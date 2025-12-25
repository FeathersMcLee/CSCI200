#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

class Array { 
    public:
        Array(const int SIZE);
        Array(const Array& OTHER);
        ~Array();
        int size() const;
        void resize(const int SIZE);
        void set(const int POS, const int VAL);
        int get(const int i) const;
        Array& operator=(const Array& OTHER);

    private:
        int *mpArr;
        int mSize;
};

ostream& operator<<(ostream& os, const Array& ARR);

#endif