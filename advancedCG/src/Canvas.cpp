#include <Canvas.h>

using namespace std;

Canvas::Canvas() {
    setWidth(800);
    setHeight(600);
    fileName = "image.bmp";
}

Canvas::Canvas(unsigned int width, unsigned int height, string name) {
    setWidth(width);
    setHeight(height);
    fileName = "image.bmp";
}

void Canvas::setName(string name) { fileName = name; }

string Canvas::getName() { return fileName; }

void Canvas::writeToFile() {
    WriteImage(fileName);
}
