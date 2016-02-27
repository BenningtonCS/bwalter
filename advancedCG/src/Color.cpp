Color() { r=0; g=0; b=0; a=0; }
Color(float red, float green, float blue, float alpha) {
    setColor(red, green, blue, alpha);
}

/*
    Setters
*/
bool setr(float red) {
    if (0 <= red && red <= 1) {
        r = red;
        return true;
    }
    return false;
}
bool setg(float green) {
    if (0 <= green && green <= 1) {
        g = green;
        return true;
    }
    return false;
}
bool setb(float blue) {
    if (0 <= blue && blue <= 1) {
        b = blue;
        return true;
    }
    return false;
}
bool seta(float alpha) {
    if (0 <= alpha && alpha <= 1) {
        a = alpha;
        return true;
    }
    return false;
}
bool setColor(float red, float green, float blue, float alpha) {
    if (setr(red) && setg(green) && setb(blue) && seta(alpha))
        return true;

    return false;
}

 /*
    Getters
*/
float getr() { return r; }
float getg() { return g; }
float getb() { return b; }
float geta() { return a; }
void getColor(float *red, float *green, float *blue, float *alpha) {
    *red = r; *green = g; *blue = b; *alpha = a;
}
