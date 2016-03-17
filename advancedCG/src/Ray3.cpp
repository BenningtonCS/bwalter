#include <Ray3.h>

/* constructors */

Ray3::Ray3() {
    setRay(0, 0, 0, 1, 1, 1);
}

Ray3::Ray3(const Vector3& origin, const Vector3& direction) {
    setRay(origin, direction);
}

Ray3::Ray3(const double ox, const double oy, const double oz,
           const double dx, const double dy, const double dz) {
    setRay(ox, oy, oz, dx, dy, dz);
}


/* getters */

Vector3 Ray3::getOrigin() const { return origin; }
Vector3 Ray3::getDirection() const { return direction; }


/* setters */

bool Ray3::setOrigin(const Vector3& orig) {
    origin = orig;
    return true;
}

bool Ray3::setDirection(const Vector3& dir) {
    direction = dir.makeUnitVector();
    return true;
}

bool Ray3::setOrigin(const double X, const double Y, const double Z) {
    Vector3 orig(X, Y, Z);
    origin = orig;
    return true;
}

bool Ray3::setDirection(const double X, const double Y, const double Z) {
    Vector3 dir(X, Y, Z);
    direction = dir.makeUnitVector();
    return true;
}

bool Ray3::setRay(const Vector3& orig, const Vector3& dir) {
    if (setOrigin(orig) && setDirection(dir))
        return true;
    return false;
}

bool Ray3::setRay(const double ox, const double oy, const double oz,
                  const double dx, const double dy, const double dz) {
    if (setOrigin(ox, oy, oz) && setDirection(dx, dy, dz))
        return true;
    return false;
}


/* class methods */

void Ray3::printRay() const {
    printf("(%.5f, %.5f, %.5f), (%.5f, %.5f, %.5f)\n",
           origin.getx(), origin.gety(), origin.getz(),
           direction.getx(), direction.gety(), direction.getz());
}

Vector3 Ray3::rayAtT(const float t) const {
    Vector3 result(getOrigin() + getDirection()*t);
    return result;
}
