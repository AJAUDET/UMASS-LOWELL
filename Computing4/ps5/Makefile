CXX = g++
CXXFLAGS = -O3 -std=c++20 -Wall -Werror -pedantic
SFML_LIBS = -L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
SFML_INCLUDE = -I/usr/local/include

TARGET = EDistance
TEST_TARGET = test

LIBRARY = EDistance.a
LIB_OBJS = EDistance.o

MAIN_OBJ = main.o
TEST_OBJ = test.o

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(MAIN_OBJ) $(LIBRARY)
	$(CXX) $(CXXFLAGS) $(MAIN_OBJ) $(LIBRARY) -o $(TARGET) $(SFML_LIBS)

$(TEST_TARGET): $(TEST_OBJ) $(LIBRARY)
	$(CXX) $(CXXFLAGS) $(TEST_OBJ) $(LIBRARY) -o $(TEST_TARGET) $(SFML_LIBS) -lboost_unit_test_framework

$(LIBRARY): $(LIB_OBJS)
	ar rcs $@ $^

main.o: main.cpp EDistance.hpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) -c main.cpp

EDistance.o: EDistance.cpp EDistance.hpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) -c EDistance.cpp

test.o: test.cpp EDistance.hpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) -c test.cpp

clean:
	rm -f *.o $(TARGET) $(TEST_TARGET) $(LIBRARY)
