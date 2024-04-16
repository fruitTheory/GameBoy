CC = g++
BIN = ./bin/
SRC = ./src/
INC = ./inc/
FLAG = -std=c++17 -Wall -Wextra -Wpedantic -Wconversion
BUILD = ./build/

SOURCES = cartridge.cpp cpu.cpp utility.cpp
OBJECTS = $(SOURCES:%.cpp=$(BUILD)%.o)

all: directories main

main: $(OBJECTS)
	$(CC) $(FLAG) $(OBJECTS) -I$(INC) $(SRC)main.cpp -o $(BIN)main
	$(MAKE) run 

$(BUILD)%.o: $(SRC)%.cpp
	$(CC) $(FLAG) -I$(INC) -c $< -o $@ 

directories:
	if [ ! -d bin ]; then mkdir bin; fi
	if [ ! -d build ]; then mkdir build; fi

.PHONY: run clean

run:
	$(BIN)main ./bin/tiles.gb

clean:
	rm $(BUILD)*.o
	rm $(BIN)*.exe

