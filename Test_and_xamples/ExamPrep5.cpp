#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <exception>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstddef>
using namespace std;

int main() {
    // Populate list
    vector<int> list(0);
    for (int i = 0; i < 5; i++) {
        list.push_back(i);
    }

    // Selection
    for (int i = 0; i < list.size(); i++) {
        int minPos = i;
        for(int j = i+1; j < list.size(); j++){
            if(list.at(j) < list.at(minPos)) {
                minPos = j;
            }
        }
        int temp = list.at(minPos);
        list.at(minPos) = list.at(i);
        list.at(i) = temp;
    }

    // Insertion
    cout << endl;
    for(int i = 1; i < list.size(); i++) {
        int temp = list.at(i);
        int j = i-1;
        while(j >= 0 && list.at(j) > temp) {
            list.at(j+1) = list.at(j);
            j--;
        }
        list.at(j+1) = temp;
    }

    // Bubble
    for(int i = 0; i < list.size(); i++) {
        int numSwaps=0;
        for(int j = 0; j < list.size() - i - 1; j++) {
            if(list.at(j) > list.at(j+1)) {
                int temp = list.at(j+1);
                list.at(j+1) = list.at(j);
                list.at(j) = temp;
                numSwaps++;
            }
        }
        if(numSwaps == 0) {
            break;
        }
    }

    // Print list
    for (int i = 0; i < list.size(); i++) {
        cout << list.at(i);
    }

    return 0;
}