#include <iostream>
#include <cstdlib>

#include "FileTypes.hpp"

enum Filters {
    Grayscale = 1,
};

namespace BitmapImages {
    bool bitmapFilters(int filter, FILE* pOriginalImage, const char* newImageName) {
        std::cout << "\nOpening " << newImageName << std::endl;
        
        // Create new image
        FILE* pNewImage = fopen(newImageName, "w");
        if (pNewImage == NULL) {
            std::cout << "Failed to create new image!" << std::endl;
            return false;
        }
        
        // BMP Header Format
        BITMAPFILEHEADER bmFileHeader;
        fread(&bmFileHeader, sizeof(BITMAPFILEHEADER), 1, pOriginalImage);
        
        BITMAPINFOHEADER bmInfoHeader;
        fread(&bmInfoHeader, sizeof(BITMAPINFOHEADER), 1, pOriginalImage);
        
        // Check Bitmap Format
        if (bmFileHeader.bfType != 0x4d42 || bmFileHeader.bfOffBits != 138 || bmInfoHeader.biSize != 124  || bmInfoHeader.biBitCount != 24 || bmInfoHeader.biCompression != 0) {
            std::cout << "The program doesn't work on this BMP file format. Check underlying file format." << std::endl;
            fclose(pNewImage);
            return false;
        }
        
        // Image set up
        int imageHeight = abs(bmInfoHeader.biHeight);
        int imageWidth = bmInfoHeader.biWidth;
        // Width must be divisible by 4
        int padding = (4 - (imageWidth * sizeof(RGBTRIPLE)) % 4) % 4;
        
        // Store RGB Pixels
        RGBTRIPLE* image = (RGBTRIPLE*)calloc(imageHeight * (imageWidth + padding), sizeof(RGBTRIPLE));
        if (image == NULL) {
            std::cout << "Failed to allocate memory for the image!" << std::endl;
            fclose(pNewImage);
            free(image);
            return false;
        }
        
        for (int row = 0; row < imageHeight; row++) {
            fread(image + row * (imageWidth + padding), sizeof(RGBTRIPLE), imageWidth, pOriginalImage);
            fseek(pOriginalImage, padding, SEEK_CUR);
        }
        
        
        switch (filter) {
            case Grayscale:
                break;
            default:
                break;
        }

        
        
        std::cout << "Closing " << newImageName << std::endl;
        free(image);
        fclose(pNewImage);
        return true;
    }
}
