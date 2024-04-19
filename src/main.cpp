#include <iostream>
#include "imageBinaryData.hpp"

int main(int argc, const char * argv[]) {
    if (argc == 1 || argc > 2) {
        std::cout << "Need to input the name of the file when building.\n";
        std::cout << "Usage: " << argv[0] << " filename.png  (as an example)\n";
        return 0;
    }

    std::cout << "Starting Program...\n";

    openImage(argv[1]);

    std::cout << "Closing Programm...\n";
    
    return 0;
}
