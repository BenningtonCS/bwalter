#include <Objects.h>

/* getters */

Color Object::getColor() const { return material.getColor(); }
Material Object::getMaterial() const { return material; }
Matrix4 Object::getTransformMatrix() const { return transformMatrix; }
Matrix4 Object::getInverseMatrix() const { return inverseMatrix; }

/* setters */

bool Object::setColor() {
    Color c(1, 1, 1, 1);
    if (setColor(c))
        return true;

    return false;
}

bool Object::setColor(const float r, const float g, const float b,
                      const float a) {
    Color c(r, g, b, a);
    if (setColor(c))
        return true;

    return false;
}

bool Object::setColor(const Color& col) {
    if (material.setColor(col))
        return true;

    return false;
}

bool Object::setMaterial(const Material& mat) {
    material = mat;
    return true;
}


/* class methods */

double Object::rayHitPosition(const Ray3& ray) const { return -1; }
Vector3 Object::getNormal(const Vector3& hitPos) const {
    Vector3 empty(0, 0, 0);
    return empty;
}

void Object::rotatex(const float deg) {
    transformMatrix = transformMatrix.getRotationX(deg)*transformMatrix;
    inverseMatrix = inverseMatrix*transformMatrix.getRotationX(-deg);
}

void Object::rotatey(const float deg) {
    transformMatrix = transformMatrix.getRotationY(deg)*transformMatrix;
    inverseMatrix = inverseMatrix*transformMatrix.getRotationY(-deg);
}

void Object::rotatez(const float deg) {
    transformMatrix = transformMatrix.getRotationZ(deg)*transformMatrix;
    inverseMatrix = inverseMatrix*transformMatrix.getRotationZ(-deg);
}


void Object::scale(const Vector3& v) {
    transformMatrix = transformMatrix.getScaleBy(v)*transformMatrix;
    inverseMatrix = inverseMatrix*transformMatrix.getScaleBy(v*-1);
}

void Object::translate(const Vector3& v) {
    transformMatrix = transformMatrix.getTranslateBy(v)*transformMatrix;
    inverseMatrix = inverseMatrix*transformMatrix.getTranslateBy(v*-1);
}


void Object::scale(const double x, const double y, const double z) {
    Vector3 v(x, y, z);
    scale(v);
}

void Object::translate(const double x, const double y, const double z) {
    Vector3 v(x, y, z);
    translate(v);
}
