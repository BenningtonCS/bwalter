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
    if (red < 0) r = 0;
    else if (red > 1) r = 1;
    else r = red;
    return true;
}

bool Color::setg(const float green) {
    if (green < 0) g = 0;
    else if (green > 1) g = 1;
    else g = green;

    return true;
}

bool Color::setb(const float blue) {
    if (blue < 0) b = 0;
    else if (blue > 1) b = 1;
    else b = blue;

    return true;
}
bool Color::seta(const float alpha) {
    if (alpha < 0) a = 0;
    else if (alpha > 1) a = 1;
    else a = alpha;

    return true;
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


/* operator overloads */
Color Color::operator+(const Color& col) const {
    Color c(getr()+col.getr(), getg()+col.getg(), getb()+col.getb(),
            geta()+col.geta());
    return c;
}

Color Color::operator-(const Color& col) const {
    Color c(getr()-col.getr(), getg()-col.getg(), getb()-col.getb(),
            geta()-col.geta());
    return c;
}

Color Color::operator*(const Color& col) const {
    Color c(getr()*col.getr(), getg()*col.getg(), getb()*col.getb(),
            geta()*col.geta());
    return c;
}

Color Color::operator*(const float s) const {
    Color c(getr()*s, getg()*s, getb()*s, geta()*s);
    return c;
}

Color Color::operator/(const Color& col) const {
    Color c(getr()/col.getr(), getg()/col.getg(), getb()/col.getb(),
            geta()/col.geta());
    return c;
}

Color Color::operator/(const float s) const {
    Color c(getr()/s, getg()/s, getb()/s, geta()*s);
    return c;
}

bool Color::operator==(const Color& col) const {
    if (getr() == col.getr() && getg() == col.getg() && getb() == col.getb() &&
        geta() == col.geta())
        return true;

    return false;
}

bool Color::operator!=(const Color& col) const {
    if (getr() != col.getr() && getg() != col.getg() && getb() != col.getb() &&
        geta() != col.geta())
        return true;

    return false;
}
