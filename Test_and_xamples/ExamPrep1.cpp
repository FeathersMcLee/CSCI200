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

int main() {
    double grade = 77;
    if(grade >= 90) {cout << "A" << endl;}
    if(grade >= 80 && grade < 90) {cout << "B" << endl;}
    if(grade < 80) {cout << "C" << endl;}
    

    if(grade >= 90) {cout << "A" << endl;}
    else if(grade >= 80) {cout << "B" << endl;}
    else {cout << "C" << endl;}
    int x = 1;
    cout << 11%3;
    cout << endl << x++ + 4;
    return 0;
}