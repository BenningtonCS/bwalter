#include <Image.h>
#include <Canvas.h>

int main(void) {

	//declare image
	short width = 256;
	short height = 256;
	TGAImage *img = new TGAImage(width,height);

	//declare a temporary color variable
	Colour c;

	//Loop through image and set all pixels to red
	for(int x=0; x<width; x++)
		for(int y=0; y<width; y++)
		{
			c.r = 255;
			c.g = 0;
			c.b = 0;
			c.a = 255;
			img->setPixel(c,x,y);
		}

	//write the image to disk
	string filename = "test.tga";
	img->WriteImage(filename);


}
