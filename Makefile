all: generator clean

basic.o: Headers/basic.hh Headers/basic.cc
	g++ -c Headers/basic.cc

main.o: main.cc
	g++ -c main.cc

generator: basic.o main.o
	g++ basic.o main.o -o generator -lSDL -lSDL_image -lSDL_ttf

clean:
	rm -rf *.o
