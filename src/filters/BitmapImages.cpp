#include <iostream>
#include <cstdlib>

#include "FileTypes.hpp"

enum Filters {
    Grayscale = 1,
};

namespace BitmapImages {
    void grayscaleFilter(int imageHeight, int imageWidth, RGBTRIPLE** image);

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

        // Store RGB Pixels as a 2D array
        RGBTRIPLE** image = new RGBTRIPLE*[imageHeight];
        if (image == NULL) {
            std::cout << "Failed to allocate memory for the image!" << std::endl;
            fclose(pNewImage);
            return false;
        }
        for (int i = 0; i < imageHeight; i++) {
            image[i] = new RGBTRIPLE[imageWidth];
        }
        
        // Width must be divisible by 4
        int padding = (4 - (imageWidth * sizeof(RGBTRIPLE)) % 4) % 4;

        // Read image data
        for (int row = 0; row < imageHeight; row++) {
            fread(image[row], sizeof(RGBTRIPLE), imageWidth, pOriginalImage);
            fseek(pOriginalImage, padding, SEEK_CUR);
        }

        switch (filter) {
            case Grayscale:
                grayscaleFilter(imageHeight, imageWidth, image);
                break;
            default:
                break;
        }

        // TODO: Write to new file
        std::cout << "\nCreating new image\n" << std::endl;
        fwrite(&bmFileHeader, sizeof(BITMAPFILEHEADER), 1, pNewImage);
        fwrite(&bmInfoHeader, sizeof(BITMAPINFOHEADER), 1, pNewImage);
        
        // Add updated pixel data
        for (int row = 0; row < imageHeight; row++) {
            fwrite(image[row], sizeof(RGBTRIPLE), imageWidth, pNewImage);
            for (int k = 0; k < padding; k++) {
                fputc(0x00, pNewImage);
            }
        }
        
        std::cout << "New Image Created\n" << std::endl;
        
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
                
                std::cout << grayTone << std::endl;
                
                image[row][col].rgbtRed = grayTone;
                image[row][col].rgbtGreen = grayTone;
                image[row][col].rgbtBlue = grayTone;
            }
        }
        
        std::cout << "Finished Grayscale Process...\n" << std::endl;
    }
}
