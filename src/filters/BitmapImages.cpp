#include <iostream>
#include <cstdlib>

#include "FileTypes.hpp"

enum Filters {
    Grayscale = 1,
};

namespace BitmapImages {
    void grayscaleFilter(int imageHeight, int imageWidth, RGBTRIPLE** image);

    bool checkBitmapFormat(BITMAPFILEHEADER bmFileHeader, BITMAPINFOHEADER bmInfoHeader) {
        if (bmFileHeader.bfType != 0x4d42 || bmFileHeader.bfOffBits != 138 || bmInfoHeader.biSize != 124  || bmInfoHeader.biBitCount != 24 || bmInfoHeader.biCompression != 0) {
            std::cout << "The program doesn't work on this BMP file format. Check underlying file format." << std::endl;
            return false;
        }
        
        return true;
    }

    RGBTRIPLE** createNewImage(int imageHeight, int imageWidth, int padding) {
        RGBTRIPLE** image = new RGBTRIPLE*[imageHeight];
        if (image == NULL) {
            std::cout << "Failed to allocate memory for the image!" << std::endl;
            return NULL;
        }
        
        for (int i = 0; i < imageHeight; i++) {
            image[i] = new RGBTRIPLE[imageWidth];
        }
        
        return image;
    }

    void readImageData(int imageHeight, int imageWidth, int padding, FILE* pOriginalImage, RGBTRIPLE** image) {
        for (int row = 0; row < imageHeight; row++) {
            fread(image[row], sizeof(RGBTRIPLE), imageWidth, pOriginalImage);
            fseek(pOriginalImage, padding, SEEK_CUR);
        }
    }

    void updatePixels(int imageHeight, int imageWidth, int padding, FILE* pNewImage, RGBTRIPLE** image, BITMAPFILEHEADER bmFileHeader, BITMAPINFOHEADER bmInfoHeader) {
        std::cout << "\nCreating new image\n" << std::endl;
        fwrite(&bmFileHeader, sizeof(BITMAPFILEHEADER), 1, pNewImage);
        fwrite(&bmInfoHeader, sizeof(BITMAPINFOHEADER), 1, pNewImage);
        
        for (int row = 0; row < imageHeight; row++) {
            fwrite(image[row], sizeof(RGBTRIPLE), imageWidth, pNewImage);
            for (int k = 0; k < padding; k++) {
                fputc(0x00, pNewImage);
            }
        }
        
        std::cout << "New Image Created\n" << std::endl;
    }

    bool bitmapFilters(int filter, FILE* pOriginalImage, const char* newImageName) {
        BITMAPFILEHEADER bmFileHeader;
        fread(&bmFileHeader, sizeof(BITMAPFILEHEADER), 1, pOriginalImage);
        
        BITMAPINFOHEADER bmInfoHeader;
        fread(&bmInfoHeader, sizeof(BITMAPINFOHEADER), 1, pOriginalImage);
        
        bool bitmapCheck = checkBitmapFormat(bmFileHeader, bmInfoHeader);
        if (!bitmapCheck) {
            return false;
        }
        
        int imageHeight = abs(bmInfoHeader.biHeight);
        int imageWidth = bmInfoHeader.biWidth;
        int padding = (4 - (imageWidth * sizeof(RGBTRIPLE)) % 4) % 4;

        // Store RGB Pixels as a 2D array
        RGBTRIPLE** image = createNewImage(imageHeight, imageWidth, padding);
        if (!image) {
            return false;
        }
        
        readImageData(imageHeight, imageWidth, padding, pOriginalImage, image);
        
        std::cout << "\nOpening " << newImageName << std::endl;
        
        FILE* pNewImage = fopen(newImageName, "w");
        if (pNewImage == NULL) {
            std::cout << "Failed to open new image!" << std::endl;
            return false;
        }

        switch (filter) {
            case Grayscale:
                grayscaleFilter(imageHeight, imageWidth, image);
                break;
            default:
                break;
        }
        
        updatePixels(imageHeight, imageWidth, padding, pNewImage, image, bmFileHeader, bmInfoHeader);
        
        std::cout << "Closing " << newImageName << std::endl;
        free(image);
        fclose(pNewImage);
        return true;
    }

    void grayscaleFilter(int imageHeight, int imageWidth, RGBTRIPLE** image) {
        float grayTone;
        
        std::cout << "\nStarting Grayscale Process..." << std::endl;
        
        for (int row = 0; row < imageHeight; row++) {
            for (int col = 0; col < imageWidth; col++) {
                grayTone = round((image[row][col].rgbtRed + image[row][col].rgbtGreen + image[row][col].rgbtBlue) / 3.0);
                
                image[row][col].rgbtRed = grayTone;
                image[row][col].rgbtGreen = grayTone;
                image[row][col].rgbtBlue = grayTone;
            }
        }
        
        std::cout << "Finished Grayscale Process...\n" << std::endl;
    }
}
