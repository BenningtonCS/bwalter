#include <Objects.h>


/* constructors */

Sphere::Sphere() {
    setCenter(0, 0, 0); setRadius(1); setColor();
}
Sphere::Sphere(const Vector3& cent, const double r) {
    setCenter(cent); setRadius(r); setColor();
}

Sphere::Sphere(const Vector3& cent, const double r, const Color& col) {
    setCenter(cent); setRadius(r); setColor(col);
}

Sphere::Sphere(const double X, const double Y, const double Z,
               const double r) {
    setCenter(X, Y, Z); setRadius(r); setColor();
}

Sphere::Sphere(const double X, const double Y, const double Z,
               const double r, const Color& col) {
    setCenter(X, Y, Z); setRadius(r); setColor(col);
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


/* class methods */

Vector3 Sphere::getNormal(const Vector3& hitPos) const {
    Vector3 normal = (hitPos - getCenter())  / getRadius();
    return normal;
}

double Sphere::rayHitPosition(const Ray3& ray) const {

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

    float t0 = projectionOntoRay - sqrt(lengthInsideSphere2);
    if (t0 < 0)
        return projectionOntoRay + sqrt(lengthInsideSphere2);

    return t0;
}
