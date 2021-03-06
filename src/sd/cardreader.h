/**
 * MK4duo Firmware for 3D Printer, Laser and CNC
 *
 * Based on Marlin, Sprinter and grbl
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 * Copyright (C) 2013 Alberto Cotronei @MagoKimbra
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef CARDREADER_H
#define CARDREADER_H

#if HAS_SDSUPPORT

  #if ENABLED(SD_SETTINGS)
    /**
     * SD Settings
     */
    enum cfgSD_ENUM {   // This need to be in the same order as cfgSD_KEY
      SD_CFG_CPR,
      SD_CFG_FIL,
      SD_CFG_NPR,
    #if HAS_POWER_CONSUMPTION_SENSOR
      SD_CFG_PWR,
    #endif
      SD_CFG_TME,
      SD_CFG_TPR,
      SD_CFG_END // Leave this always as the last
    };
  #endif

  enum LsAction { LS_Count, LS_GetFilename };

  #include "SDFat.h"

  struct PrintFileExtruderInfo {
	  char PlasticMaterialName[MAT_NAME_SIZE];
	  float PlasticConsumption;
	  char FiberMaterialName[MAT_NAME_SIZE];
	  float FiberConsumption;
  };

  struct PrintFileInfo {
	  uint32_t PrintDuration;
	  PrintFileExtruderInfo ExtruderInfo[HOTENDS];
  };

  class CardReader {

    public: /** Constructor */

      CardReader();

    public: /** Public Parameters */

      SdFat fat;
      SdFile gcode_file;
      SdBaseFile  root,
                 *curDir,
                  workDir,
                  workDirParents[SD_MAX_FOLDER_DEPTH];

      bool  saving,
            sdprinting,
            cardOK,
            filenameIsDir;

      uint32_t  fileSize,
                sdpos;

      float objectHeight,
            firstlayerHeight,
            layerHeight,
            filamentNeeded;

      char  fileName[LONG_FILENAME_LENGTH],
            tempLongFilename[LONG_FILENAME_LENGTH + 1],
            generatedBy[GENBY_SIZE];

      PrintFileInfo fileInfo;

      uint16_t fileModifiedDate;
      uint16_t fileModifiedTime;

    private: /** Private Parameters */

      Sd2Card card;

      #if HAS_SD_RESTART
        SdFile restart_file;
      #endif

      #if HAS_EEPROM_SD
        SdFile eeprom_file;
      #endif

      #if ENABLED(SD_SETTINGS)
        SdFile settings_file;
      #endif

      uint16_t  workDirDepth;
      millis_l  next_autostart_ms;
      uint16_t  nrFiles;             // counter for the files in the current directory and recycled as position counter for getting the nrFiles'th name in the directory.
      LsAction  lsAction;            // stored for recursion.
      bool  autostart_stilltocheck;  // the sd start is delayed, because otherwise the serial cannot answer fast enought to make contact with the hostsoftware.

      // Sort files and folders alphabetically.
      #if ENABLED(SDCARD_SORT_ALPHA)
        uint16_t sort_count;        // Count of sorted items in the current directory
        #if ENABLED(SDSORT_GCODE)
          bool sort_alpha;          // Flag to enable / disable the feature
          int sort_folders;         // Flag to enable / disable folder sorting
          //bool sort_reverse;      // Flag to enable / disable reverse sorting
        #endif

        // By default the sort index is static
        #if ENABLED(SDSORT_DYNAMIC_RAM)
          uint8_t *sort_order;
        #else
          uint8_t sort_order[SDSORT_LIMIT];
        #endif

        #if ENABLED(SDSORT_USES_RAM) && ENABLED(SDSORT_CACHE_NAMES) && DISABLED(SDSORT_DYNAMIC_RAM)
          #define SORTED_LONGNAME_MAXLEN ((SDSORT_CACHE_VFATS) * (FILENAME_LENGTH) + 1)
        #else
          #define SORTED_LONGNAME_MAXLEN LONG_FILENAME_LENGTH
        #endif

        // Cache filenames to speed up SD menus.
        #if ENABLED(SDSORT_USES_RAM)

          // If using dynamic ram for names, allocate on the heap.
          #if ENABLED(SDSORT_CACHE_NAMES)
            #if ENABLED(SDSORT_DYNAMIC_RAM)
              char **sortshort, **sortnames;
            #else
              char sortnames[SDSORT_LIMIT][SORTED_LONGNAME_MAXLEN];
            #endif
          #elif DISABLED(SDSORT_USES_STACK)
            char sortnames[SDSORT_LIMIT][SORTED_LONGNAME_MAXLEN];
          #endif

          // Folder sorting uses an isDir array when caching items.
          #if HAS_FOLDER_SORTING
            #if ENABLED(SDSORT_DYNAMIC_RAM)
              uint8_t *isDir;
            #elif ENABLED(SDSORT_CACHE_NAMES) || DISABLED(SDSORT_USES_STACK)
              uint8_t isDir[(SDSORT_LIMIT + 7)>>3];
            #endif
          #endif

        #endif // SDSORT_USES_RAM

      #endif // SDCARD_SORT_ALPHA



    public: /** Public Function */

      void mount();
      void unmount();
      void ls();
      void getfilename(uint16_t nr, const char* const match=NULL);
      void getAbsFilename(char* name);
      void startFileprint();
      void openAndPrintFile(const char* name);
      void stopSDPrint();
      void write_command(char* buf);
      void printStatus();
      void startWrite(char* filename, const bool silent=false);
      void deleteFile(char* filename);
      void finishWrite();
      void makeDirectory(char* filename);
      void closeFile();
      void printingHasFinished();
      void chdir(const char* relpath);
      void ResetDefault();
      void PrintSettings();
      void checkautostart(bool x);
      void setroot();
      void setlast();

      static void printEscapeChars(const char* s);

      bool selectFile(const char* filename);

      int8_t updir();
      uint16_t getnrfilenames();
      uint16_t get_num_Files();

      #if HAS_SD_RESTART
        void open_restart_file(const bool read);
        void close_restart_file();
        void delete_restart_file();
        bool exist_restart_file();
        int16_t save_restart_data();
        int16_t read_restart_data();
      #endif

      #if HAS_EEPROM_SD
        bool open_eeprom_sd(const uint8_t oflag);
        void close_eeprom_sd();
        bool write_eeprom_data(const uint8_t value);
        uint8_t read_eeprom_data();
      #endif

      #if ENABLED(SD_SETTINGS)
        #define CFG_SD_MAX_KEY_LEN    3+1         // increase this if you add key name longer than the actual value.
        #define CFG_SD_MAX_VALUE_LEN  10+1        // this should be enough for int, long and float: if you need to retrieve strings increase this carefully
        //(11 = strlen("4294967295")+1) (4294967295 = (2^32)-1) (32 = the num of bits of the bigger basic data structure used)
        //If you need to save string increase this to strlen("YOUR LONGER STRING")+1
        void StoreSettings();
        void RetrieveSettings(bool addValue = false);
        void parseKeyLine(char* key, char* value, int &len_k, int &len_v);
        void unparseKeyLine(const char* key, char* value);
        int  KeyIndex(char* key);
      #else
        inline void RetrieveSettings() { ResetDefault(); }
      #endif

      #if ENABLED(SDCARD_SORT_ALPHA)
        void presort();
        void getfilename_sorted(const uint16_t nr);
        #if ENABLED(SDSORT_GCODE)
          FORCE_INLINE void setSortOn(bool b) { sort_alpha = b; presort(); }
          FORCE_INLINE void setSortFolders(int i) { sort_folders = i; presort(); }
          //FORCE_INLINE void setSortReverse(bool b) { sort_reverse = b; }
        #endif
      #endif

      FORCE_INLINE void pauseSDPrint() { sdprinting = false; }
      FORCE_INLINE void setIndex(uint32_t newpos) { sdpos = newpos; gcode_file.seekSet(sdpos); }
      FORCE_INLINE uint32_t getIndex() { return sdpos; }
      FORCE_INLINE bool isFileOpen() { return gcode_file.isOpen(); }
      FORCE_INLINE bool eof() { return sdpos >= fileSize; }
      FORCE_INLINE int16_t get() { sdpos = gcode_file.curPosition(); return (int16_t)gcode_file.read(); }
      FORCE_INLINE uint8_t percentDone() { return (isFileOpen() && fileSize) ? sdpos / ((fileSize + 99) / 100) : 0; }
      FORCE_INLINE char* getWorkDirName() { workDir.getFilename(fileName); return fileName; }

      Sd2Card& getSd2Card() { return card; }

    private: /** Private Function */

      void lsDive(SdBaseFile parent, const char* const match = NULL);
      void parsejson(SdBaseFile &parser_file);
      void readFileInfo(SdBaseFile &file);
      void clearFileInfo();
      bool findFileInfo(const char *buf, uint16_t buf_length);
      bool findGeneratedBy(char* buf, char* genBy);
      bool findFirstLayerHeight(char* buf, float &firstlayerHeight);
      bool findLayerHeight(char* buf, float &layerHeight);
      bool findFilamentNeed(char* buf, float &filament);
      bool findTotalHeight(char* buf, float &objectHeight);

      #if ENABLED(SDCARD_SORT_ALPHA)
        void flush_presort();
      #endif

  };

  extern CardReader card;

  #define IS_SD_PRINTING (card.sdprinting)
  #define IS_SD_FILE_OPEN (card.isFileOpen())

  #if PIN_EXISTS(SD_DETECT)
    #if ENABLED(SD_DETECT_INVERTED)
      #define IS_SD_INSERTED (READ(SD_DETECT_PIN) != 0)
    #else
      #define IS_SD_INSERTED (READ(SD_DETECT_PIN) == 0)
    #endif
  #else
    //No card detect line? Assume the card is inserted.
    #define IS_SD_INSERTED true
  #endif

#else

  #define IS_SD_PRINTING (false)
  #define IS_SD_FILE_OPEN (false)

#endif //SDSUPPORT

#endif //__CARDREADER_H
