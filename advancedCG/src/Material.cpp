#include <Materials.h>


/* constructors */

Material::Material() { setAmbient(0); }
Material::Material(const float amb) { setAmbient(amb); }


/* getters */

float Material::getAmbient() const { return ambient; }


/* setters */

bool Material::setAmbient(const float amb) {
    if (0 <= amb && amb <= 1) {
        ambient = amb;
        return true;
    }
    return false;
}
