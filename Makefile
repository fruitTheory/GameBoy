CC = g++
BIN = ./bin/
SRC = ./src/
INC = ./inc/
FLAG = -Wall -Wextra -std=c++17
BUILD = ./build/
OBJ = cpu.o

main: $(OBJ)
	$(CC) $(FLAG) $(BUILD)$(OBJ) -I$(INC) $(SRC)main.cpp -o $(BIN)main
	$(MAKE) run

cpu.o: $(SRC)cpu.cpp $(INC)cpu.hpp
	if [ ! -d bin ]; then mkdir bin; fi
	if [ ! -d build ]; then mkdir build; fi
	$(CC) -I$(INC) -c $(SRC)cpu.cpp -o $(BUILD)cpu.o

run:
	$(BIN)main

clean:
	rm $(BUILD)*.o
	rm $(BIN)*.exe

