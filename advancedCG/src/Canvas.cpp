/*
    Canvas.cpp
    2016 Feb 25
    Brendon Walter

    Methods for the Canvas class, which can be found in Canvas.h in src/
*/

#include <Canvas.h>

Canvas::Canvas() { setSize(800, 600); setGamma(2.2); }
Canvas::Canvas(int w, int h) { setSize(w, h); setGamma(2.2); }

int Canvas::getWidth() { return width; }
int Canvas::getHeight() { return height; }
float Canvas::getGamma() { return gamma; }

bool Canvas::setSize(int w, int h) {
    if (0 < w && 0 < h) {
        width = w; height = h;

        // create 2D array of pixels
        pixels = new Color*[width];
        for (int i=0; i<width; i++)
            pixels[i] = new Color[height];

        return true;
    }
    return false;
}

bool Canvas::setGamma(float g) { gamma = g; return true;}

void Canvas::setPixel(int x, int y, Color color) {
    pixels[x][y] = color;
}

int Canvas::convertToUInt8(float color, float gamma) {
    return 255 * pow(color, 1/gamma);
}

void Canvas::writeToFile(char* fileName) {
    // create a new BMP image
    BMP image;
    image.SetSize(width, height);
    image.SetBitDepth(32);

    // set the color of each pixel in the image
    for (int x=0; x<width; x++) {
        for (int y=0; y<height; y++) {
            image(x, y)->Red = convertToUInt8(pixels[x][y].getr(), gamma);
            image(x, y)->Green = convertToUInt8(pixels[x][y].getg(), gamma);
            image(x, y)->Blue = convertToUInt8(pixels[x][y].getb(), gamma);
            image(x, y)->Alpha = convertToUInt8(pixels[x][y].geta(), gamma);
        }
    }
    image.WriteToFile(fileName);
}
