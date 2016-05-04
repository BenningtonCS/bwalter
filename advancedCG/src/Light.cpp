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

float Light::getDiffuseIntensity(const Vector3& hitPos,
                                 const Object& obj) const {
    return 1;
}

float Light::getSpecularIntensity(const Vector3& hitPos,
                                  const Object& obj,
                                  const Vector3& lightDir,
                                  const Ray3& camDir) const {

    Vector3 objNormal = obj.getNormal(hitPos);
    Vector3 reflection(lightDir + objNormal*2*(lightDir*-1 * objNormal));

    printf("%.2f\t", reflection * (camDir.getDirection()*-1));

    return pow((reflection.normalize() * (camDir.getDirection()*-1)),
                obj.getMaterial().getRoughness());
}

Vector3 Light::getDirection() const {
    Vector3 v; return v;
}

Vector3 Light::getDirection(const Vector3&) const {
    Vector3 v; return v;
}
