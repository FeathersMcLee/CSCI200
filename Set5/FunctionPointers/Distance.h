#ifndef DISTANCE_H
#define DISTANCE_H

class Distance {
    public:
        Distance();
        int getFeet() const;
        void setFeet(int f);
        int getInches() const;
        void setInches(int i);

        // Add inequality operators
        bool operator<(const Distance& D);
        bool operator>(const Distance& D);
        
    private:
        int mFeet;
        int mInches; 
};

#endif