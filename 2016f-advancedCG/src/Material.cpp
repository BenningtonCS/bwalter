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
float Material::getIOR() const { return ior; }
float Material::getReflection() const { return reflection; }


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

bool Material::setIOR(const float IOR) {
    if (IOR <= 1 && IOR >= 0) {
        ior = IOR;
        return true;
    }

    return false;
}

bool Material::setReflection(const float reflect) {
    if (reflect <= 1 && reflect >= 0) {
        reflection = reflect;
        return true;
    }

    return false;
}
