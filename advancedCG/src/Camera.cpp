#include <Camera.h>
#include <Scene.h>

Camera::Camera() {
    setLocation(0, 0, -10);
    setLookAt(0, 0, 0);
    setPixelSize(0.01);
}

Camera::Camera(Vector3 loc, Vector3 look) {
    setLocation(loc);
    setLookAt(look);
    setPixelSize(0.01);
}

Vector3 Camera::getLocation() { return location; }
Vector3 Camera::getLookAt() { return lookAt; }
Canvas Camera::getCanvas() { return canvas; }
float Camera::getPixelSize() { return pixelSize; }

bool Camera::setLocation(Vector3 loc) {
    location = loc;
    return true;
}

bool Camera::setLocation(double X, double Y, double Z) {
    if (location.setx(X) && location.sety(Y) && location.setz(Z))
        return true;

    return false;
}

bool Camera::setLookAt(Vector3 look) {
    lookAt = look;
    return true;
}

bool Camera::setLookAt(double X, double Y, double Z) {
    if (lookAt.setx(X) && lookAt.sety(Y) && lookAt.setz(Z))
        return true;

    return false;
}

bool Camera::setCanvas(int width, int height) {
    if (canvas.setSize(width, height))
        return true;

    return false;
}

bool Camera::setPixelSize(float size) {
    if (size > 0) {
        pixelSize = size;
        return true;
    }

    return false;
}

void Camera::render(Scene scene, char* fileName) {

    int width = canvas.getWidth();
    int height = canvas.getHeight();

    Vector3 origin(0, 0, 0);
    Vector3 direction(0, 0, 1);
    Ray3 ray(origin, direction);

    Color red(1, 0, 0, 1);
    Color black(0, 0, 0, 1);

    for (float x = 0; x < width; x++) {
        for (float y = 0; y < height; y++) {
            origin.setVector(x + pixelSize/2, y + pixelSize/2, 0);
            ray.setOrigin(origin);

            if (scene.sendRay(ray)) {
                canvas.setPixel(x, y, red);
            } else {
                canvas.setPixel(x, y, black);
            }
        }
    }

    canvas.writeToFile(fileName);

}
