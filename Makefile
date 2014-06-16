all: generator clean

basic.o: Headers/basic.hh Headers/basic.cc
	g++ -c Headers/basic.cc

generate.o: Headers/generate.hh Headers/generate.cc
	g++ -c Headers/generate.cc

main.o: main.cc
	g++ -c main.cc

generator: basic.o generate.o main.o
	g++ basic.o generate.o main.o -o generator -lSDL -lSDL_image -lSDL_ttf

clean:
	rm -rf *.o
