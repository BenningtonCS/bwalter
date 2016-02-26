IDIR=include
CC=g++
CFLAGS=-Wall -I$(IDIR)
SDIR=src
OUT=main

_SRC=main.cc Image.cpp Color.cpp Vector3.cpp Canvas.cpp
SRC=$(patsubst %,$(SDIR)/%,$(_SRC))

all: 
	$(CC) $(SRC) $(CFLAGS) -o $(OUT)
