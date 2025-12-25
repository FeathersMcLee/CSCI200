#ifndef IDRAWABLE_H
#define IDRAWABLE_H

class IDrawable {
    public:
        virtual ~IDrawable() {};
        virtual void draw() = 0;
};

#endif