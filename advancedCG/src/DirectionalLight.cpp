#include <Lights.h>


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
    direction = dir.normalize();
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
    return -(getDirection() * obj.getNormal(hitPos));
}
