#include <stdio.h>
#include "inputChecks.hpp"
#include "errorHandling.hpp"

enum FileTypes {
    JPEG = 1,
    JPG = 2,
    PNG = 3,
    BMP = 4,
    SVG = 5,
    PDF = 6,
};

void closeImage(FILE* pFile)
{
    if (pFile != NULL) {
        fclose(pFile);
    };
}

void openImage(const char* filename)
{
    bool validFilename = InputChecks::checkFilename(filename);
    
    if (!validFilename) {
        ErrorHandling::invalidFileType();
    }
    
    FILE *pFile;
    pFile = fopen(filename, "wb");
    
    // Manipulate Images
    
    closeImage(pFile);
}
