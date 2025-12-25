#ifndef CYLINDER_H
#define CYLINDER_H

const float PI = 3.1415926;

class Cylinder {
    public:
        double radius;
        double height;

        double volume();
};


#endif