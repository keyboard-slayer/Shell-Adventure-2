OBJS = main.cpp Engine/*/*.cpp mechanics/*/*.cpp
OBJ_NAME = Shell-Adventure

CC = g++
COMPILER_FLAGS = -Wall -Wpedantic 
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -IEngine/
ALL: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

