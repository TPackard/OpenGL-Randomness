MAKEFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
CUR_DIR := $(notdir $(patsubst %/,%,$(dir $(MAKEFILE_PATH))))

OBJS = src/glfw_callbacks.cpp src/base.cpp src/main.cpp

CC = g++

INCLUDE_PATHS = -I$(CUR_DIR)/res/include -I/usr/local/include
LIBRARY_PATHS = -L$(CUR_DIR)/res/lib -L/usr/local/lib

COMPILER_FLAGS = -w

LINKER_FLAGS = -framework Cocoa -framework IOKit -framework CoreVideo -framework OpenGL -lglfw3

OBJ_NAME = bin/OpenGl_Randomness

all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
