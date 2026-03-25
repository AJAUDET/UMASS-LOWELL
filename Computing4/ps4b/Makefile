CXX = g++
CXXFLAGS = -std=c++20 -Wall -Werror -pedantic
SFML_LIBS = -L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
SFML_INCLUDE = -I/usr/local/include

TARGET = AniPlayer
LIBRARY = AniPlayer.a
LIB_OBJS = AniPlayer.o Component.o KeyFrame.o
MAIN_OBJ = main.o

all: $(TARGET)

$(TARGET): $(MAIN_OBJ) $(LIBRARY)
	$(CXX) $(CXXFLAGS) $(MAIN_OBJ) $(LIBRARY) -o $(TARGET) $(SFML_LIBS)

$(LIBRARY): $(LIB_OBJS)
	ar rcs $@ $^

main.o: main.cpp AniPlayer.hpp Component.hpp KeyFrame.hpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) -c main.cpp

AniPlayer.o: AniPlayer.cpp AniPlayer.hpp Component.hpp KeyFrame.hpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) -c AniPlayer.cpp

Component.o: Component.cpp Component.hpp KeyFrame.hpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) -c Component.cpp

KeyFrame.o: KeyFrame.cpp KeyFrame.hpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) -c KeyFrame.cpp

clean:
	rm -f *.o $(TARGET) $(LIBRARY)