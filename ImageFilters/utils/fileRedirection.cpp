#include <string>

std::string fileType(const char* filename)
{
    return;
}

int redirectFileType(std::string fileType)
{
    switch (fileType) {
        case "jpeg":
            return 1;
        case "jpg":
            return 2;
        case "png":
            return 3;
        case "bmp":
            return 4;
        case "svg":
            return 5;
        case "pdf":
            return 6;
        default:
            return 0;
    };
}
