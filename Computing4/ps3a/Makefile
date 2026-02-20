CC = g++
CFLAGS = --std=c++20 -Wall -Werror -pedantic -g -I$(INCLUDE_DIR)
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
BOOSTLIB = -lboost_unit_test_framework

# Directories for organization
SRC_DIR := src
INCLUDE_DIR := include
BUILD_DIR := build

# Wildcard build rules
DEPS := $(shell find $(INCLUDE_DIR) -name '*.hpp')
SRC := $(shell find $(SRC_DIR) -name '*.cpp')
OBJECTS := $(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
PROGRAM := Sokoban

LIBRARY = Sokoban.a

.PHONY: all clean lint


all: $(PROGRAM)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/$(LIBRARY): $(OBJECTS)
	ar rcs $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEPS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/main.o: main.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(PROGRAM): $(BUILD_DIR)/$(LIBRARY) $(BUILD_DIR)/main.o
	$(CC) $(CFLAGS) -o $@ $(BUILD_DIR)/main.o $(BUILD_DIR)/$(LIBRARY) $(LIB)

clean:
	rm -rf $(BUILD_DIR) $(PROGRAM) $(LIBRARY)

lint:
	cpplint *.cpp *.hpp