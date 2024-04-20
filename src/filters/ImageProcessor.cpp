#include <iostream>

namespace ImageProcessor {
    bool bmpFileConverter(FILE* image) {
        fseek(image, 0, SEEK_SET);
        printf("\n\nBeginning %ld", ftell(image));
        
        fseek(image, 0, SEEK_END);
        printf("\n\nEnding %ld", ftell(image));
        
        return true;
    };
}
