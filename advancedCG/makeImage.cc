#include <string>
#include <stdio.h>
#include "lib/EasyBMP/EasyBMP.h"

using namespace std;

class Image {

  protected:

    string fileName;        // name of file to write to
    unsigned int width;     // width of image in pixels
    unsigned int height;    // height of image in pixels


  public:

    Image() {
        width = 800; height = 600; fileName = "image.bmp";
     }
    Image(unsigned int w, unsigned int h, string name) {
        width = w; height = h; fileName = name;
    }

    /*
        Setters
    */
    void setName(string name) { fileName = name; }
    void setWidth(int w)  { width = w; }
    void setHeight(int h) { height = h; }

    /*
        Getters
    */
    string getName() { return fileName; }
    int getWidth()   { return width; }
    int getHeight()  { return height; }

    /*
        Class methods
    */
    bool writeToFile() {

    }
};

int main(void) {
    //Image image;
    //printf("%d\n", image.getWidth());

    BMP image;
    image.SetSize(640, 480);
    image.SetBitDepth(32);

    image(14, 18)->Red = 255;
    image(14, 18)->Green = 255;
    image(14, 18)->Blue = 255;
    image(14, 18)->Alpha = 0;

    image.WriteToFile("Output.bmp");
}
