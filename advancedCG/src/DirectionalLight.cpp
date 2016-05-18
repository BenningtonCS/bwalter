#include <Lights.h>


/* constructors */

DirectionalLight::DirectionalLight() {
    setColor(); setDirection(1, -1, 1);
}

DirectionalLight::DirectionalLight(const Color& col) {
    setColor(col); setDirection(1, -1, 1);
}

DirectionalLight::DirectionalLight(const Vector3& dir) {
    setColor(); setDirection(dir);
}

DirectionalLight::DirectionalLight(const Vector3& dir, const Color& col) {
    setColor(col); setDirection(dir);
}


/* getters */

Vector3 DirectionalLight::getDirection() const {return direction; }
Vector3 DirectionalLight::getDirection(const Vector3& tmp) const {
    return direction;
}

double DirectionalLight::getDistanceTo(const Vector3& point) const {
    return std::numeric_limits<double>::max();
}

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
