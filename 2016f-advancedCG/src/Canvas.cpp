#include <Canvas.h>

/* constructors */

Canvas::Canvas() { setSize(800, 600); setGamma(2.2); }
Canvas::Canvas(const int w, const int h) { setSize(w, h); setGamma(2.2); }


/* getters */

int Canvas::getWidth() const { return width; }
int Canvas::getHeight() const { return height; }
float Canvas::getGamma() const { return gamma; }


/* setters */

bool Canvas::setSize(const int w, const int h) {
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

bool Canvas::setGamma(const float g) { gamma = g; return true;}

void Canvas::setPixel(const int x, const int y, const Color& color) {
    if (x >= 0 && x <= width) {
        if (y >= 0 && y <= height) {
            pixels[x][y] = color;
        }
    }
}


/* class methods */

int Canvas::convertToUInt8(const float color) const {
    return 255 * pow(color, 1/gamma);
}

void Canvas::writeToFile(const char* fileName) const {
    // create a new BMP image
    BMP image;
    image.SetSize(width, height);
    image.SetBitDepth(32);

    // set the color of each pixel in the image
    for (int x=0; x<width; x++) {
        for (int y=0; y<height; y++) {
            image(x, y)->Red = convertToUInt8(pixels[x][y].getr());
            image(x, y)->Green = convertToUInt8(pixels[x][y].getg());
            image(x, y)->Blue = convertToUInt8(pixels[x][y].getb());
            image(x, y)->Alpha = convertToUInt8(pixels[x][y].geta());
        }
    }
    image.WriteToFile(fileName);
}
