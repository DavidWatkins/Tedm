INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj
EXEC_DIR = demos

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	CXXFLAGS += -I/usr/local/include
	LIBS= -L/usr/local/lib
endif
LIBS+=-lSDL2main -lSDL2 -lSDL2_image

CXX=g++
RM=rm -f
CXXFLAGS=--std=c++1z -O2 -I$(INC_DIR)
DEBUG_FLAGS=-fconcepts -O0 -std=c++1z -g3 -I$(INC_DIR)

EXECS=pong anakin_side

SRCS=$(wildcard $(SRC_DIR)/*.cpp)

OBJS=$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o,$(SRCS))

EXECS_SRCS=$(wildcard $(EXEC_DIR)/*.cpp)
EXECS_OBJS=$(patsubst $(EXEC_DIR)/%.cpp, $(EXEC_DIR)/%.o,$(EXECS_SRCS))

DEPS = $(SRCS) $(LIBS)

$(EXEC_DIR)/%.o: $(EXEC_DIR)/%.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(LIBS)

pong: $(OBJS) $(EXECS_OBJS)
	$(CXX) $(CXXFLAGS) -o pong $(OBJS) $(EXEC_DIR)/pong.o $(LIBS)

anakin_side: $(OBJS) $(EXECS_OBJS)
	$(CXX) $(CXXFLAGS) -o anakin_side $(OBJS) $(EXEC_DIR)/anakin_side.o $(LIBS)

default: anakin_side pong

all: clean default

clean:
	$(RM) $(OBJS)
	$(RM) $(DEBUG_OBJS)
	$(RM) $(EXECS)
	$(RM) $(EXECS_OBJS)
