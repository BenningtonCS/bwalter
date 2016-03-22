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
