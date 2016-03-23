#include <Lights.h>


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