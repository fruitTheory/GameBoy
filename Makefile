CC = g++
BIN = ./bin/
SRC = ./src/
INC = -I./inc/ -I./inc/raylib/
FLAG = -std=c++20 -Wall -Wextra -Wpedantic -Wconversion
BUILD = ./build/
LIBRARY = -L./lib/
LIBS = -lraylibdll

SOURCES = cartridge.cpp cpu.cpp utility.cpp memory.cpp \
instructions.cpp ppu.cpp GBWindow.cpp

OBJECTS = $(SOURCES:%.cpp=$(BUILD)%.o)

all: directories main

main: $(OBJECTS)
	$(CC) $(FLAG) $(OBJECTS) $(INC) $(SRC)main.cpp $(LIBRARY) $(LIBS) -o $(BIN)main
	$(MAKE) run 

$(BUILD)%.o: $(SRC)%.cpp
	$(CC) $(FLAG) $(INC) -c $< -o $@ 

.PHONY: run clean directories

directories:
	if [ ! -d bin ]; then mkdir bin; fi
	if [ ! -d build ]; then mkdir build; fi

run:
	$(BIN)main ./bin/tileset.gb

clean:
	rm $(BUILD)*.o
	rm $(BIN)*.exe

