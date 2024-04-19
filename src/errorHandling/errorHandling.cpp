#include <iostream>
#include <cstdlib>

namespace ErrorHandling {
    void inavlidFileType()
    {
        std::cout << "Invalid file type, we only support:\nJPEG - JPG - PNG - BMP - SVG - PDF";
        std::exit(EXIT_SUCCESS);
    }

    void openingFileFailed(const char* filename)
    {
        std::cerr << "Error: Unable to open file. Check spelling, file location or code. (" << filename << ")";
        std::exit(EXIT_SUCCESS);
    }
}
