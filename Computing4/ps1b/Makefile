CXX = g++
CXXFLAGS = -std=c++17 -Wall -Werror -pedantic
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system
BOOST_LIBS = -lboost_unit_test_framework-mt

PROJECT = SpriteBuilder
TEST = test
LIB = SpriteBuilder.a

OBJS = SpriteSheet.o SpriteBuilder.o

all: $(PROJECT) $(TEST) $(LIB)

$(LIB): $(OBJS)
	ar rcs $(LIB) $(OBJS)

$(PROJECT): $(LIB)
	$(CXX) $(CXXFLAGS) -o $(PROJECT) $(LIB) $(SFML_LIBS)

$(TEST): test.o $(LIB)
	$(CXX) $(CXXFLAGS) -o $(TEST) test.o $(LIB) $(SFML_LIBS) $(BOOST_LIBS)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(PROJECT) $(LIB) $(TEST)