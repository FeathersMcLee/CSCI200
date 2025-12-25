/* CSCI 200: Lab 5B: L5B - Recursion II: Merge Sort
 *
 * Author: Isaac March
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // codesdope.com/blog/article/c-concatenating-two-linked-lists-in-c/
 *     // developer.nvidia.com/blog/merge-sort-explained
 *
 * performs a merge sort on a given list
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include "sortFunctions.h"

using namespace std;
 
int main() {
    // populate list
    vector<int> list = {4, 3, 8, 1, 5, 9, 7, 2, 6};

    // print original list
    cout << "Original list: ";
    for (unsigned int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;

    // print sorted list
    vector<int> sortedList = mergeSort(list);
    cout << "Sorted list: ";
    for (unsigned int i = 0; i < sortedList.size(); i++) {
        cout << sortedList[i] << " ";
    }
    cout << endl;

    return 0;
}