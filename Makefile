INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj
EXEC_DIR = demos
BIN_DIR = bin
UNAME_S := $(shell uname -s)
LIBS=
ifeq ($(UNAME_S),Darwin)
	INC_DIR += -I/usr/local/include
	LIBS+= -L/usr/local/lib
endif
LIBS+= -lSDL2main -lSDL2 -lSDL2_image

CXX=graphics++
RM=rm -f
CXXFLAGS=--std=c++1z -O2 -I$(INC_DIR)
DEBUG_FLAGS=-O0 -std=c++1z -g3 -I$(INC_DIR)

EXECS=pong anakin_side

SRCS=$(wildcard $(SRC_DIR)/*.cpp)

OBJS=$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o,$(SRCS))

EXECS_SRCS=$(wildcard $(EXEC_DIR)/*.cpp)
EXECS_OBJS=$(patsubst $(EXEC_DIR)/%.cpp, $(EXEC_DIR)/%.o,$(EXECS_SRCS))
BINS=$(wildcard $(BIN_DIR)/*)


DEPS = $(SRCS)# $(LIBS)

$(EXEC_DIR)/%.o: $(EXEC_DIR)/%.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

pong: $(OBJS) $(EXECS_OBJS)
	$(CXX) $(CXXFLAGS) -o $(BIN_DIR)/pong $(OBJS) $(EXEC_DIR)/pong.o $(LIBS)

anakin_side: $(OBJS) $(EXECS_OBJS)
	$(CXX) $(CXXFLAGS) -o $(BIN_DIR)/anakin_side $(OBJS) $(EXEC_DIR)/anakin_side.o $(LIBS)

default: anakin_side pong

all: clean default

clean:
	$(RM) $(OBJS)
	$(RM) $(DEBUG_OBJS)
	$(RM) $(EXECS)
	$(RM) $(EXECS_OBJS)
	$(RM) $(BINS)
