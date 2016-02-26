/*
    Canvas.h
    2016 Feb 25
    Brendon Walter

    Canvas class. Turn an array of pixels into an image.

    Methods for this class are found in Canvas.cpp in include/
*/

#ifndef CANVAS_H
#define CANVAS_H

#include <EasyBMP.h>

class Canvas {

  protected:
    unsigned int width;
    unsigned int height;

  public:
    Canvas();
    Canvas(unsigned int, unsigned int);

    /*
        Getters
    */
    int getWidth();
    int getHeight();

    /*
        Setters
    */
    void setWidth(unsigned int);
    void setHeight(unsigned int);
    void setSize(unsigned int, unsigned int); // width, height

    /*
        Class methods
    */
    void writeToFile(char*);
};

#endif
