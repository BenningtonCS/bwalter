#include <Color.h>

Color::Color() { r=1; g=1; b=1; a=1; }
Color::Color(const float red, const float green, const float blue) {
    setColor(red, green, blue, 1);
}
Color::Color(const float red, const float green, const float blue,
             const float alpha) {
    setColor(red, green, blue, alpha);
}

/* setters */

bool Color::setr(const float red) {
    if (0 <= red && red <= 1) {
        r = red;
        return true;
    }
    return false;
}

bool Color::setg(const float green) {
    if (0 <= green && green <= 1) {
        g = green;
        return true;
    }
    return false;
}

bool Color::setb(const float blue) {
    if (0 <= blue && blue <= 1) {
        b = blue;
        return true;
    }
    return false;
}

bool Color::seta(const float alpha) {
    if (0 <= alpha && alpha <= 1) {
        a = alpha;
        return true;
    }
    return false;
}

bool Color::setColor(const float red, const float green, const float blue) {
    if (setr(red) && setg(green) && setb(blue))
        return true;

    return false;
}

bool Color::setColor(const float red, const float green, const float blue,
                     const float alpha) {
    if (setr(red) && setg(green) && setb(blue) && seta(alpha))
        return true;

    return false;
}


/* getters */

float Color::getr() const { return r; }
float Color::getg() const { return g; }
float Color::getb() const { return b; }
float Color::geta() const { return a; }


/* class methods */

Color Color::scale(const float s) const {
    Color col(getr()*s, getg()*s, getb()*s);
    return col;
}
