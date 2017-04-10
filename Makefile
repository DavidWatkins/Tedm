CXX=g++

CXXFLAGS=--std=c++11

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	CXXFLAGS += -I/usr/local/include -L/usr/local/lib
endif

LIBS=-lSDL2main -lSDL2 -lSDL2_image

OBJS=graphics.o pong.o environment.o player_base.o sprite_base.o game.o

default: main

main: $(OBJS)
	$(CXX) $(CXXFLAGS) -o pong $(OBJS) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $*.cpp $(LIBS)

clean:
	rm -f *.o pong 

all: clean default

valgrind : main
		valgrind -v --num-callers=20 --leak-check=yes --leak-resolution=high --show-reachable=yes ./main

