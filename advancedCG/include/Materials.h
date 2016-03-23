#ifndef MATERIALS_H
#define MATERIALS_H


class Material {
  protected:
    float ambient;

  public:

    /* constructors */

    Material();
    Material(const float);


    /* getters */

    float getAmbient() const;


    /* setters */

    bool setAmbient(const float);
};

#endif
