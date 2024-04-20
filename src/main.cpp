#include "MyLibrary.hpp"
#include "ImageBinaryData.hpp"

int main(int argc, const char * argv[]) {
    if (argc != 2) {
        std::cout << "Need to input the name of the file when building.\n";
        std::cout << "Usage: " << argv[0] << " filename.png  (as an example)\n";
        return 0;
    }
    
    printf("Starting Program...\n\n");

    openImage(argv[1]);

    printf("Closing Program...\n\n");
    
    return 0;
}
