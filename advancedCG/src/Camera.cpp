#include <Camera.h>
#include <Scene.h>

Camera::Camera() {
    setLocation(0, 0, -10);
    setLookAt(0, 0, 0);
    setPixelSize(0.01);
}

Camera::Camera(const Vector3& loc, const Vector3& look) {
    setLocation(loc);
    setLookAt(look);
    setPixelSize(0.01);
}

Camera::Camera(const double x1, const double y1, const double z1,   // location
               const double x2, const double y2, const double z2) { // lookat
    setLocation(x1, y1, z1);
    setLookAt(x2, y2, z2);
    setPixelSize(0.01);
}

Vector3 Camera::getLocation() const { return location; }
Vector3 Camera::getLookAt() const { return lookAt; }
Canvas Camera::getCanvas() const { return canvas; }
float Camera::getPixelSize() const { return pixelSize; }

bool Camera::setLocation(const Vector3& loc) {
    location = loc;
    return true;
}

bool Camera::setLocation(const double X, const double Y, const double Z) {
    if (location.setx(X) && location.sety(Y) && location.setz(Z))
        return true;

    return false;
}

bool Camera::setLookAt(const Vector3& look) {
    lookAt = look;
    return true;
}

bool Camera::setLookAt(const double X, const double Y, const double Z) {
    if (lookAt.setx(X) && lookAt.sety(Y) && lookAt.setz(Z))
        return true;

    return false;
}

bool Camera::setCanvas(const int width, const int height) {
    if (canvas.setSize(width, height))
        return true;

    return false;
}

bool Camera::setPixelSize(const float size) {
    if (size > 0) {
        pixelSize = size;
        return true;
    }

    return false;
}

void Camera::render(const Scene& scene, const char* fileName) {

    int width = canvas.getWidth();
    int height = canvas.getHeight();

    Vector3 origin(0, 0, 0);
    Vector3 direction(0, 0, 1);
    Ray3 ray(origin, direction);

    // move through the scene starting from the upper left to the lower right
    // left of the center of the image has -x coordinates and right has +x
    // below the center of the image has -y coordinates, above has +y
    for (float x = -width/2; x < width/2; x++) {
        for (float y = -height/2; y < height/2; y++) {

            origin.setVector(x + pixelSize/2, -y - pixelSize/2, 0);
            ray.setOrigin(origin);

            Color color = scene.sendRay(ray);

            // set pixel colors, changing the upper left corner to have (x, y)
            // coordinates of (0, 0) rather than the center
            canvas.setPixel(x + width/2, y + height/2, color);
        }
    }

    canvas.writeToFile(fileName);
}
