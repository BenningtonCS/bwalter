#include <Objects.h>


/* constructors */

Plane::Plane() {
    setNormal(0, 1, 0); setPoint(0, 0, 0); setColor();
}

Plane::Plane(const Vector3& n, const Vector3& p) {
    setNormal(n); setPoint(p); setColor();
}

Plane::Plane(const Vector3& n, const Vector3& p, const Color& col) {
    setNormal(n); setPoint(p); setColor(col);
}

Plane::Plane(const double nx, const double ny, const double nz,
             const double px, const double py, const double pz) {
    setNormal(nx, ny, nz); setPoint(px, py, pz); setColor();
}

Plane::Plane(const double nx, const double ny, const double nz,
             const double px, const double py, const double pz,
             const Color& col) {
    setNormal(nx, ny, nz); setPoint(px, py, pz); setColor(col);
}


/* getters */

Vector3 Plane::getNormal() const {
    return inverseMatrix.getTranspose().transformVector(normal);
}

Vector3 Plane::getPoint() const { return point; }


/* setters */

bool Plane::setNormal(const Vector3& n) {
    normal = n.normalize(); return true;
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


/* class methods */

Vector3 Plane::getNormal(const Vector3& hitPos) const {
    return getNormal();
}

double Plane::rayHitPosition(const Ray3& ray) const {

    float denom = getNormal() * ray.getDirection();
    if (denom != 0)
          return ((getPoint() - ray.getOrigin()) * getNormal()) / denom;

    return -1;
}
