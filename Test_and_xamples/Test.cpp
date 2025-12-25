#include <iostream>
#include <vector>

using namespace std;

void f(const int I, const int N) {
    if (I < N) {
        std::cout << I;
        f(I + 1, N);
        std::cout << I;
        f(I + 1, N);
        std::cout << I << std::endl;
    }
}

int main() {
    f(0, 2);
    return 0;
}