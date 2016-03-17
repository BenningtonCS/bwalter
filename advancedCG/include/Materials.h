#ifndef MATERIALS_H
#define MATERIALS_H

#include <Color.h>

class Material {
  protected:
    Color color;
    float ambient;

  public:

    /* getters */

    Color getColor();
    float getAmbient();

    /* setters */

    bool setColor();
    bool setAmbient();
};

#endif
