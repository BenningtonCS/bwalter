/*
    Canvas.cpp
    2016 Feb 25
    Brendon Walter

    Methods for the Canvas class, which can be found in Canvas.h in src/
*/

#include <Canvas.h>

Canvas::Canvas() { setSize(800, 600); }
Canvas::Canvas(int w, int h) { setSize(w, h); }

int Canvas::getWidth() { return width; }
int Canvas::getHeight() { return height; }

bool Canvas::setWidth(int w) {
    if (w > 0) {
        width = w;
        return true;
    }
    return false;
}
bool Canvas::setHeight(int h) {
    if (h > 0) {
        height = h;
        return true;
    }
    return false;
}
bool Canvas::setSize(int w, int h) {
    if (setWidth(w) && setHeight(h))
        return true;

    return false;
}

void Canvas::writeToFile(char* fileName) {

    // create a new BMP image
    BMP image;
    image.SetSize(width, height);
    image.SetBitDepth(32);

    // set the color of each pixel in the image
    for (int x=0; x<width; x++) {
        for (int y=0; y<height; y++) {
            image(x, y)->Red = 0;
            image(x, y)->Green = 255;
            image(x, y)->Blue = 100;
            image(x, y)->Alpha = 0;
        }
    }
    image.WriteToFile(fileName);
}
