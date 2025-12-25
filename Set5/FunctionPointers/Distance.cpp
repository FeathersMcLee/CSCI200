#include "Distance.h"

Distance::Distance() { mFeet = mInches = 0; }

int Distance::getFeet() const { return mFeet; }
void Distance::setFeet(int f) { mFeet = f; }
int Distance::getInches() const { return mInches; }
void Distance::setInches(int i) { mInches = i; } 

// Add inequality operators
bool Distance::operator<(const Distance& D) {
    return ((mFeet < D.mFeet)
        || (mFeet == D.mFeet && mInches < D.mInches));
}

bool Distance::operator>(const Distance& D) {
    return ((mFeet > D.mFeet)
        || (mFeet == D.mFeet && mInches > D.mInches));
}
