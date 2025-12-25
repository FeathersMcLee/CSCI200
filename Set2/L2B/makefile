# A line starting with a has is a comment, we'll build up
# the below example

TARGET = FunctionFiles
SRC_FILES = main.cpp color_conversion.cpp

# DO NOT EDIT BELOW HERE
CXX = g++
CFLAGS = -Wall -g
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

# Dependencies
main.o: main.cpp color_conversion.h
color_conversion.o: color_conversion.cpp color_conversion.h