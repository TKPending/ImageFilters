#include <iostream>
#include <cstdlib>

namespace ErrorHandling {
    void inavlidFileType()
    {
        std::cout << "Invalid file type, we only support:\nJPEG - JPG - PNG - BMP - SVG - PDF";
        std::exit(EXIT_SUCCESS);
    }
}
