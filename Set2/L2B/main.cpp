/* CSCI 200: Lab 2: L2B - 
 *
 * Author: Isaac March
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // ZYbooks
 *
 *  Recives RGB or HSV values and converts them to the non-given color format.
 */
// The include section adds extra definitions from the C++ standard library.


#include <iostream> // For cin, cout, etc.
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include "color_conversion.h"
using namespace std;

int main() {
    //Ask user what to convert
    int userin;
    cout << "Enter 1 to convert from RGB to HSV or 2 to convert from HSV to RGB:" << endl;
    cin >> userin;
    if (userin == 1) {
        cout << "Enter an R, G, and B value:" << endl;
        double r; double g; double b;
        cin >> r >> g >> b;
        rgb_to_hsv(r, g, b);
    }
    else if (userin == 2) {
        cout << "Enter an H, S, and V value:" << endl;
        double h; double s; double v;
        cin >> h >> s >> v;
        hsv_to_rgb(h,s,v);
    }
    else {
        cerr << "Invalid input." << endl;
    }
    return 0;
}




