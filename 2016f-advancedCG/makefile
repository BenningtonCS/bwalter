IDIR=include
CC=g++
CFLAGS=-Wall -I$(IDIR) -D_USE_MATH_DEFINES -std=c++11
SDIR=src
OUT=main

_SRC=main.cc Camera.cpp Canvas.cpp Color.cpp EasyBMP.cpp Light.cpp DirectionalLight.cpp PointLight.cpp Material.cpp Matrix4.cpp Object.cpp Sphere.cpp Plane.cpp Disk.cpp Box.cpp Ray3.cpp Scene.cpp Vector3.cpp
SRC=$(patsubst %,$(SDIR)/%,$(_SRC))

all:
	$(CC) $(SRC) $(CFLAGS) -o $(OUT)

debug:
	$(CC) $(SRC) $(CFLAGS) -g -o $(OUT)
