#include <string>

std::string fileType(const char* filename)
{
    const char* lastDot = std::strrchr(filename, '.');

    if (lastDot != nullptr && lastDot != filename + std::strlen(filename) - 1) {
        return std::string(lastDot + 1);
    } else {
        return "";
    }
}

int redirectFileType(std::string& fileType)
{
    if (fileType == "jpeg") {
        return 1;
    } else if (fileType == "jpg") {
        return 2;
    } else if (fileType == "png") {
        return 3;
    } else if (fileType == "bmp") {
        return 4;
    } else if (fileType == "svg") {
        return 5;
    } else if (fileType == "pdf") {
        return 6;
    } else {
        return 0;
    }
}
