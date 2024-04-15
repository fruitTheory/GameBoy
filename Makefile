CC = g++
BIN = ./bin/
SRC = ./src/
INC = ./inc/
FLAG = -std=c++17 -Wall -Wextra -Wpedantic -Wconversion
BUILD = ./build/
OBJ = cpu.o utility.o cartridge.o
BUILT = $(BUILD)cpu.o $(BUILD)utility.o $(BUILD)cartridge.o

main: $(OBJ)
	$(CC) $(FLAG) $(BUILT) -I$(INC) $(SRC)main.cpp -o $(BIN)main
	$(MAKE) run 

cpu.o: $(SRC)cpu.cpp $(INC)cpu.hpp
	if [ ! -d bin ]; then mkdir bin; fi
	if [ ! -d build ]; then mkdir build; fi
	$(CC) -I$(INC) -c $(SRC)cpu.cpp -o $(BUILD)cpu.o

utility.o: $(SRC)utility.cpp $(INC)utility.hpp
	$(CC) -I$(INC) -c $(SRC)utility.cpp -o $(BUILD)utility.o

cartridge.o: $(SRC)cartridge.cpp $(INC)cartridge.hpp
	$(CC) -I$(INC) -c $(SRC)cartridge.cpp -o $(BUILD)cartridge.o

run:
	$(BIN)main ./bin/test.txt

clean:
	rm $(BUILD)*.o
	rm $(BIN)*.exe

