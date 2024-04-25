#include <iostream>

#include "FileTypes.hpp"

namespace FileStructureCheck {
    void invalidFileStructureError(const char* fileType) {
        std::cerr << "Problem: The file structure doesn't match our requirements. (" << fileType << ")" << std::endl;
    }

    bool bitmapStructure(BITMAPFILEHEADER bitmapHeader, BITMAPINFOHEADER bitmapInfo) {
        if (bitmapHeader.bfType != 0x4d42 || bitmapHeader.bfOffBits != 54
            || bitmapInfo.biSize != 40 || bitmapInfo.biBitCount != 24 || bitmapInfo.biCompression != 0) {
                invalidFileStructureError("BMP");
                return false;
            }
    
        return true;
    }
}

