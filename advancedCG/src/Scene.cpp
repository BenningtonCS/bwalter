#include <stdio.h>

#include <Scene.h>

/* constructors */

Scene::Scene(const Camera& cam) {
    addCamera(cam);
    setBackground(0, 0, 0, 1);
}


/* getters */

Camera Scene::getCamera() const { return camera; }
Color Scene::getBackground() const { return background; }
std::vector<Object*> Scene::getObjects() const { return objs; }


/* setters */

bool Scene::setBackground(const Color& col) {
    background = col;
    return true;
}

bool Scene::setBackground(const float r, const float g, const float b,
                          const float a) {
    Color col(r, g, b, a);
    background = col;
    return true;
}

bool Scene::addCamera(const Camera& cam) { camera = cam; return true; }
bool Scene::addObject(Object* obj) {
    objs.push_back(obj);
    return true;
}
bool Scene::addLight(Light* l) {
    lights.push_back(l);
    return true;
}


/* class methods */

Color Scene::sendRay(const Ray3& ray) const {
    Color color(0, 0, 0, 1);

    float closestT = std::numeric_limits<float>::max();
    Object* closestObj;

    // move through every object in the scene and check if the ray hits it
    for (unsigned int i=0; i<objs.size(); i++) {

        float t = objs[i]->rayHitPosition(ray);

        // check for the closest object
        if (t < closestT && t != -1) {
            closestT = t;
            closestObj = objs[i];
        }
    }

    // if an object has been hit by the run, move through the lights in the
    // scene and add them up
    if (closestT < std::numeric_limits<float>::max()) {
        Vector3 hitPos = ray.rayAtT(closestT);

        for (unsigned int j=0; j<lights.size(); j++) {


            float intensity = lights[j]->getIntensity(hitPos, *closestObj);
            if (intensity < closestObj->getMaterial().getAmbient())
                intensity = closestObj->getMaterial().getAmbient();

            // get the color of the object at that point with lights

            // Color of object * Color of light1 * intensity of light1 at point
            // + Color of object * Color of light2 * intensity of light2 at point

            float newr = color.getr() + closestObj->getColor().getr() *
                         lights[j]->getColor().getr() * intensity;
            float newg = color.getg() + closestObj->getColor().getg() *
                         lights[j]->getColor().getg() * intensity;
            float newb = color.getb() + closestObj->getColor().getb() *
                         lights[j]->getColor().getb() * intensity;

            color.setColor(newr, newg, newb, closestObj->getColor().geta());
        }

        return color;
    }

    return background;
}
