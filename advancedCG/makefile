IDIR=include
CC=g++
CFLAGS=-Wall -I$(IDIR) -g
SDIR=src
OUT=main

_SRC=main.cc Color.cpp Vector3.cpp Canvas.cpp EasyBMP.cpp
SRC=$(patsubst %,$(SDIR)/%,$(_SRC))

all: 
	$(CC) $(SRC) $(CFLAGS) -o $(OUT)
