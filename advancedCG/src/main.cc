#include <Canvas.h>

int main(void) {
		int width = 600;			// works
		int height = 800;

		//int width = 800;		// doesn't work
		//int height = 600;

		Canvas c(width, height);
		Color red(1, 0, 0, 1);
		Color green(0, 1, 0, 1);
		Color blue(0, 0, 1, 1);

		for (int x=0; x<width; x++) {
			for (int y=0; y<height; y++) {
				c.setPixel(x, y, blue);
			}
		}
		c.writeToFile("output.bmp");
}
