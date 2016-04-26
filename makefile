all: main.o vector2.o tile.o grass.o tree.o
	g++ main.o vector2.o tile.o tree.o grass.o -ofast -std=c++11 -Wc++11-extensions -framework openGL -framework GLUT -Wdeprecated-declarations -framework Cocoa -o out
	rm *.o

main.o: .//src/main.cpp
	g++ .//src/main.cpp -c

vector2.o: .//src/vector2.cpp
	g++  .//src/vector2.cpp -c

tile.o: .//src/tile.cpp
	g++ .//src/tile.cpp -c

grass.o: .//src/grass.cpp
	g++ .//src/grass.cpp -c

tree.o: .//src/tree.cpp
	g++ .//src/tree.cpp -c
