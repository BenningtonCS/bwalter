#include <Camera.h>
#include <Canvas.h>
#include <Color.h>
#include <Objects.h>
#include <Ray3.h>
#include <Scene.h>
#include <Vector3.h>

int main(void) {

    Color color1(1, 0, 0, 1);
    Sphere sphere1(200, 300, 100, 100, color1);

    Color color2(0, 0, 1, 1);
    Sphere sphere2(200, 400, 10, 50, color2);

    Camera cam;

    Scene scene(cam);
    scene.addObject(&sphere1);
    scene.addObject(&sphere2);

    cam.render(scene, (char*)"sphere.bmp");
}
