#ifndef MATERIALS_H
#define MATERIALS_H

#include <Color.h>

class Material {
  protected:
    Color color;
    float ambient = 0;
    float specular = 0;
    float roughness = 0;

  public:

    /* constructors */

    Material();
    Material(const Color&);


    /* getters */

    Color getColor() const;
    float getAmbient() const;
    float getSpecular() const;
    float getRoughness() const;


    /* setters */

    bool setColor(const Color&);
    bool setAmbient(const float);
    bool setSpecular(const float);
    bool setRoughness(const float);
};

#endif
