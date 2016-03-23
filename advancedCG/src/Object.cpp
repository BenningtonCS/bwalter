#include <Objects.h>

Object::Object() { material.setAmbient(0); }

/* getters */

Color Object::getColor() const { return color; }
Material Object::getMaterial() const { return material; }


/* setters */
bool Object::setColor() {
    Color c(1, 1, 1, 1);
    if (setColor(c))
        return true;

    return false;
}

bool Object::setColor(const float r, const float g, const float b,
                      const float a) {
    Color c(r, g, b, a);
    if (setColor(c))
        return true;

    return false;
}

bool Object::setColor(const Color& col) {
    color = col;
    return true;
}

bool Object::setMaterial(const Material& mat) {
    material = mat;
    return true;
}

/* class methods */

float Object::rayHitPosition(const Ray3& ray) const { return -1; }
Vector3 Object::getNormal(const Vector3& hitPos) const {
    Vector3 empty(0, 0, 0);
    return empty;
}
