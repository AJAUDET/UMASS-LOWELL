CC = g++
CFLAGS := --std=c++20 -Wall -Werror -pedantic -g
TEST_LIB = -lboost_unit_test_framework

BUILD_DIR := build

SRC := $(wildcard *.cpp)
OBJ := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRC))

LIB_OBJ := $(filter-out $(BUILD_DIR)/TextWriter.o $(BUILD_DIR)/test.o, $(OBJ))

PROGRAM := TextWriter
TEST := test
LIBRARY := TextWriter.a

.PHONY: all clean

all: $(PROGRAM) $(TEST)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBRARY): $(LIB_OBJ)
	ar rcs $@ $^

$(PROGRAM): $(LIBRARY) $(BUILD_DIR)/TextWriter.o
	$(CC) $(CFLAGS) -o $@ $(BUILD_DIR)/TextWriter.o $(LIBRARY)

$(TEST): $(LIBRARY) $(BUILD_DIR)/test.o
	$(CC) $(CFLAGS) -o $@ $(BUILD_DIR)/test.o $(LIBRARY) $(TEST_LIB)

clean:
	rm -rf $(BUILD_DIR) $(PROGRAM) $(TEST) $(LIBRARY)

lint:
	cpplint *.cpp *.hpp