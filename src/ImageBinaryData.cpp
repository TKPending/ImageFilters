#include "MyLibrary.hpp"
#include "InputChecks.hpp"
#include "ErrorHandling.hpp"
#include "FileRedirection.hpp"
#include "ImageProcessor.hpp"

enum FileTypes {
    JPEG = 1,
    JPG = 2,
    PNG = 3,
    BMP = 4,
    SVG = 5,
    PDF = 6,
};

void closeImage(FILE* pFile) {
    if (pFile != NULL) {
        fclose(pFile);
        std::cout << "\nFile Closed\n\n";
    }
}

bool fileTypeProcessing(const char* filename, FILE* pFile) {
    const char* imageType = fileType(filename);
    int redirectNumb = redirectFileType(imageType);
    
    switch (redirectNumb) {
        case JPEG:
            return false;
        case JPG:
            return false;
        case PNG:
            return false;
        case BMP:
            return ImageProcessor::bmpFileConverter(pFile);
        case SVG:
            return false;
        case PDF:
            return false;
        default:
            ErrorHandling::invalidFileType();
            return false;
    }
}

void openImage(const char* filename) {
    bool validFilename = InputChecks::checkFilename(filename);
    
    if (!validFilename) {
        ErrorHandling::invalidFileType();
        return;
    }
    
    FILE *pFile;
    pFile = fopen(filename, "rb");
    
    if (pFile == NULL) {
        ErrorHandling::openingFileFailed(filename);
    } else {
        std::cout << "\nFile Opened!\n";
        bool processStatus = fileTypeProcessing(filename, pFile);
        
        if (processStatus) {
            printf("\n\nImage has been updated!\n\n");
        } else {
            printf("\n\nFailed to update image!\n\n");
        }
    }
    
    closeImage(pFile);
}
