#include <iostream>

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
    static bool bmpCheck(FILE* pOriginalImage) {
        fseek(pOriginalImage, 0, SEEK_SET);
        
        char signature[2];
        size_t signatureBytes = fread(signature, sizeof(char), 2, pOriginalImage);
        
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

    bool Grayscale(FILE* pOriginalImage, const char* newImage) {
        if (!bmpCheck(pOriginalImage)) {
            return false;
        }
      
        int bmpWidth = bmpImageSize(pOriginalImage, widthByteBuffer);
        int bmpHeight = bmpImageSize(pOriginalImage, heightByteBuffer);
        
        fseek(pOriginalImage, metaDataByteBuffer, SEEK_SET);
        
        std::cout << "\nCreating new file " << newImage << "\n" << std::endl;
        
        FILE* pNewImage;
        pNewImage = fopen(newImage, "wb");
            
        // TODO:
        //  Copy header information from image A to B
        //  Grayscale the pixels
        //  Return true - It worked & False - Didn't work
        
        fwrite(pOriginalImage, sizeof(char), metaDataByteBuffer, pNewImage);
        
//        for (int ROWS = 0; ROWS < bmpWidth; ROWS++) {
//            for (int HEIGHT = 0; HEIGHT < bmpHeight; HEIGHT++) {
//                
//            }
//        }
        
        fclose(pNewImage);
        std::cout << "\nNew Image Closed\n" << std::endl;
        
        return true;
    };
}
