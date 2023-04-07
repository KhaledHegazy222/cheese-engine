CC = g++
CFLAGS = -std=c++11 -Wall -Iinclude

LDFLAGS = -Llibs
ifeq ($(shell uname), Windows_NT)
    # Link against mingw32 library on Windows
    LDFLAGS += -lmingw32
endif
 LDFLAGS += -lSDL2main -lSDL2

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

SRC_FILES = $(wildcard $(SRC_DIR)/**/*.cpp) $(wildcard $(SRC_DIR)/*.cpp) 
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
BIN_NAME = cheeseEngine.exe

.PHONY: all clean

all: $(BIN_DIR)/$(BIN_NAME)

$(BIN_DIR)/$(BIN_NAME): $(OBJ_FILES)
	$(CC) $^ $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_FILES) $(BIN_DIR)/$(BIN_NAME)
