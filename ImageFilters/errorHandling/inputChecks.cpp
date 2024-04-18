#include <vector>
#include <string>

namespace InputChecks {
    constexpr int fileTypeAmount = 6;

    bool checkFilename(const char* filename)
    {
        std::vector<std::string> imageFileTypes = {".jpeg", ".jpg" , ".png", ".bmp", ".svg", ".pdf"};

        for (const std::string& fileType : imageFileTypes) {
            if (strstr(filename, fileType.c_str()) != nullptr) {
                return true;
            }
        }

        return false;
    }
}
