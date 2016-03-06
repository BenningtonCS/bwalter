IDIR=include
CC=g++
CFLAGS=-Wall -I$(IDIR) -g
SDIR=src
OUT=main

_SRC=main.cc Camera.cpp Canvas.cpp Color.cpp EasyBMP.cpp Objects.cpp Ray3.cpp Scene.cpp Vector3.cpp 
SRC=$(patsubst %,$(SDIR)/%,$(_SRC))

all: 
	$(CC) $(SRC) $(CFLAGS) -o $(OUT)
