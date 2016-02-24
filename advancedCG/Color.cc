class Color {

  protected:
    // rgba values are between 0 and 1
    float r;
    float g;
    float b;
    float a;

  public:

    Color() { r=0; g=0; b=0; a=0; }
    Color(float red, float green, float blue, float alpha) {
        r = red; g = green; b = blue; a = alpha;    
    }

    /*
        Setters
    */

    void setr(float red)   { r = red; }
    void setg(float green) { g = green; }
    void setb(float blue)  { b = blue; }
    void seta(float alpha) { a = alpha; }
    void setColor(float red, float green, float blue, float alpha) {
        r = red; g = green; b = blue; a = alpha;
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
};
