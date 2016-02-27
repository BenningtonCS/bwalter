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
    int width;
    int height;

  public:
    Canvas();
    Canvas(int, int);

    /*
        Getters
    */
    int getWidth();
    int getHeight();

    /*
        Setters
    */
    void setWidth(int);
    void setHeight(int);
    void setSize(int, int); // width, height

    /*
        Class methods
    */
    void writeToFile(char*);
};

#endif
