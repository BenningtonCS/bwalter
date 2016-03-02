#include <Canvas.h>
#include <Vector3.h>
#include <Ray3.h>
#include <Sphere.h>

int main(void) {
    // testing for image writing
		int width = 800;
		int height = 600;

		Canvas c(width, height);
		Color red(1, 0, 0, 1);
		Color green(0, 1, 0, 1);
		Color blue(0, 0, 1, 1);

		for (int x=0; x<width; x++) {
			for (int y=0; y<height; y++) {
				//if (x == y) c.setPixel(x, y, red);
        //else c.setPixel(x, y, blue);
        Color gradient(0, 1-(float)x/width, 0+(float)x/width, 1);
        c.setPixel(x, y, gradient);
			}
		}
		c.writeToFile("output.bmp");

    // testing vectors and rays
		Ray3 ray(0, 0, 0, 10, 5, 2);
    ray.printRay();

    Sphere sphere(1, 1, 1, 1);
    sphere.getCenter().printVector();
}
