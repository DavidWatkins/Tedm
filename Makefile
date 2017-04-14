CXX=g++

CXXFLAGS=--std=c++17 -g

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	CXXFLAGS += -I/usr/local/include -L/usr/local/lib
endif

LIBS=-lSDL2main -lSDL2 -lSDL2_image

OBJS=graphics.o environment.o player.o sprite.o game.o 
EXES=pong.o #sample_render.o#test01.o

default: main

main: $(OBJS) $(EXES)
	$(CXX) $(CXXFLAGS) -o pong $(OBJS) pong.o $(LIBS)
#	$(CXX) $(CXXFLAGS) -o sample_render sample_render.o $(LIBS)
#	$(CXX) $(CXXFLAGS) -o test01 $(OBJS) test01.o $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $*.cpp $(LIBS)

clean:
	rm -f *.o pong 

all: clean default

valgrind : main
	valgrind --leak-check=full --track-origins=yes ./pong
#	valgrind -v --num-callers=20 --leak-check=yes --leak-resolution=high --show-reachable=yes ./main

