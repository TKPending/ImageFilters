#include "MyLibrary.hpp"
#include "ImageBinaryData.hpp"

int main(int argc, const char * argv[]) {
    if (argc != 3) {
        std::cout << "Invalid Arguments!\nArgument Naming" << std::endl;
        std::cout << "exe -> name of original image (Including file type) -> name of new file (Excluding file type)" << std::endl;
        std::cout << "E.G: ./main selfie.png greySelfie" << std::endl;
        return 0;
    }
    
    printf("Starting Program...\n\n");
    
    const char* originalFile = argv[1];
    const char* newFile = argv[2];
    
    openImage(originalFile, newFile);

    printf("Closing Program...\n\n");
    
    return 0;
}
