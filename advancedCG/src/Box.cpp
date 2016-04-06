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
    Vector3 m = min - hitPos;

    if (m.getx() <= 0.0001) normal.setVector(-1, 0, 0);
    if (m.gety() <= 0.0001) normal.setVector(0, -1, 0);
    if (m.getz() <= 0.0001) normal.setVector(0, 0, -1);

    if (hitPos.getx() == max.getx()) normal.setVector(1, 0, 0);
    if (hitPos.gety() == max.gety()) normal.setVector(0, 1, 0);
    if (hitPos.getz() == max.getz()) normal.setVector(0, 0, 1);

    return normal;
}

double Box::rayHitPosition(const Ray3& ray) const {

    float denom = ray.getDirection().getx();
    float tx0 = (min.getx() - ray.getOrigin().getx()) / denom;
    float tx1 = (max.getx() - ray.getOrigin().getx()) / denom;

    float tx0Real, tx1Real;
    if (tx0 < tx1) {
        tx0Real = tx0;
        tx1Real = tx1;
    } else {
        tx0Real = tx1;
        tx1Real = tx0;
    }

    denom = ray.getDirection().gety();
    float ty0 = (min.gety() - ray.getOrigin().gety()) / denom;
    float ty1 = (max.gety() - ray.getOrigin().gety()) / denom;

    float ty0Real, ty1Real;
    if (ty0 < ty1) {
        ty0Real = ty0;
        ty1Real = ty1;
    } else {
        ty0Real = ty1;
        ty1Real = ty0;
    }

    denom = ray.getDirection().getz();
    float tz0 = (min.getz() - ray.getOrigin().getz()) / denom;
    float tz1 = (max.getz() - ray.getOrigin().getz()) / denom;

    float tz0Real, tz1Real;
    if (tz0 < tz1) {
        tz0Real = tz0;
        tz1Real = tz1;
    } else {
        tz0Real = tz1;
        tz1Real = tz0;
    }

    float t = -1;

    // misses the box
    if (tx1Real < ty0Real || tx1Real < tz0Real ||
        ty1Real < tx0Real || ty1Real < tz0Real ||
        tz1Real < tx0Real || tz1Real < ty0Real) {

        return t;
    }

    // hits the box
    if (tx0Real >= ty0Real && tx0Real >= tz0Real) t = tx0Real;
    if (ty0Real >= tx0Real && ty0Real >= tz0Real) t = ty0Real;
    if (tz0Real >= tx0Real && tz0Real >= ty0Real) t = tz0Real;

    return t;
}
