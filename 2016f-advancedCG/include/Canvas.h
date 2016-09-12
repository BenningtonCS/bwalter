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
    Canvas(const int, const int);


    /* getters */

    int getWidth() const;
    int getHeight() const;
    float getGamma() const;


    /* setters */

    bool setSize(const int, const int); // width, height
    bool setGamma(const float);

    /*
    Parameters: x, y coordinates of pixel on canvas as ints, color to set the
        pixel to
    Returns: None

    Set a pixel at (x, y) to a Color
    */
    void setPixel(const int, const int, const Color&);


    /* class methods */

    /*
    Parameters: Color channel specified as a float between 0 and 1
    Returns: integer between 0 and 255

    Convert RGBA values from being a float between 0 and 1 to an integer
    between 0 and 255
    */
    int convertToUInt8(const float) const;

    /*
    Parameters: Name of file to write to
    Returns: None

    Convert scalar RGBA values to UInt8 and writes them to a file
    */
    void writeToFile(const char*) const;
};

#endif
