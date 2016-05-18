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

Vector3 Light::getDirection() const {
    Vector3 v; return v;
}

Vector3 Light::getDirection(const Vector3&) const {
    Vector3 v; return v;
}

double Light::getDistanceTo(const Vector3& point) const {
    return 0;
}

float Light::getDiffuseIntensity(const Vector3& hitPos,
                                 const Object& obj) const {
    float val = ((getDirection(hitPos)*-1) * obj.getNormal(hitPos));
    if (val < 0) return 0;
    if (val > 1) return 1;
    return val;
}

float Light::getSpecularIntensity(const Vector3& hitPos,
                                  const Object& obj,
                                  const Vector3& lightDir,
                                  const Ray3& camDir) const {

    Vector3 objNormal = obj.getNormal(hitPos);
    Vector3 reflection(lightDir + objNormal*2*(lightDir*-1 * objNormal));

    float base = reflection * (camDir.getDirection()*-1);
    if (base < 0) base = 0;
    if (base > 1) base = 1;
    float e = obj.getMaterial().getRoughness();
    float val = pow(base, e);

    return val;
}

Color Light::getReflectedColor(const Vector3& hitPos,
                                   const Object& obj,
                                   const Vector3& lightDir,
                                   const Ray3& camDir) const {

    Vector3 objNormal = obj.getNormal(hitPos);
    Vector3 eye = camDir.getDirection() * -1;
    Vector3 reflectedRay = eye*-1 + objNormal * (objNormal * eye) * 2;

    return obj.getMaterial().getColor() * obj.getMaterial().getReflection() /
           (objNormal * reflectedRay);

}
