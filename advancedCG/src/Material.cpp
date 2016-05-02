#include <Materials.h>


/* constructors */

Material::Material() {
    Color white(1, 1, 1, 1);
    setMaterial(white, 0);
}

Material::Material(const Color& col, const float amb) {
    setMaterial(col, amb);
}


/* getters */

Color Material::getColor() const { return color; }
float Material::getAmbient() const { return ambient; }


/* setters */

bool Material::setColor(const Color& col) {
    color = col;
    return true;
}

bool Material::setAmbient(const float amb) {
    if (0 <= amb && amb <= 1) {
        ambient = amb;
        return true;
    }
    return false;
}

bool Material::setMaterial(const Color& col, const float amb) {
    if (setColor(col) && setAmbient(amb))
        return true;

    return false;
}
