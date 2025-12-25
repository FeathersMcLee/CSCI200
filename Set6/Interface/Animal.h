#ifndef ANIMAL_H
#define ANIMAL_H 

#include <string>

class Animal {
    public:
        Animal();
        virtual ~Animal();

        std::string getName();
        void setName(const std::string& N);

        virtual void speak() = 0;

    private:
        std::string mName;
        double mHeight;
        double mWeight;
};

#endif