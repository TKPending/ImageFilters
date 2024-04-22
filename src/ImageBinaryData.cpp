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

bool fileTypeProcessing(int redirectionId, FILE* pOriginalImage, const char* newImage) {
    switch (redirectionId) {
        case JPEG:
            return false;
        case JPG:
            return false;
        case PNG:
            return false;
        case BMP:
            return ImageProcessor::bmpFileConverter(pOriginalImage, newImage);
        case SVG:
            return false;
        case PDF:
            return false;
        default:
            ErrorHandling::invalidFileType();
            return false;
    }
}

void openImage(const char* originalImage, const char* newImage) {
    bool validFilename = InputChecks::checkFilename(originalImage);
    
    if (!validFilename) {
        ErrorHandling::invalidFileType();
        return;
    }
    
    FILE *pOriginalImage;
    pOriginalImage = fopen(originalImage, "rb");
    
    if (pOriginalImage == NULL) {
        ErrorHandling::openingFileFailed(originalImage);
    } else {
        std::cout << "\nFile Opened!\n";
        
        const char* imageType = fileType(originalImage);
        if (strcmp(imageType, "") != 0) {
            int redirectionId = redirectFileType(imageType);
            
            bool processStatus = fileTypeProcessing(redirectionId, pOriginalImage, newImage);
            
            if (processStatus) {
                printf("\n\nImage has been updated!\n\n");
            } else {
                printf("\n\nFailed to update image!\n\n");
            }
        }
    }
    
    closeImage(pOriginalImage);
}
