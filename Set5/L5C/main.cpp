/* CSCI 200: Lab 5C: L5C - A Needle in the Haystack
 *
 * Author: Isaac March
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // Stack overflow
 *     // Used code from lab 5B
 *
 * sorts a list and performs a binary search based on user given constraints
 */

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <vector>
#include <ctime>
#include <random>
#include "sortFunctions.h"

using namespace std;
 
int main() {
    srand(static_cast<unsigned int>(time(0)));

    // ask for user input of n, min, and max
    int n, min, max, random;
    cout << "How many integers would you like to enter: ";
    cin >> n; cout << endl;
    cout << "Enter a smallest value: ";
    cin >> min; cout << endl;
    cout << "Enter a largest value: ";
    cin >> max; cout << endl;

    // populate list
    vector<int> list = {};
    for (int i = 0; i < n * 10; i++) {
        random = min + rand() % (max - min + 1);
        list.push_back(random);
    }

    // print original list
    cout << "Original list: ";
    printList(list);

    // print sorted list
    vector<int> sortedList = mergeSort(list);
    cout << "Sorted list: ";
    printList(sortedList);

    // ask the user how many target values to search for
    int nTargets, target;
    cout << "Enter a number of target values to seach for: ";
    cin >> nTargets;
    vector<int> targetList = {};
    for (int i = 0; i < nTargets; i++) {
        cout << "Target " << i+1 << ": "; cin >> target;
        targetList.push_back(target);
    } 
    cout << "List of targets: ";
    printList(targetList);

    // perorm binary search for each item in targetList
    for (int i = 0; i < nTargets; i++) {
        target = targetList[i];
        binarySearch(sortedList, target, 0, sortedList.size() - 1);
    } 

    return 0;
}