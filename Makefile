CXX=g++

CXXFLAGS=--std=c++14 -g 

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	CXXFLAGS += -I/usr/local/include
	LIBS= -L/usr/local/lib
endif

LIBS+=-lSDL2main -lSDL2 -lSDL2_image

OBJS=graphics.o environment.o game.o 
EXES=anakin_side.o

default: main

main: $(OBJS) $(EXES)
	$(CXX) $(CXXFLAGS) $(INCS) -o anakin_side $(OBJS) anakin_side.o $(LIBS)

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) $(INCS) -c $*.cpp

clean:
	rm -f *.o anakin_side 

all: clean default

valgrind : main
	valgrind --leak-check=full --track-origins=yes ./anakin_side

