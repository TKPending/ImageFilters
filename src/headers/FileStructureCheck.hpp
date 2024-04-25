#ifndef FileStructureCheck_hpp
#define FileStructureCheck_hpp

#include "FileTypes.hpp"

namespace FileStructureCheck {
    void invalidFileStructureError(const char* fileType);
    bool bitmapStructure(BITMAPFILEHEADER bitmapHeader, BITMAPINFOHEADER bitmapInfo);
}

#endif /* FileStructureCheck_hpp */
