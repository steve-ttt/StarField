CC=g++
CFLAGS=-lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17
DEPS =  olcPixelGameEngine.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

build: star.o 
	$(CC) -o star star.o $(CFLAGS) 
