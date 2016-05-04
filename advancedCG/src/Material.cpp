#include <Materials.h>


/* constructors */

Material::Material() {
    Color white(1, 1, 1, 1);
    setColor(white);
}

Material::Material(const Color& col) {
    setColor(col);
}


/* getters */

Color Material::getColor() const { return color; }
float Material::getAmbient() const { return ambient; }
float Material::getSpecular() const { return specular; }
float Material::getRoughness() const { return roughness; }


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

bool Material::setSpecular(const float spec) {
    if (0 <= spec && spec <= 1) {
        specular = spec;
        return true;
    }
    return false;
}

bool Material::setRoughness(const float rough) {
    if (rough >= 0) {
        roughness = rough;
        return true;
    }

    return false;
}
