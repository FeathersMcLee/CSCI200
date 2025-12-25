#ifndef ROCKCAIRN_HPP
#define ROCKCAIRN_HPP

class RockCairn {
public:
    RockCairn() { }
    bool push(const int VALUE) {
        if (VALUE < mStack.peek()) {
            mStack.push(VALUE);
            return true;
        }
        return false;
    }
    int pop() {
        if (mStack.size() > 0) return mStack.pop();
        else throw std::out_of_range("stack is empty");
    }
    int size() const { return mStack.size(); }
private:
    Stack mStack;
};

#endif