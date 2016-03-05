/*
    Sphere.cpp
    2016 March 2
    Brendon Walter

    Methods for the Sphere class
*/

#include <Sphere.h>


/* constructors */

Sphere::Sphere() { setSphere(0, 0, 0, 1); }
Sphere::Sphere(Vector3 cent, double r) { setSphere(cent, r); }
Sphere::Sphere(Vector3 cent, double r, Color col) { setSphere(cent, r, col); }
Sphere::Sphere(double X, double Y, double Z, double r) {
    setSphere(X, Y, Z, r);
}
Sphere::Sphere(double X, double Y, double Z, double r, Color col) {
    setSphere(X, Y, Z, r, col);
}


/* getters */

Vector3 Sphere::getCenter() { return center; }
double Sphere::getRadius() { return radius; }
Color Sphere::getColor() { return color; }
void Sphere::getSphere(Vector3* cent, double* r, Color* col) {
    *cent = center;
    *r = radius;
    *col = color;
}
void Sphere::getSphere(double* X, double* Y, double* Z, double* r, Color* col) {
    *X = center.getx(); *Y = center.gety(); *Z = center.getz();
    *r = radius;
    *col = color;
}


/* setters */

bool Sphere::setCenter(Vector3 cent) { center = cent; return true; }

bool Sphere::setCenter(double X, double Y, double Z) {
    Vector3 cent(X, Y, Z);
    if (setCenter(cent))
        return true;

    return false;
}

bool Sphere::setRadius(double r) {
    if (r > 0) {
        radius = r;
        return true;
    }

    return false;
}

bool Sphere::setColor(Color col) { color = col; return true; }

bool Sphere::setSphere(Vector3 cent, double r) {
    Color col;
    if (setSphere(cent, r, color))
        return true;

    return false;
}

bool Sphere::setSphere(Vector3 cent, double r, Color col) {
    if (setCenter(cent) && setRadius(r) && setColor(col))
        return true;

    return false;
}

bool Sphere::setSphere(double X, double Y, double Z, double r) {
    Color col(1, 1, 1, 1);
    if (setSphere(X, Y, Z, r, col))
        return true;

    return false;
}

bool Sphere::setSphere(double X, double Y, double Z, double r, Color col) {
    if (center.setx(X) && center.sety(Y) && center.setz(Z) &&
        setRadius(r) && setColor(col))
        return true;

    return false;
}

bool Sphere::isHit(Ray3 ray) {

    // sent a vector from the origin of the ray to the center of the sphere
    Vector3 originToCenter = getCenter() - ray.getOrigin();
    // project the new vector onto the direction of the ray
    float projectionOntoRay = originToCenter * ray.getDirection();

    // if the projection is negative, the sphere is behind the camera and
    // so not relevant
    if (projectionOntoRay < 0)
        return false;

    // distance between the center of the sphere and the projected vector
    float centerToProjection2 = originToCenter * originToCenter -
                                pow(projectionOntoRay, 2);

    // check if the ray misses the sphere
    if (centerToProjection2 > pow(getRadius(), 2))
        return false;

    float lengthInsideSphere2 = pow(getRadius(), 2) - centerToProjection2;

    float t0, t1;
    t0 = projectionOntoRay - sqrt(lengthInsideSphere2);
    t1 = projectionOntoRay + sqrt(lengthInsideSphere2);

    if (t0 > t1)
        std::swap(t0, t1);

    if (t0 < 0) {
        t0 = t1;
        if (t0 < 0)
            return false;
    }

    return true;
}
