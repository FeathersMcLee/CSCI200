#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

#include <string>

class LinkedList {
    private:
        Node* mpHead;
        Node* mpTail;
        unsigned int mSize;
    public:
        LinkedList();
        ~LinkedList();
        int get(const int POS);
        int find(const int TARGET);
        void insert(const int POS, const int VALUE);
        int max();
        int min();
        void remove(const int POS);
        void set(const int POS, const int VALUE);
        unsigned int size();
    private:
        Node* mMakeNodeForValue(const int VALUE);
};

#endif