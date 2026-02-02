CXX = g++
CXXFLAGS = -std=c++17 -Wall -Werror -pedantic
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system
BOOST_LIBS = -lboost_unit_test_framework

PROJECT = SpriteBuilder
TEST = test
LIB = SpriteBuilder.a

all: $(PROJECT) $(TEST) $(LIB)

$(LIB): SpriteSheet.o
	ar rcs $(LIB) SpriteSheet.o 

$(PROJECT): SpriteBuilder.o $(LIB)
	$(CXX) $(CXXFLAGS) -o $(PROJECT) $(LIB) SpriteBuilder.o $(SFML_LIBS)

$(TEST): test.o $(LIB)
	$(CXX) $(CXXFLAGS) -o $(TEST) test.o $(LIB) $(SFML_LIBS) $(BOOST_LIBS)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(PROJECT) $(LIB) $(TEST)