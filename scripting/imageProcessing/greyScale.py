from PIL import Image

img = Image.open("mars.jpg")

width = img.size[0]
height = img.size[1]

newImg = Image.new("F", (width, height))

def convertPixel(rgb):
	return rgb[0]*0.2126 + rgb[1]*0.7152 + rgb[2]*0.0722

for w in range(0, width):
	for h in range (0, height):
		val = convertPixel(img.getpixel((w,h)))
		newImg.putpixel((w,h), val)

newImg.show()
