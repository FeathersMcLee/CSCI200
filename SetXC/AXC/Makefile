# A line starting with a hash (#) is a comment, we'll build up
# the below example

TARGET = AXC
SRC_FILES = main.cpp BinarySearchTree.hpp TreeNode.hpp

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
main.o: main.cpp TreeNode.hpp BinarySearchTree.hpp
BinarySearchTree.o: BinarySearchTree.hpp
TreeNode.o: TreeNode.hpp