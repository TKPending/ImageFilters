#include <iostream>
#include "ErrorHandling.hpp"

enum BmpByteBuffers {
    byteBuffer = 4,
    headerByteBuffer = 14,
    widthByteBuffer = 4,
    heightByteBuffer = 8,
    metaDataByteBuffer = 54,
};

enum BlackWhite {
    black = 0,
    white = 255,
};

namespace BitmapFilters {
//    TODO: Change original image to image
    static bool bmpCheck(FILE* pImage) {
        fseek(pImage, 0, SEEK_SET);
        
        char signature[2];
        size_t signatureBytes = fread(signature, sizeof(char), 2, pImage);
        
        if (signatureBytes != 2) {
            std::cout << "\nProblem: Bytes weren't read.\n" << std::endl;
            return false;
        }
        
        if (signature[0] == 'B' && signature[1] == 'M') {
            std::cout << "\nBMP File Detected!\n" << std::endl;
            return true;
        } else {
            std::cout << "\nFile in question, isn't a BMP File\n" << std::endl;
            return false;
        }
    };

    static int bmpImageSize(FILE* pOriginalImage, int buffer) {
        fseek(pOriginalImage, headerByteBuffer + buffer, SEEK_SET);
        
        int size;
        fread(&size, sizeof(int), 1, pOriginalImage);
        
        return size;
    }

    static FILE* createNewImage(const char* newImageName) {
        FILE* pNewImage;
        pNewImage = fopen(newImageName, "wb");
        
        return pNewImage;
    }

    static bool copyHeaderInfo(FILE* pOriginalImage, FILE* pNewImage) {
        char headerBuffer[metaDataByteBuffer];
        fseek(pOriginalImage, 0, SEEK_SET);
        
        fread(headerBuffer, sizeof(char), metaDataByteBuffer, pOriginalImage);
        fwrite(headerBuffer, sizeof(char), metaDataByteBuffer, pNewImage);
        
        std::cout << "\nChecking new image was copied...." << std::endl;
        bool checkHeaderCopied = bmpCheck(pNewImage);
        
        if (!checkHeaderCopied) {
            return false;
        }
        
        return true;
    }

    bool Grayscale(FILE* pOriginalImage, const char* newImage) {
        if (!bmpCheck(pOriginalImage)) {
            return false;
        }
      
        int bmpWidth = bmpImageSize(pOriginalImage, widthByteBuffer);
        int bmpHeight = bmpImageSize(pOriginalImage, heightByteBuffer);
        
        std::cout << "\nCreating new file " << newImage << "\n" << std::endl;
        
        FILE* pNewImage = createNewImage(newImage);
        if (pNewImage == NULL) {
            std::cout << "\nClosing " << newImage << "\n" << std::endl;
            fclose(pNewImage);
            ErrorHandling::creatingFileFailed(newImage);
        }
        
        bool headerCopied = copyHeaderInfo(pOriginalImage, pNewImage);
        if (!headerCopied) {
            std::cout << "\nClosing " << newImage << "\n" << std::endl;
            fclose(pNewImage);
            return false;
        }
        
        fclose(pNewImage);
        std::cout << "\nNew Image Closed\n" << std::endl;
        
        return true;
    };
}
