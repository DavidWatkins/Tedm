XX=g++

CXXFLAGS=--std=c++11

OBJS=game.o player.o environment.o event.o

default: main

main: $(OBJS)
	$(CXX) $(CXXFLAGS) -o main $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $*.cpp

clean:
	rm -f *.o main 

all: clean default

valgrind : main
		valgrind -v --num-callers=20 --leak-check=yes --leak-resolution=high --show-reachable=yes ./main

