# Project Name
PROJECT_NAME=epubreader

# Build dir
BUILD_DIR=./bin/

# src dir
SRC_DIR=./src/

# .c files
C_SOURCE=$(wildcard ./src/*.c)

# .h files
H_SOURCE=$(wildcard ./src/*.h)

# Object files
OBJ=$(subst .c,.o,$(subst src,bin,$(C_SOURCE)))

# Compiler
CC=gcc

# Compile options
CFLAGS=-Wall -Werror -ansi -pedantic

# Compilation and linking

all: $(PROJECT_NAME)

$(PROJECT_NAME): build $(OBJ)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)$@ $(OBJ)

build:
	mkdir -p $(BUILD_DIR)

./bin/%.o: ./src/%.c ./src/%.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(BUILD_DIR)

install:
	cp $(BUILD_DIR)$(PROJECT_NAME) /usr/bin

uninstall:
	rm /usr/bin/$(PROJECT_NAME)
