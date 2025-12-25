#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Q1
    for(int i = 0; i < 100; i++) {
        if (i%2 == 1) {
            cout << i << " ";
        }
    }

    // Q2
    cout << endl;
    srand(time(0));
    int min = 1;
    int max = 100;
    for(int i = 0; i < 10; i++) {
        int Random = (rand() % (max - min + 1)) + min;
        cout << Random << " ";
    }

    // Q3
    cout << endl;
    for(int i = 2; i <=18; i+=3){
        cout << "*";
    }

    // Q4
    ifstream fileIn("xc.txt");
    if ( !fileIn ) {
        cerr << "Error opening input file" << endl;
        return -1;
    }
    int x;
    int j;
    int Max = 0;
    int Min = 1000;
    fileIn >> x;
    for ( int i = 0; i < x; i++) {
        fileIn >> j;
        if (j > Max) {Max = j;}
        if (j < Min) {Min = j;}
    }
    cout << endl << " Max " << Max;
    cout << " Min " << Min;
    cout << " Length " << fileIn.eof() << endl;

    // Q6
    cout << endl << "Enter max value: ";
    int X;
    cin >> X;
    int i = 0;
    while( i <= X) {
        if (i%2) {
            cout << i << " ";
        }
        i++;
    }
    cout << endl;

    // Q7
    int rank;
    cout << endl << "Enter a rank integer: ";
    cin >> rank;
    switch (rank) {
        case 1:
        case 2:
            cout << "Lower division" << endl;
            break;
        case 3:
        case 4:
            cout << "Upper division" << endl;
            break;
        case 5:
            cout << "Graduate student" << endl;
            break;
        //default:
            //cout << "Invalid rank" << endl;
            //break;
    }

    // Q3
    cout << endl;
    for(int i = 0; i < 4; i++){
        for (int j=i;j<6;j++){
            cout << "*";
        }
        cout << endl;
    }



    // Q5 
    int number = 0;
    int sum = 0;
    int limit = 20;
    while ( number < limit){
        sum += number;
        number += 2;
    }
    cout << sum << endl;

    number = 0;
    sum = 0;
    limit = 20;
    while ( number > limit){
        sum += number;
        number += 2;
    }
    cout << sum << endl;

    number = 100;
    while ( number > limit){
        sum += number;
        number += 2;
    }
    cout << sum << endl;





    return 0;
}

