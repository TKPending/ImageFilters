#include <iostream>

namespace ImageProcessor {
    bool bmpFileConverter(FILE* pOriginalImage, const char* newImage) {
        fseek(pOriginalImage, 0, SEEK_END);
        printf("\n\Ending %ld", ftell(pOriginalImage));
        
        fseek(pOriginalImage, 0, SEEK_SET);
        printf("\n\nBeginning %ld", ftell(pOriginalImage));
        
        return true;
    };
}
