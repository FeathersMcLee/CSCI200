# A line starting with a hash is a comment, we'll build up
# the below example
 
TARGET = FunctionPointers
SRC_FILES = main.cpp Distance.cpp

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
main.o: main.cpp Distance.h
Distance.o: Distance.cpp Distance.h