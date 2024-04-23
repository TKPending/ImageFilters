#ifndef ERROR_HANDLING_HPP
#define ERROR_HANDLING_HPP

namespace ErrorHandling {
    void invalidFileType();
    void openingFileFailed(const char* filename);
    void creatingFileFailed(const char* filename);
}


#endif
