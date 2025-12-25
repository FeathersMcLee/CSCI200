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

string string_append(string str) {
    string text = " is a super coder.";
    string new_str = str + text;
    return new_str;
}

int main() {
    // Q cypher list
    ifstream fileIn("cypher.txt");
    if ( !fileIn ) {
        cerr << "Error opening input file" << endl;
        return -1;
    }
    int length;
    int value;
    int min;
    int p;
    int j;
    vector<int> list;
    while(!fileIn.eof()) {
        fileIn >> value;
        list.push_back(value);
        cout << value;
    }

    for ( int j = 2; j < length; j++) {
        fileIn >> value;
        //if()
    }

    cout << "Min: " << min << endl;
    cout << "Length: " << length << endl;



    // Q
    unsigned short int q = -1;
    cout << "Unsigned int: " << q << endl;

    // Q
    cout << string_append("You") << endl;

    // Bubble Sort
    int array[5] = {0, 3, 2, 5, 8};
    int max = 0;
    for (int i = 0; i < 5; i++) {
        if (max < array[i]) {
            max = array[i];
        }
    }

    cout << max;

    return 0;
}

