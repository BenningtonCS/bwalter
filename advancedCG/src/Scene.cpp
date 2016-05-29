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
    return sendRay(ray, 0);
}

Color Scene::sendRay(const Ray3& ray, const int recursionDepth) const {
    Color color(0, 0, 0, 1);

    double closestT = std::numeric_limits<double>::max();
    Object* closestObj;

    // move through every object in the scene and check if the ray hits it
    for (unsigned int i=0; i<objs.size(); i++) {

        // deal with object transformation by transforming the ray hitting it
        Ray3 transformedRay = objs[i]->getInverseMatrix().transformRay(ray);
        double t = objs[i]->rayHitPosition(transformedRay);

        // find the closest object
        if (t < closestT && t >= 0) {
            closestT = t;
            closestObj = objs[i];
        }
    }

    Material closestObjMat = closestObj->getMaterial();

    // if an object has been hit by the ray, move through the lights in the
    // scene and add them up
    if (closestT < std::numeric_limits<double>::max()) {

        Vector3 hitPos = ray.rayAtT(closestT);
        float diffuseCo = 1 - closestObjMat.getAmbient()
                          - closestObjMat.getSpecular()
                          - closestObjMat.getReflection();

        for (unsigned int j=0; j<lights.size(); j++) {

            // check if object is in shadow
            Vector3 shadowDirection = lights[j]->getDirection(hitPos) * -1;
            Ray3 shadowRay(hitPos, shadowDirection);

            double t = -1;
            bool isInShadow = false;
            for (unsigned int i=0; i<objs.size(); i++) {
                t = objs[i]->rayHitPosition(shadowRay);
                if (t > 1 && t < lights[j]->getDistanceTo(hitPos)) {
                    isInShadow = true;
                }
            }

            if (isInShadow) continue;

            // get the intensity of the light on the object
            float diffuse = lights[j]->getDiffuseIntensity(hitPos,
                              *closestObj) * diffuseCo;
            float specular = lights[j]->getSpecularIntensity(hitPos,
                             *closestObj, lights[j]->getDirection(hitPos), ray)
                             * closestObjMat.getSpecular();

            Color newColor(color + closestObj->getColor() *
                           lights[j]->getColor() * (diffuse + specular));

            // get reflections
            if (recursionDepth < maxDepth) {
                if (closestObjMat.getReflection() > 0) {

                    Ray3 reflRay = lights[j]->getReflectedRay(hitPos,
                                                *closestObj, ray);

                    reflRay.setOrigin(reflRay.getOrigin() +
                                      closestObj->getNormal(hitPos) * 0.1);

                    Color reflColor = sendRay(reflRay, recursionDepth+1) *
                                              closestObjMat.getReflection() /
                                              (closestObj->getNormal(hitPos) *
                                               reflRay.getDirection());

                    newColor = newColor + reflColor;
                }
            }

            color.setColor(newColor);
        }

        // get the color of the object at that point with lights
        float ambient = closestObjMat.getAmbient();
        Color newColor(color + closestObjMat.getColor() * ambient);
        color.setColor(newColor);

        return color;
    }

    return background;
}
