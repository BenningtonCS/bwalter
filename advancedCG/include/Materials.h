#ifndef MATERIALS_H
#define MATERIALS_H

#include <Color.h>

class Material {
  protected:
    Color color;
    float ambient;

  public:

    /* constructors */

    Material();
    Material(const Color&, const float);


    /* getters */

    Color getColor() const;
    float getAmbient() const;


    /* setters */

    bool setColor(const Color&);
    bool setAmbient(const float);
    bool setMaterial(const Color&, const float);
};

#endif
