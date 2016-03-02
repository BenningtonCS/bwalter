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
#include <Color.h>

class Canvas {

  protected:
    int width;          // width of canvas. 800 by default
    int height;         // height of canvas. 600 by default
    Color** pixels;     // 2D array of pixels
    float gamma;        // gamma of the monitor. This is 2.2 by default.

  public:

    /* constructors */

    Canvas();
    Canvas(int, int);


    /* getters */

    int getWidth();
    int getHeight();
    float getGamma();


    /* setters */

    bool setSize(int, int); // width, height
    bool setGamma(float);

    /*
    Parameters: x, y coordinates of pixel on canvas as ints, color to set the
        pixel to
    Returns: None

    Set a pixel at (x, y) to a Color
    */
    void setPixel(int, int, Color);


    /* class methods */

    /*
    Parameters: Color channel specified as a float between 0 and 1, gamma of
        the monitor as a float
    Returns: integer between 0 and 255

    Convert RGBA values from being a float between 0 and 1 to an integer
    between 0 and 255
    */
    int convertToUInt8(float, float);

    /*
    Parameters: Name of file to write to
    Returns: None

    Convert scalar RGBA values to UInt8 and writes them to a file
    */
    void writeToFile(char*);
};

#endif
