#include <Objects.h>


/* constructors */

Plane::Plane() {
    setNormal(0, 1, 0);
    setPoint(0, 0, 0);
}

Plane::Plane(const Vector3& n, const Vector3& p) {
    setNormal(n);
    setPoint(p);
}

Plane::Plane(const double nx, const double ny, const double nz,
             const double px, const double py, const double pz) {
    setNormal(nx, ny, nz);
    setPoint(px, py, pz);
}


/* getters */

Vector3 Plane::getNormal() const { return normal; }
Vector3 Plane::getPoint() const { return point; }


/* setters */

bool Plane::setNormal(const Vector3& n) {
    normal = n; return true;
}

bool Plane::setNormal(const double X, const double Y, const double Z) {
    Vector3 n(X, Y, Z);
    if (setNormal(n))
        return true;

    return false;
}

bool Plane::setPoint(const Vector3& p) {
    point = p; return true;
}

bool Plane::setPoint(const double X, const double Y, const double Z) {
    Vector3 p(X, Y, Z);
    if (setPoint(p))
        return true;

    return false;
}

bool Plane::setPlane(const Vector3& n, const Vector3& p) {
    if (setNormal(n) && setPoint(p))
        return true;

    return false;
}

bool Plane::setPlane(const double nx, const double ny, const double nz,
                     const double px, const double py, const double pz) {

    if (setNormal(nx, ny, nz) && setPoint(px, py, pz))
        return true;

    return false;
}


/* class methods */

float Plane::rayHitPosition(const Ray3& ray) const {

    float t = -1;

//    printf("%.2f\t",((ray.getDirection() - getPoint()) * getNormal()));
    if (((ray.getDirection() - getPoint()) * getNormal()) == 0) {
        t = (((getPoint() - ray.getOrigin()) * getNormal()) /
               (ray.getDirection() * getNormal()));

    }
    printf("%.2f\t", t);
    return t;
}
