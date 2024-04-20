#include "MyLibrary.hpp"

namespace ErrorHandling {
    
    void closingProgramText() {
        std::cout << "Closing Program...\n\n";
    }
    
    void invalidFileType() {
        std::cout << "Invalid file type, we only support:\nJPEG - JPG - PNG - BMP - SVG - PDF\n\n";
        closingProgramText();
        std::exit(EXIT_SUCCESS);
    }

    void openingFileFailed(const char* filename) {
        std::cerr << "Error: Unable to open file. Check spelling, file location or code. (" << filename << ")\n\n";
        closingProgramText();
        std::exit(EXIT_SUCCESS);
    }
}
