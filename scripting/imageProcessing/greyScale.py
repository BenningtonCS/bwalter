#!/usr/bin/python3

'''
	greyScale.py
	2015 October 22
	Brendon Walter

	Convert an RGB image to greyscale
'''

from PIL import Image

# open an image and get the width and height of it
img = Image.open("mars.jpg")
width = img.size[0]
height = img.size[1]

# create a new image with 32 bit floating point pixels the same size as the 
#reference image
newImg = Image.new("F", (width, height))

# convert an rgb tuple to greyscale
def convertPixel(rgb):
	# forumula found on rosettacode.org
	return rgb[0]*0.2126 + rgb[1]*0.7152 + rgb[2]*0.0722

# go through image pixel by pixel
for w in range(0, width):
	for h in range (0, height):
		# convert rgb value to grey
		val = convertPixel(img.getpixel((w,h)))
		# write pixels to new image
		newImg.putpixel((w,h), val)

# show the grey scale image
newImg.show()
