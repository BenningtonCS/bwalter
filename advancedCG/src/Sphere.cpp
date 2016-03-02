#include <Sphere.h>


/* constructors */

Sphere::Sphere() {
    setSphere(0, 0, 0, 1);
}

Sphere::Sphere(Vector3 cent, double r) {
    setSphere(cent, r);
}

Sphere::Sphere(Vector3 cent, double r, Color col) {
    setSphere(cent, r, col);
}

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

bool Sphere::setCenter(Vector3 cent) {
    center = cent;
    return true;
}

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

bool Sphere::setColor(Color col) {
    color = col;
    return true;
}

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
