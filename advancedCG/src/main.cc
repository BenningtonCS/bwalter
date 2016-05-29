#include <Camera.h>
#include <Canvas.h>
#include <Color.h>
#include <Objects.h>
#include <Ray3.h>
#include <Scene.h>
#include <Vector3.h>
#include <Matrix4.h>


int main(void) {

    Color red(1, 0, 0, 1);
    Color yellow(1, 1, 0, 1);
    Color green(0, 1, 0, 1);
    Color blue(0, 0, 1, 1);
    Color white(1, 1, 1, 1);

    Sphere sphere1(200, 50, 0, 100);
    Sphere sphere2(-170, -20, 200, 50, blue);

    Material mat;
    mat.setAmbient(0);
    mat.setRoughness(.2);
    mat.setSpecular(.6);
    mat.setColor(red);
    mat.setReflection(.2);
    sphere1.setMaterial(mat);

    Material mat2;
    mat2.setColor(blue);
    mat2.setReflection(.2);
    sphere2.setMaterial(mat2);

    Box box;
    box.setMin(-300, -90, -200);
    box.setMax(-200, 100, -50);
    box.setColor(green);

    box.rotatex(45);

    Plane plane(0, 1, 0, 0, -100, 0, white);
    Disk disk(-1, -1, -1, 150, -50, 10, 50, green);

//    Vector3 dir(200, -500, -100);
    Vector3 dir(80, 200, -150);
//    DirectionalLight light(dir);
    PointLight light(dir);
    Vector3 dir2(-80, 100, -150);
    PointLight light2(dir2);

//    light.setColor(green);

//    OrthographicCam cam;
    PerspectiveCam cam;
    cam.setLocation(0, 0, -10);
//    cam.setSampling(4, 1);

    Scene scene(cam);
    scene.addObject(&sphere1);
    scene.addObject(&sphere2);
    scene.addObject(&plane);
    scene.addObject(&box);
//    scene.addObject(&disk);
    scene.addLight(&light);
    scene.addLight(&light2);

    cam.render(scene, "scene.bmp");

    box.getTransformMatrix().printMatrix();
}
