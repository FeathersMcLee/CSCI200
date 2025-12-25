# A line starting with a has is a comment, we'll build up
# the below example

TARGET = A4
SRC_FILES = main.cpp Player.hpp Die.hpp Game.hpp

# DO NOT EDIT BELOW HERE
CXX = g++
CFLAGS = -Wall -g -std=c++11
OBJECTS = $(SRC_FILES:.cpp=.o)

ifeq ($(shell echo "Windows"), "Windows")
	TARGET := $(TARGET).exe
	DEL = del
else
	DEL = rm
endif

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

.cpp.o:
	$(CXX) $(CFLAGS) -o $@ -c $<

clean:
	$(DEL) $(TARGET) $(OBJECTS)

# DEPENDENCIES
Player.o: Player.hpp Node.hpp
Die.o: Die.hpp
Game.o: Game.hpp
linked_list_functions.o: linked_list_functions.cpp linked_list_functions.h Node.hpp
main.o: main.cpp Node.hpp
