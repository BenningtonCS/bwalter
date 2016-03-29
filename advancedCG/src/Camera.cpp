#include <Camera.h>
#include <Scene.h>


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

void Camera::render(const Scene&, const char*) {}


/* O R T H O G R A P H I C   C A M E R A */

OrthographicCam::OrthographicCam() {
    setLocation(0, 0, -10);
    setLookAt(0, 0, 0);
    setPixelSize(0.01);
}

OrthographicCam::OrthographicCam(const Vector3& loc, const Vector3& look) {
    setLocation(loc);
    setLookAt(look);
    setPixelSize(0.01);
}

OrthographicCam::OrthographicCam(
            const double x1, const double y1, const double z1,   // location
            const double x2, const double y2, const double z2) { // lookat
    setLocation(x1, y1, z1);
    setLookAt(x2, y2, z2);
    setPixelSize(0.01);
}

void OrthographicCam::render(const Scene& scene, const char* fileName) {

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


/* P E R S P E C T I V E   C A M E R A */

PerspectiveCam::PerspectiveCam() {
    setLocation(0, 0, -10);
    setLookAt(0, 0, 0);
    setPixelSize(0.01);
    setFOV(60);
}

PerspectiveCam::PerspectiveCam(const Vector3& loc, const Vector3& look,
                               const double fov) {
    setLocation(loc);
    setLookAt(look);
    setPixelSize(0.01);
    setFOV(fov);
}

PerspectiveCam::PerspectiveCam(
            const double x1, const double y1, const double z1,   // location
            const double x2, const double y2, const double z2,   // lookat
            const double fov) {                                 // distnace
    setLocation(x1, y1, z1);
    setLookAt(x2, y2, z2);
    setPixelSize(0.01);
    setFOV(fov);
}


double PerspectiveCam::getFOV() const { return FOV; }
double PerspectiveCam::getDistance() const {
    return ((canvas.getHeight()/2)/tan((FOV/2) * M_PI / 180));
}


bool PerspectiveCam::setFOV(const double fov) {
    if (0 < fov && fov < 90) {
        FOV = fov; return true;
    }
    return false;
}

void PerspectiveCam::render(const Scene& scene, const char* fileName) {
    int width = canvas.getWidth();
    int height = canvas.getHeight();

    Vector3 origin(0, 0, -getDistance());
    Vector3 direction(0, 0, 1);
    Ray3 ray(origin, direction);

    // move through the scene starting from the upper left to the lower right
    // left of the center of the image has -x coordinates and right has +x
    // below the center of the image has -y coordinates, above has +y
    for (float x = -width/2; x < width/2; x++) {
        for (float y = -height/2; y < height/2; y++) {

            Vector3 pixelLocation(x + pixelSize/2, -y - pixelSize/2, 0);

            direction = (pixelLocation - origin).normalize();
            ray.setDirection(direction);

            Color color = scene.sendRay(ray);

            // set pixel colors, changing the upper left corner to have (x, y)
            // coordinates of (0, 0) rather than the center
            canvas.setPixel(x + width/2, y + height/2, color);
        }
    }

    canvas.writeToFile(fileName);
}
