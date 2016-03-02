IDIR=include
CC=g++
CFLAGS=-Wall -I$(IDIR) -g
SDIR=src
OUT=main

_SRC=main.cc Vector3.cpp Ray3.cpp Color.cpp Canvas.cpp EasyBMP.cpp
SRC=$(patsubst %,$(SDIR)/%,$(_SRC))

all: 
	$(CC) $(SRC) $(CFLAGS) -o $(OUT)
