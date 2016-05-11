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

    double closestT = std::numeric_limits<double>::max();
    Object* closestObj;

    // move through every object in the scene and check if the ray hits it
    for (unsigned int i=0; i<objs.size(); i++) {

        double t = objs[i]->rayHitPosition(ray);

        // find the closest object
        if (t < closestT && t >= 0) {
            closestT = t;
            closestObj = objs[i];
        }
    }

    // if an object has been hit by the ray, move through the lights in the
    // scene and add them up
    if (closestT < std::numeric_limits<double>::max()) {
        Vector3 hitPos = ray.rayAtT(closestT);

        float diffuse = 1 - closestObj->getMaterial().getAmbient()
                          - closestObj->getMaterial().getSpecular();

        for (unsigned int j=0; j<lights.size(); j++) {

            // check if object is in shadow
            Vector3 shadowOrigin = hitPos;
            Vector3 shadowDirection = lights[j]->getDirection(hitPos) * -1;
            Ray3 shadowRay(shadowOrigin, shadowDirection);

            double t = -1;
            bool isInShadow = false;
            for (unsigned int i=0; i<objs.size(); i++) {
                t = objs[i]->rayHitPosition(shadowRay);
                if (t > 1 && t < shadowDirection.getMagnitude()) {
                    isInShadow = true;
                }
            }

            if (isInShadow) continue;

            // get the intensity of the light on the object
            float intensity = lights[j]->getDiffuseIntensity(hitPos,
                                                             *closestObj);

            float specIntensity = lights[j]->getSpecularIntensity(hitPos,
                                *closestObj, lights[j]->getDirection(hitPos), ray);

            Color newColor(color + closestObj->getColor() *
                           lights[j]->getColor() *
                           (diffuse * intensity + specIntensity *
                            closestObj->getMaterial().getSpecular()));
            color.setColor(newColor);

        }

        // get the color of the object at that point with lights
        float ambient = closestObj->getMaterial().getAmbient();
        Color newColor(color + closestObj->getColor() * ambient);
        color.setColor(newColor);

        return color;
    }

    return background;
}
