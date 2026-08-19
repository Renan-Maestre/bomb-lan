CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++17

LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRC = main.cpp Game.cpp player/player.cpp bomb/bomb.cpp menu/menu.cpp safeArea/safeArea.cpp

TARGET = Bomba

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LIBS)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)