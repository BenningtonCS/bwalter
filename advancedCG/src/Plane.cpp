#include <Objects.h>


/* constructors */

Plane::Plane() {
    setPlane(0, 1, 0, 0, 0, 0);
}

Plane::Plane(const Color& col) {
    setPlane(0, 1, 0, 0, 0, 0, col);
}

Plane::Plane(const Vector3& n, const Vector3& p) {
    setPlane(n, p);
}

Plane::Plane(const Vector3& n, const Vector3& p, const Color& col) {
    setPlane(n, p, col);
}

Plane::Plane(const double nx, const double ny, const double nz,
             const double px, const double py, const double pz) {
    setPlane(nx, ny, nz, px, py, pz);
}

Plane::Plane(const double nx, const double ny, const double nz,
             const double px, const double py, const double pz,
             const Color& col) {
    setPlane(nx, ny, nz, px, py, pz, col);
}


/* getters */

Vector3 Plane::getNormal() const { return normal; }
Vector3 Plane::getPoint() const { return point; }


/* setters */

bool Plane::setNormal(const Vector3& n) {
    normal = n.makeUnitVector(); return true;
}

bool Plane::setNormal(const double X, const double Y, const double Z) {
    Vector3 n(X, Y, Z);
    if (setNormal(n))
        return true;

    return false;
}

bool Plane::setPoint(const Vector3& p) {
    point = p.makeUnitVector(); return true;
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

bool Plane::setPlane(const Vector3& n, const Vector3& p, const Color& col) {
    if (setPlane(n, p) && setColor(col))
        return true;

    return false;
}

bool Plane::setPlane(const double nx, const double ny, const double nz,
                     const double px, const double py, const double pz) {
    if (setNormal(nx, ny, nz) && setPoint(px, py, pz))
        return true;

    return false;
}

bool Plane::setPlane(const double nx, const double ny, const double nz,
                     const double px, const double py, const double pz,
                     const Color& col) {
    if (setPlane(nx, ny, nz, px, py, pz) && setColor(col))
        return true;

    return false;
}


/* class methods */

Vector3 Plane::getNormal(const Vector3& hitPos) const {
    return getNormal();
}

float Plane::rayHitPosition(const Ray3& ray) const {

    float denom = getNormal() * ray.getDirection();
    if (denom != 0)
          return ((getPoint() - ray.getOrigin()) * getNormal()) / denom;

    return -1;
}
