#include <Ray3.h>

/* constructors */

Ray3::Ray3() {
    setRay(0, 0, 0, 1, 0, 0);
}

Ray3::Ray3(Vector3 origin, Vector3 direction) {
    setRay(origin, direction);
}

Ray3::Ray3(double ox, double oy, double oz, double dx, double dy, double dz) {
    setRay(ox, oy, oz, dx, dy, dz);
}


/* getters */

Vector3 Ray3::getOrigin() { return origin; }
Vector3 Ray3::getDirection() { return direction; }

void Ray3::getOrigin(double* X, double* Y, double* Z) {
    *X = origin.getx();
    *Y = origin.gety();
    *Z = origin.getz();
}

void Ray3::getDirection(double* X, double* Y, double* Z) {
    *X = direction.getx();
    *Y = direction.gety();
    *Z = direction.getz();
}

void Ray3::getRay(double* ox, double* oy, double* oz,
                  double* dx, double* dy, double* dz) {
    getOrigin(ox, oy, oz);
    getDirection(dx, dy, dz);
}


/* setters */

bool Ray3::setOrigin(Vector3 orig) {
    origin = orig;
    return true;
}

bool Ray3::setDirection(Vector3 dir) {
    direction = dir.makeUnitVector();
    return true;
}

bool Ray3::setOrigin(double X, double Y, double Z) {
    Vector3 orig(X, Y, Z);
    origin = orig;
    return true;
}

bool Ray3::setDirection(double X, double Y, double Z) {
    Vector3 dir(X, Y, Z);
    direction = dir.makeUnitVector();
    return true;
}

bool Ray3::setRay(Vector3 orig, Vector3 dir) {
    if (setOrigin(orig) && setDirection(dir))
        return true;
    return false;
}

bool Ray3::setRay(double ox, double oy, double oz,
                  double dx, double dy, double dz) {
    if (setOrigin(ox, oy, oz) && setDirection(dx, dy, dz))
        return true;
    return false;
}


/* class methods */

void Ray3::printRay() {
    printf("(%.5f, %.5f, %.5f), (%.5f, %.5f, %.5f)\n",
           origin.getx(), origin.gety(), origin.getz(),
           direction.getx(), direction.gety(), direction.getz());
}

Vector3 Ray3::rayAtT(float t) {
    Vector3 result(getOrigin() + getDirection()*t);
    return result;
}
