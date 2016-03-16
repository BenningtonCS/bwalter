#include <Lights.h>

/* L I G H T */

/* getters */

Color Light::getColor() { return color; }

/* setters */

bool Light::setColor(Color col) { color = col; return true; }
bool Light::setColor(float r, float g, float b, float a) {
    Color col(r, g, b, a);
    color = col;
    return true;
}

float Light::getIntensity(Vector3 hitPos, Object obj) { return 1; }


/* D I R E C T I O N A L   L I G H T */

/* constructors */

DirectionalLight::DirectionalLight() {
    setColor(1, 1, 1, 1);
    setDirection(1, -1, 1);
}
DirectionalLight::DirectionalLight(Color col) {
    setColor(col);
    setDirection(1, -1, 1);
}
DirectionalLight::DirectionalLight(Vector3 dir) {
    setColor(1, 1, 1, 1);
    setDirection(dir);
}
DirectionalLight::DirectionalLight(Vector3 dir, Color col) {
    setColor(col);
    setDirection(dir);
}

/* getters */

Vector3 DirectionalLight::getDirection() {return direction; }

/* setters */

bool DirectionalLight::setDirection(Vector3 dir) {
    direction = dir.makeUnitVector();
    return true;
}
bool DirectionalLight::setDirection(double X, double Y, double Z) {
    Vector3 dir(X, Y, Z);
    if (setDirection(dir))
        return true;

    return false;
}

/* class methods */

float DirectionalLight::getIntensity(Vector3 hitPos, Object obj) {
    float intensity =  -(direction * obj.getNormal(hitPos));
    return intensity;
}

/* P O I N T   L I G H T */

/* constructors */

PointLight::PointLight() {
    setColor(1, 1, 1, 1);
    setLocation(0, 0, 0);
}
PointLight::PointLight(Color col) {
    setColor(col);
    setLocation(0, 0, 0);
}
PointLight::PointLight(Vector3 loc) {
    setColor(1, 1, 1, 1);
    setLocation(loc);
}
PointLight::PointLight(Vector3 loc, Color col) {
    setColor(col);
    setLocation(loc);
}

/* getters */

Vector3 PointLight::getLocation() { return location; }

/* setters */

bool PointLight::setLocation(Vector3 loc) {
    location = loc.makeUnitVector();
    return true;
}

bool PointLight::setLocation(double X, double Y, double Z) {
    Vector3 loc(X, Y, Z);
    if (setLocation(loc))
        return true;

    return false;
}
