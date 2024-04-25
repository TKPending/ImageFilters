#include <iostream>

#include "FilterPicker.hpp"
#include "ImageTypeProcess.hpp"
#include "ImageFilters.hpp"

enum ArgumentValues {
    OriginalImageIndex = 1,
    NewImageIndex = 2,
};

enum FileTypes {
    invalidFileType = 0,
    JPEG = 1,
    JPG = 2,
    PNG = 3,
    BMP = 4,
    SVG = 5,
    PDF = 6,
};


int main(int argc, const char * argv[]) {
    if (argc != 3) {
        std::cout << "Invalid arguments" << std::endl;
        std::cout << "executable -> original image -> name of new image" << std::endl;
        std::cout << "./filter selfie.bmp greyselfie.bmp" << std::endl;
        return 0;
    }
    
    // Extract file names from arguments
    const char* originalImageName = argv[OriginalImageIndex];
    const char* newImageName = argv[NewImageIndex];
    
    // Check ending of file, matches imagee format
    const char* originalImageFileEnding = ImageTypeProcess::findImageType(originalImageName);
    int fileTypeProcess = ImageTypeProcess::imageTypeRedirection(originalImageFileEnding);
    if (strcmp(originalImageFileEnding, "") == invalidFileType || fileTypeProcess == invalidFileType) {
        std::cout << "Invalid file names" << std::endl;
        std::cout << "Ensure the files match:  JPEG or JPG or PNG or BMP or SVG or PDF" << std::endl;
        return 0;
    }
    
    std::cout << "Starting Image Filter by Tony.\n" << std::endl;
    
    // Open original image
    FILE* pOriginalImage = fopen(originalImageName, "rb");
    if (pOriginalImage == NULL) {
        std::cout << "Failed to open original image." << std::endl;
        std::cout << "Check file name. Does the original image exist? " << std::endl;
        std::cout << "\nClosing Program" << std::endl;
        fclose(pOriginalImage);
        return 0;
    }
    
    std::cout << "Opened " << originalImageName << std::endl;
    
    // User chooses filter
    int filter = pickImageFilter();
    
    // Add filter & Check filter addded
    bool filterSuccess = false;
    switch (fileTypeProcess) {
        case BMP:
            filterSuccess = BitmapImages::bitmapFilters(filter, pOriginalImage, newImageName);
            break;
        default:
            std::cout << "Program doesn't work with this file format. Also, check for hidden metadata." << std::endl;
            break;
    }
    
    // Let user know success
    if (filterSuccess) {
        std::cout << "\nImage has been successfully changed!\n" << std::endl;
    } else {
        std::cout << "\nAdding filter was unsuccesful!/n" << std::endl;
    }
    
    std::cout << "Closing " << originalImageName << std::endl;
    std::cout << "Closing Program\n" << std::endl;
    fclose(pOriginalImage);
    return 0;
}
