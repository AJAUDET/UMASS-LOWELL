CC = g++
CFLAGS := --std=c++20 -Wall -Werror -pedantic -g
SFML_LIB := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
TEST_LIB = -lboost_unit_test_framework

BUILD_DIR := build

SRC := $(wildcard *.cpp)
OBJ := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRC))

LIB_OBJ := $(filter-out $(BUILD_DIR)/main.o $(BUILD_DIR)/test.o, $(OBJ))

PROGRAM := Sokoban
TEST := Test
LIBRARY := Sokoban.a

.PHONY: all clean

all: $(PROGRAM) $(TEST)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBRARY): $(LIB_OBJ)
	ar rcs $@ $^

$(PROGRAM): $(LIBRARY) $(BUILD_DIR)/main.o
	$(CC) $(CFLAGS) -o $@ $(BUILD_DIR)/main.o $(LIBRARY) $(SFML_LIB)

$(TEST): $(LIBRARY) $(BUILD_DIR)/test.o
	$(CC) $(CFLAGS) -o $@ $(BUILD_DIR)/test.o $(LIBRARY) $(SFML_LIB) $(TEST_LIB)

clean:
	rm -rf $(BUILD_DIR) $(PROGRAM) $(TEST) $(LIBRARY)

lint:
	cpplint *.cpp *.hpp