#include <Lights.h>

/* L I G H T */

/* protected */

bool Light::setColor() {
    setColor(1, 1, 1, 1); return true;
}


/* getters */

Color Light::getColor() const { return color; }


/* setters */

bool Light::setColor(const Color& col) { color = col; return true; }

bool Light::setColor(const float r, const float g, const float b) {
    Color col(r, g, b);
    color = col;
    return true;
}

bool Light::setColor(const float r, const float g, const float b,
                     const float a) {
    Color col(r, g, b, a);
    color = col;
    return true;
}

float Light::getIntensity(const Vector3& hitPos, const Object& obj) const {
    return 1;
}


/* D I R E C T I O N A L   L I G H T */

/* constructors */

DirectionalLight::DirectionalLight() {
    setColor(); setDirection();
}

DirectionalLight::DirectionalLight(const Color& col) {
    setColor(col); setDirection();
}

DirectionalLight::DirectionalLight(const Vector3& dir) {
    setColor(); setDirection(dir);
}

DirectionalLight::DirectionalLight(const Vector3& dir, const Color& col) {
    setColor(col); setDirection(dir);
}


/* private */

bool DirectionalLight::setDirection() {
    setDirection(1, -1, 1); return true;
}


/* getters */

Vector3 DirectionalLight::getDirection() const {return direction; }

/* setters */

bool DirectionalLight::setDirection(const Vector3& dir) {
    direction = dir.makeUnitVector();
    return true;
}
bool DirectionalLight::setDirection(const double X, const double Y,
                                    const double Z) {
    Vector3 dir(X, Y, Z);
    if (setDirection(dir))
        return true;

    return false;
}

/* class methods */

float DirectionalLight::getIntensity(const Vector3& hitPos,
                                     const Object& obj) const {
    float intensity =  -(direction * obj.getNormal(hitPos));
    return intensity;
}

/* P O I N T   L I G H T */

/* protected */

bool PointLight::setLocation() {
    setLocation(0, 0, 0); return true;
}

/* constructors */

PointLight::PointLight() {
    setColor(); setLocation();
}
PointLight::PointLight(const Color& col) {
    setColor(col); setLocation();
}
PointLight::PointLight(const Vector3& loc) {
    setColor(); setLocation(loc);
}
PointLight::PointLight(const Vector3& loc, const Color& col) {
    setColor(col); setLocation(loc);
}

/* getters */

Vector3 PointLight::getLocation() const { return location; }

/* setters */

bool PointLight::setLocation(const Vector3& loc) {
    location = loc.makeUnitVector();
    return true;
}

bool PointLight::setLocation(const double X, const double Y, const double Z) {
    Vector3 loc(X, Y, Z);
    if (setLocation(loc))
        return true;

    return false;
}
