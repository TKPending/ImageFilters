#include <iostream>
#include <string>
#include "BitmapFilters.hpp"

namespace ImageProcessor {

    void printImageSize(FILE* image) {
        fseek(image, 0, SEEK_END);
        long imageSize = ftell(image);
        
        std::cout << "\nImage Size: " << imageSize << std::endl;
    }

    static std::string imageFilter() {
        std::string chosenFilter;
    
        while (true) {
            std::cout << "\n Choose a filter:\n    1) Black and White\nYour Answer: ";
            std::cin >> chosenFilter;
        
            if (chosenFilter == "1") {
                return chosenFilter;
            } else {
                std::cout << "\nInvalid input. Please enter '1'.\n";
            }
        }
    }

    bool handleChosenFilter(std::string chosenFilter, FILE* pOriginalImage, const char* newImage) {
        if (chosenFilter == "1") {
            return BitmapFilters::Grayscale(pOriginalImage, newImage);
        } else {
            return false;
        }
    }

    bool bmpFileConverter(FILE* pOriginalImage, const char* newImage) {
        printImageSize(pOriginalImage);
        
        std::string chosenFilter = imageFilter();
        bool filterProcess = handleChosenFilter(chosenFilter, pOriginalImage, newImage);
        
        std::cout << filterProcess << std::endl;

        return filterProcess;
    };
}
