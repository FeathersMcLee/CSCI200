#include "color_conversion.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

//Convert RGB to HSV
void rgb_to_hsv(double r, double g, double b) {
    //Find Min and Max
    double Max = std::max(r, std::max(g, b));
    double Min = std::min(r, std::min(g, b));
    double delta = Max - Min;
    //Find Value 
    double V = Max/255;

    //Find Saturation
    double S;
    if (Max > 0) {
        S = 1 - Min/Max;
    }
    else if (Max == 0) {
        S = 0;
    }

    //Find Hue
    double H;
    if (delta == 0) {
        H = 0;
    } else if (Max == r) {
        H = 60 * (((g - b) / delta) + 6);
    } else if (Max == g) {
        H = 60 * (((b - r) / delta) + 2);
    } else if (Max == b) {
        H = 60 * (((r - g) / delta) + 4);
    }
    cout << "(" << H <<", " << S << ", " << V << ")"<< endl;
}

//Convert HSV to RGB
void hsv_to_rgb(double h, double s, double v) {
    //Find Min and Max
    double M = 255*v;
    double m = M*(1-s);
    double z = (M-m)*(1-abs(fmod(h/60.0,2)-1));
    
    double r; double g; double b;
    if (h < 60) {
        r = M;
        g = z+m;
        b = m;
    } else if (h >= 60 && h < 120) {
        r = z+m;
        g = M;
        b = m;
    } else if (h >= 120 && h < 180) {
        r = m;
        g = M;
        b = z+m;
    } else if (h >= 180 && h < 240) {
        r = m;
        g = z+m;
        b = M;
    } else if (h >= 240 && h < 300) {
        r = z+m;
        g = m;
        b = M;
    } else {
        r = M;
        g = m;
        b = z+m;
    }

    //r = static_cast<int>((r + m) * 255.0);
    //g = static_cast<int>((g + m) * 255.0);
    //b = static_cast<int>((b + m) * 255.0);
    cout << "(" << r <<", " << g << ", " << b << ")"<< endl;
    //
}