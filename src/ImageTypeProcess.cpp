#include <string>

namespace ImageTypeProcess {
    const char* findImageType(const char* imageFilename) {
        const char* fileSeperator = std::strrchr(imageFilename, '.');

        if (fileSeperator != nullptr
            && fileSeperator != imageFilename + std::strlen(imageFilename) - 1) {
            static std::string fileTypeStr(fileSeperator + 1);
        
            return fileTypeStr.c_str();
        }

        return "";
    }


    int imageTypeRedirection(const char* fileType) {
        if (strcmp(fileType, "jpeg") == 0) {
            return 1;
        } else if (strcmp(fileType, "jpg") == 0) {
            return 2;
        } else if (strcmp(fileType, "png") == 0) {
            return 3;
        } else if (strcmp(fileType, "bmp") == 0) {
            return 4;
        } else if (strcmp(fileType, "svg") == 0) {
            return 5;
        } else if (strcmp(fileType, "pdf") == 0) {
            return 6;
        } else {
            return 0;
        }
    }
}
