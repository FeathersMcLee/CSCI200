#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <exception>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstddef>
using namespace std;

int neutral_func(int foo, double bar, char baz) {
    return 0;
}

void cool_func() {

}

double hot_func() {
    return 1.0;
}

int area_square(int h) {
    int area = h * 2;
    return area;
}

void add_one( int &x );

int main() {
    // Q
    int foo;
    double bar;
    char baz;
    int a = neutral_func(foo, bar, baz);

    // Q
    int h, w;
    h = 2;
    int area = area_square(h);
    cout << "Area " << area << endl;
    // or
    cout << area_square(2);

    // Q
    int x = 7;
    add_one( x );
    cout << "7 plus one is " << x << endl;

    return 0;
}

void add_one( int &x ) {
    x++;
}