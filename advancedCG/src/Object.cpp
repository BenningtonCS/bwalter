#include <Objects.h>


/* getters */

Color Object::getColor() const { return color; }


/* setters */

bool Object::setColor(const Color& col) { color = col; return true; }


/* class methods */

float Object::rayHitPosition(const Ray3& ray) const { return -1; }
Vector3 Object::getNormal(const Vector3& hitPos) const {
    Vector3 empty(0, 0, 0);
    return empty;
}
