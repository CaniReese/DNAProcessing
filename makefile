CC = g++
CFLAGS = -std=c++17 -Iinclude

SRC_DIR = src
INC_DIR = include
OBJ_DIR = lib
BIN_DIR = bin

TARGET = $(BIN_DIR)/DNAProcessing

SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/LinkedList.cpp $(SRC_DIR)/Population.cpp
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/LinkedList.o $(OBJ_DIR)/Population.o

all: $(TARGET)

$(TARGET): $(OBJS)
	if not exist $(BIN_DIR) mkdir $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	if exist $(OBJ_DIR) rmdir /S /Q $(OBJ_DIR)
	if exist $(BIN_DIR) rmdir /S /Q $(BIN_DIR)

rebuild: clean all