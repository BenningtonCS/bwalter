#include <Objects.h>


/* constructors */

Box::Box() {
    setMin(0, 0, 0); setMax(1, 1, 1); setColor();
}

Box::Box(const Vector3& mn, const Vector3& mx) {
    setMin(mn); setMax(mx); setColor();
}

Box::Box(const Vector3& mn, const Vector3& mx, const Color& col) {
    setMin(mn); setMax(mx); setColor(col);
}

Box::Box(const double x1, const double y1, const double z1,
         const double x2, const double y2, const double z2) {
    setMin(x1, y1, z1); setMax(x2, y2, z2); setColor();
}

Box::Box(const double x1, const double y1, const double z1,
         const double x2, const double y2, const double z2, const Color& col) {
    setMin(x1, y1, z1); setMax(x2, y2, z2); setColor(col);
}


/* getters */

Vector3 Box::getMin() const { return min; }
Vector3 Box::getMax() const { return max; }


/* setters */

bool Box::setMin(const Vector3& m) {
    min = m; return true;
}

bool Box::setMin(const double X, const double Y, const double Z) {
    Vector3 m(X, Y, Z);
    if (setMin(m))
        return true;

    return false;
}

bool Box::setMax(const Vector3& m) {
    max = m; return true;
}

bool Box::setMax(const double X, const double Y, const double Z) {
    Vector3 m(X, Y, Z);
    if (setMax(m))
        return true;

    return false;
}


/* class methods */

Vector3 Box::getNormal(const Vector3& hitPos) const {
    Vector3 normal;
    return normal;
}

float Box::rayHitPosition(const Ray3& ray) const {

    // create 6 planes making up the box
    Plane txmin(-1, 0, 0, min.getx(), 0, 0);
    Plane txmax(1, 0, 0, max.getx(), 0, 0);

    Plane tymin(0, -1, 0, 0, min.gety(), 0);
    Plane tymax(0, 1, 0, 0, max.gety(), 0);

    Plane tzmin(0, 0, -1, 0, 0, min.getz());
    Plane tzmax(0, 0, 1, 0, 0, max.getz());

    // get the points where the ray intersects with the planes in x
    float tx0 = txmin.rayHitPosition(ray);
    float tx1 = txmax.rayHitPosition(ray);

    float ty0 = tymin.rayHitPosition(ray);
    float ty1 = tymax.rayHitPosition(ray);

    float tz0 = tzmin.rayHitPosition(ray);
    float tz1 = tzmax.rayHitPosition(ray);


}
