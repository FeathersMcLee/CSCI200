#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
    public:
        Animal();
        ~Animal();

        std::string getName();
        void setName(const std::string& N);
    private:
        std::string mName;
        double mHeight;
        double mWeight;
};



#endif