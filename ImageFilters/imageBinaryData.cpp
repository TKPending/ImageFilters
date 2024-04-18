#include <stdio.h>
#include <string>
#include "inputChecks.hpp"
#include "errorHandling.hpp"
#include "fileRedirection.hpp"

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

void fileTypeProcessing(const char* filename)
{
    std::string imageType = fileType(filename);
    int redirectNumb = redirectFileType(imageType);
    
    switch (redirectNumb) {
        case JPEG:
            return;
        case JPG:
            return;
        case PNG:
            return;
        case BMP:
            return;
        case SVG:
            return;
        case PDF:
            return;
        default:
            ErrorHandling::invalidFileType();
            return;
    }
}

void openImage(const char* filename)
{
    bool validFilename = InputChecks::checkFilename(filename);
    
    if (!validFilename) {
        ErrorHandling::invalidFileType();
    }
    
    FILE *pFile;
    pFile = fopen(filename, "wb");
    
    fileTypeProcessing(filename);
    
    closeImage(pFile);
}
