CXX = g++
CXXFLAGS = -std=c++17 -Wall
TARGET = game
SRCS = Game.cpp Character.cpp Player.cpp Enemy.cpp Weapon.cpp Potion.cpp Food.cpp Inventory.cpp Item.cpp ItemFactory.cpp Combat.cpp Map.cpp Location.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET) 
	./$(TARGET)

.PHONY: clean run