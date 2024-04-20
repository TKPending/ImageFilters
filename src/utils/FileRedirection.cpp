#include "MyLibrary.hpp"
#include <cstring>

const char* fileType(const char* filename) {
   const char* lastDot = std::strrchr(filename, '.');

    if (lastDot != nullptr && lastDot != filename + std::strlen(filename) - 1) {
       static std::string fileTypeStr(lastDot + 1);
       return fileTypeStr.c_str();
    }

    return "";
}


int redirectFileType(const char* fileType) {
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
