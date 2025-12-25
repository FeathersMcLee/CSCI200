TARGET = CTPolymorphism
SRC_FILES = main.cpp Dog.cpp Cat.cpp Animal.cpp

# DO NOT EDIT BELOW HERE
CXX = g++
#CFLAGS = -Wall -g -std=c++11  Turned off warning because we will create many unused arrays
CFLAGS = -g -std=c++11 -Wall
OBJECTS = $(SRC_FILES:.cpp=.o)
ifeq ($(shell echo "Windows"), "Windows")
	TARGET := $(TARGET).exe
	DEL = del
else
	DEL = rm
endif

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) $(CFLAGS) -o $@ -c $<

clean:
	$(DEL) $(TARGET) $(OBJECTS)

# DEPENDENCIES
main.o: main.cpp Dog.h Cat.h Animal.h
Dog.o: Dog.cpp Dog.h Animal.h
Cat.o: Cat.cpp Cat.h Animal.h
Animal.o: Animal.cpp Animal.h

