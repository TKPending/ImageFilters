#include <iostream>

int main(int argc, const char * argv[]) {
    
    if (argc == 1) {
        std::cout << "Need to input the name of the file when building.\n";
        std::cout << "Usage: " << argv[0] << " filename.png  (as an example)\n";
        return 0;
    }
    
    return 0;
}
