/*
    Color.h
    2016 March 2
    Brendon Walter

    Class for creating colors
*/

#ifndef COLOR_H
#define COLOR_H

class Color {

  protected:
    float r, g, b, a; // rgba values are between 0 and 1

  public:

    /* constructors */

    Color();
    Color(float, float, float, float); // red, green, blue, alpha


    /* Setters */

    /*
    Parameters: float value for each color
    Returns: true if set correctly, false if not
    */
    bool setr(float);
    bool setg(float);
    bool setb(float);
    bool seta(float);
    bool setColor(float, float, float, float);


    /* getters */

    /*
    Parameters: None
    Returns: Float value for each color componant
    */
    float getr();
    float getg();
    float getb();
    float geta();

    /*
    Paramters:
       output: RGBA values as floats
    Returns: None

    Get the RGBA values using output paramters
    */
    void getColor(float*, float*, float*, float*);


    /* class methods */

    Color scaleColor(float);
};

#endif
