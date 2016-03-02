#include <Color.h>

Color::Color() { r=0; g=0; b=0; a=0; }
Color::Color(float red, float green, float blue, float alpha) {
    setColor(red, green, blue, alpha);
}

/* setters */

bool Color::setr(float red) {
    if (0 <= red && red <= 1) {
        r = red;
        return true;
    }
    return false;
}
bool Color::setg(float green) {
    if (0 <= green && green <= 1) {
        g = green;
        return true;
    }
    return false;
}
bool Color::setb(float blue) {
    if (0 <= blue && blue <= 1) {
        b = blue;
        return true;
    }
    return false;
}
bool Color::seta(float alpha) {
    if (0 <= alpha && alpha <= 1) {
        a = alpha;
        return true;
    }
    return false;
}
bool Color::setColor(float red, float green, float blue, float alpha) {
    if (setr(red) && setg(green) && setb(blue) && seta(alpha))
        return true;

    return false;
}

/* getters */

float Color::getr() { return r; }
float Color::getg() { return g; }
float Color::getb() { return b; }
float Color::geta() { return a; }
void Color::getColor(float* red, float* green, float* blue, float* alpha) {
    *red = r; *green = g; *blue = b; *alpha = a;
}

/* basic colors */

Color Color::red() {
    Color red(1, 0, 0, 1);
    return red;
}

Color Color::green() {
    Color green(0, 1, 0, 1);
    return green;
}

Color Color::blue() {
    Color blue(0, 0, 1, 1);
    return blue;
}

Color Color::white() {
    Color white(1, 1, 1, 1);
    return white;
}

Color Color::black() {
    Color black(0, 0, 0, 1);
    return black;
}
