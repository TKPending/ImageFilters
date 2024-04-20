#include "MyLibrary.hpp"

namespace InputChecks {
    bool checkFilename(const char* filename)
    {
        std::vector<std::string> imageFileTypes;
        
        imageFileTypes.push_back(".jpeg");
        imageFileTypes.push_back(".jpg");
        imageFileTypes.push_back(".png");
        imageFileTypes.push_back(".bmp");
        imageFileTypes.push_back(".svg");
        imageFileTypes.push_back(".pdf");


        for (std::vector<std::string>::const_iterator it = imageFileTypes.begin(); it != imageFileTypes.end(); ++it) {
            if (strstr(filename, (*it).c_str()) != nullptr) {
                return true;
            }
        }


        return false;
    }
}
