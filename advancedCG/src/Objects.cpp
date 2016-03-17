#include <Objects.h>

/* O B J E C T */

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


/* S P H E R E */

/* constructors */

Sphere::Sphere() { setSphere(0, 0, 0, 1); }
Sphere::Sphere(const Vector3& cent, const double r) {
    setSphere(cent, r);
}

Sphere::Sphere(const Vector3& cent, const double r, const Color& col) {
    setSphere(cent, r, col);
}

Sphere::Sphere(const double X, const double Y, const double Z,
               const double r) {
    setSphere(X, Y, Z, r);
}

Sphere::Sphere(const double X, const double Y, const double Z,
               const double r, const Color& col) {
    setSphere(X, Y, Z, r, col);
}


/* getters */

Vector3 Sphere::getCenter() const { return center; }
double Sphere::getRadius() const { return radius; }


/* setters */

bool Sphere::setCenter(const Vector3& cent) { center = cent; return true; }

bool Sphere::setCenter(const double X, const double Y, const double Z) {
    Vector3 cent(X, Y, Z);
    if (setCenter(cent))
        return true;

    return false;
}

bool Sphere::setRadius(const double r) {
    if (r > 0) {
        radius = r;
        return true;
    }

    return false;
}

bool Sphere::setSphere(const Vector3& cent, const double r) {
    Color col;
    if (setSphere(cent, r, color))
        return true;

    return false;
}

bool Sphere::setSphere(const Vector3& cent, const double r, const Color& col) {
    if (setCenter(cent) && setRadius(r) && setColor(col))
        return true;

    return false;
}

bool Sphere::setSphere(const double X, const double Y, const double Z,
                       const double r) {

    Color col(1, 1, 1, 1);
    if (setSphere(X, Y, Z, r, col))
        return true;

    return false;
}

bool Sphere::setSphere(const double X, const double Y, const double Z,
                       const double r, const Color& col) {

    if (center.setx(X) && center.sety(Y) && center.setz(Z) &&
        setRadius(r) && setColor(col))
        return true;

    return false;
}

float Sphere::rayHitPosition(const Ray3& ray) const {

    // thanks to
    // http://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-
    // tracer-rendering-simple-shapes/ray-sphere-intersection
    // for the detailed explanation

    // send a vector from the origin of the ray to the center of the sphere
    Vector3 originToCenter = getCenter() - ray.getOrigin();
    // project the new vector onto the direction of the ray
    float projectionOntoRay = originToCenter * ray.getDirection();

    // if the projection is negative, the sphere is behind the camera and
    // so not relevant
    if (projectionOntoRay < 0)
        return -1;

    // distance between the center of the sphere and the projected vector
    float centerToProjection2 = originToCenter * originToCenter -
                                pow(projectionOntoRay, 2);

    // check if the ray misses the sphere
    if (centerToProjection2 > pow(getRadius(), 2))
        return -1;

    float lengthInsideSphere2 = pow(getRadius(), 2) - centerToProjection2;

    float t0, t1;
    t0 = projectionOntoRay - sqrt(lengthInsideSphere2);
    t1 = projectionOntoRay + sqrt(lengthInsideSphere2);

    if (t0 > t1)
        std::swap(t0, t1);

    if (t0 < 0) {
        t0 = t1;
        if (t0 < 0)
            return -1;
    }

    return t0;
}

Vector3 Sphere::getNormal(const Vector3& hitPos) const {
    Vector3 normal = hitPos - getCenter()  /
                     (hitPos - getCenter()).getMagnitude();
    normal.printVector();
    return normal;
}
