#include <Objects.h>

/* constructors */

Disk::Disk() {
    Color col;
    setDisk(0, 1, 0, 0, 0, 0, 1, col);
}

Disk::Disk(const Vector3& n, const Vector3& c, const float r) {
    Color col;
    setDisk(n, c, r, col);
}

Disk::Disk(const Vector3& n, const Vector3& c, const float r, const Color& col) {
    setDisk(n, c, r, col);
}

Disk::Disk(const double nx, const double ny, const double nz,
           const double cx, const double cy, const double cz,
           const float r) {
    Color col;
    setDisk(nx, ny, nz, cx, cy, cz, r, col);

}

Disk::Disk(const double nx, const double ny, const double nz,
           const double cx, const double cy, const double cz,
           const float r, const Color& col) {
    setDisk(nx, ny, nz, cx, cy, cz, r, col);
}


/* getters */

Vector3 Disk::getNormal() const { return normal; }
Vector3 Disk::getCenter() const { return center; }
float Disk::getRadius() const { return radius; }


/* setters */

bool Disk::setNormal(const Vector3& n) {
    normal = n.makeUnitVector(); return true;
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

bool Disk::setDisk(const Vector3& n, const Vector3& c, const float r) {
    if (setNormal(n) && setCenter(c) && setRadius(r))
        return true;

    return false;
}

bool Disk::setDisk(const Vector3& n, const Vector3& c,  const float r,
                   const Color& col) {
    if (setDisk(n, c, r) && setColor(col))
        return true;

    return false;
}

bool Disk::setDisk(const double nx, const double ny, const double nz,
                   const double cx, const double cy, const double cz,
                   const float r) {
    Vector3 n(nx, ny, nz);
    Vector3 c(cx, cy, cz);
    if (setDisk(n, c, r))
        return true;

    return false;
}

bool Disk::setDisk(const double nx, const double ny, const double nz,
                   const double cx, const double cy, const double cz,
                   const float r, const Color& col) {
    Vector3 n(nx, ny, nz);
    Vector3 c(cx, cy, cz);
    if (setDisk(n, c, r) && setColor(col))
        return true;

    return false;
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
