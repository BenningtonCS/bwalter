#include <Objects.h>

/* constructors */

Disk::Disk() {
    setNormal(0, 1, 0); setCenter(0, 0, 0); setRadius(1); setColor();
}

Disk::Disk(const Vector3& n, const Vector3& c, const float r) {
    setNormal(n); setCenter(c); setRadius(r); setColor();
}

Disk::Disk(const Vector3& n, const Vector3& c, const float r, const Color& col) {
    setNormal(n); setCenter(c); setRadius(r); setColor(col);
}

Disk::Disk(const double nx, const double ny, const double nz,
           const double cx, const double cy, const double cz,
           const float r) {
    setNormal(nx, ny, nz); setCenter(cx, cy, cz); setRadius(r); setColor();
}

Disk::Disk(const double nx, const double ny, const double nz,
           const double cx, const double cy, const double cz,
           const float r, const Color& col) {
    setNormal(nx, ny, nz); setCenter(cx, cy, cz); setRadius(r); setColor(col);
}


/* getters */

Vector3 Disk::getNormal() const { return normal; }
Vector3 Disk::getCenter() const { return center; }
float Disk::getRadius() const { return radius; }


/* setters */

bool Disk::setNormal(const Vector3& n) {
    normal = n.normalize(); return true;
}

bool Disk::setNormal(const double X, const double Y, const double Z) {
    Vector3 n(X, Y, Z);
    if (setNormal(n))
        return true;

    return false;
}

bool Disk::setCenter(const Vector3& c) {
    center = c; return true;
}

bool Disk::setCenter(const double X, const double Y, const double Z) {
    Vector3 c(X, Y, Z);
    if (setCenter(c))
        return true;

    return false;
}

bool Disk::setRadius(const float r) {
    if (r < 0)
        return false;

    radius = r;
    return true;

}


/* class methods */
Vector3 Disk::getNormal(const Vector3& hitPos) const {
    return normal;
}

float Disk::rayHitPosition(const Ray3& ray) const {
    // create a plane over the disk and check if the ray hits the plane
    Plane plane(getNormal(), getCenter());
    float t = plane.rayHitPosition(ray);
    if (t != -1) {
        // if it does, check if its inside the disk
        Vector3 hitPos = ray.rayAtT(t);
        if ((hitPos - getCenter()).getMagnitudeSquared() <= pow(getRadius(), 2))
            return t;
    }

    return -1;
}
