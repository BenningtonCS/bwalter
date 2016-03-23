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
    Color color;

    float closestT = std::numeric_limits<float>::max();
    Object* closestObj;

    // move through every object in the scene and check if the ray hits it
    for (unsigned int i=0; i<objs.size(); i++) {

        float t = objs[i]->rayHitPosition(ray);

        // if it does, move through every light in the scene and check the
        // intensity of the light
        if (t < closestT && t != -1) {

            closestT = t;
            closestObj = objs[i];
        }
    }

    if (closestT < std::numeric_limits<float>::max()) {
        Vector3 hitPos = ray.rayAtT(closestT);

        for (unsigned int j=0; j<lights.size(); j++) {

            // TODO: actually add the lights

            float intensity = lights[j]->getIntensity(hitPos, *closestObj);
            if (intensity < closestObj->getMaterial().getAmbient())
                intensity = closestObj->getMaterial().getAmbient();

            // get the color of the object at that point with lights
            color.setColor(closestObj->getColor().getr()*intensity,
                           closestObj->getColor().getg()*intensity,
                           closestObj->getColor().getb()*intensity,
                           closestObj->getColor().geta());
        }
        return color;
    }

    return background;
}
