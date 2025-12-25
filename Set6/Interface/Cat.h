#ifndef CAT_H
#define CAT_H

#include "Animal.h"
#include "IDrawable.h"
#include <string>

class Cat : public Animal, IDrawable {
    public:
        Cat();
        ~Cat();
        
        virtual void speak() override;
        virtual void draw() override;

    private:
        
};
#endif