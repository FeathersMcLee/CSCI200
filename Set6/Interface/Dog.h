#ifndef DOG_H
#define DOG_H

#include "Animal.h"
#include "IDrawable.h"
#include <string> 

class Dog : public Animal, IDrawable {
    public:
        Dog();
        ~Dog();
        
        virtual void speak() override;
        virtual void draw() override;

};
#endif