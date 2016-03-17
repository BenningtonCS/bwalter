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
    Color(const float, const float, const float);               // r, g, b
    Color(const float, const float, const float, const float);  // r, g, b, a


    /* Setters */

    /*
    Parameters: float value for each color
    Returns: true if set correctly, false if not
    */
    bool setr(const float);
    bool setg(const float);
    bool setb(const float);
    bool seta(const float);
    bool setColor(const float, const float, const float);              // rgb
    bool setColor(const float, const float, const float, const float); // rgba


    /* getters */

    /*
    Parameters: None
    Returns: Float value for each color componant
    */
    float getr() const;
    float getg() const;
    float getb() const;
    float geta() const;

    /* class methods */

    /*
    Parameters: scale value as a float
    Returns: The scaled color

    Scale a color by a certain amount. For example, if you have a pure white
    (1, 1, 1, 1) and you want to turn it down to (.5, .5, .5,. 1),
    call white.scale(0.5)
    */
    Color scale(const float) const;
};

#endif
