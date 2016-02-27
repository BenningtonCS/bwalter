class Color {

  protected:
    float r, g, b, a; // rgba values are between 0 and 1

  public:

    Color();
    Color(float, float, float, float); // red, green, blue, alpha

    /*
        Setters
    */
    bool setr(float);
    bool setg(float);
    bool setb(float);
    bool seta(float);
    bool setColor(float, float, float, float);

     /*
        Getters
    */
    float getr();
    float getg();
    float getb();
    float geta();
    void getColor(float*, float*, float*, float*);
};
