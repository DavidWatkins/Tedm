XX=g++

CXXFLAGS=--std=c++11

LIBS=-lSDL2main -lSDL2

OBJS=graphics.o test01.o environment.o #game.o player.o event.o

default: main

main: $(OBJS)
	$(CXX) $(CXXFLAGS) -o main $(OBJS) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $*.cpp $(LIBS)

clean:
	rm -f *.o main 

all: clean default

valgrind : main
		valgrind -v --num-callers=20 --leak-check=yes --leak-resolution=high --show-reachable=yes ./main

