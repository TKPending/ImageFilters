#include <iostream>
#include <string>

namespace ImageProcessor {

    void printImageSize(FILE* image) {
        fseek(image, 0, SEEK_END);
        long imageSize = ftell(image);
        
        std::cout << "/nImage Size: " << imageSize << std::endl;
    }

    static std::string imageFilter() {
        std::string chosenFilter;
    
        while (true) {
            std::cout << "/nChoose a filter:\n    1) Black and White\n    2) Grayscale\nYour Answer: ";
            std::cin >> chosenFilter;
        
            if (chosenFilter == "1" || chosenFilter == "2") {
                return chosenFilter;
            } else {
                std::cout << "/nInvalid input. Please enter '1' or '2'.\n";
            }
        }
    }

    bool handleChosenFilter(std::string chosenFilter) {
        if (chosenFilter == "1") {
            return true;
        } else if (chosenFilter == "2") {
            return true;
        } else {
            return false;
        }
    }

    bool bmpFileConverter(FILE* pOriginalImage, const char* newImage) {
        printImageSize(pOriginalImage);
        
        std::string chosenFilter = imageFilter();
        bool filterProcess = handleChosenFilter(chosenFilter);

        return filterProcess;
    };
}
