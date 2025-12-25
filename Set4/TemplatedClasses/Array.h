#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

template <typename T>
class Array { 
    public:
        Array(const int SIZE);
        Array(const Array<T>& OTHER);
        ~Array();
        int size() const;
        void resize(const int SIZE);
        void set(const int POS, const T VAL);
        T get(const int i) const;
        Array<T>& operator=(const Array<T>& OTHER);
    private:
        T *mpArr;
        int mSize;
};

template <typename T>
ostream& operator<<(ostream& os, const Array<T>& ARR);



#endif