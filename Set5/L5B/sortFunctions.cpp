#include <vector>
#include <list>
#include <iostream>
#include "sortFunctions.h"

using namespace std;

// recursive Merge Sort function
vector<int> mergeSort(const vector<int>& list) {
    // base case
    if (list.size() <= 1) {
        return list;
    } else {
        // divide
        vector<vector<int>> halves = splitList(list);
        vector<int> leftList = halves[0];
        vector<int> rightList = halves[1];

        // recurse
        leftList = mergeSort(leftList);
        rightList = mergeSort(rightList);

        // conquer
        return merge(leftList, rightList);
    }
}

// Merge two sorted lists into a single sorted list
vector<int> merge(const vector<int>& left, const vector<int>& right) {
    vector<int> mergedList;
    unsigned int leftIndex = 0;
    unsigned int rightIndex = 0;

    while (leftIndex < left.size() && rightIndex < right.size()) { // merge the two lists in sorted order
        if (left[leftIndex] <= right[rightIndex]) {
            mergedList.push_back(left[leftIndex]);
            leftIndex++;
        } else {
            mergedList.push_back(right[rightIndex]);
            rightIndex++;
        }
    }

    // deals with any remaining elements from each list
    while (leftIndex < left.size()) {
        mergedList.push_back(left[leftIndex]);
        leftIndex++;
    }
    while (rightIndex < right.size()) {
        mergedList.push_back(right[rightIndex]);
        rightIndex++;
    }

    return mergedList;
}

// split list function with a vector list of outputs
vector<vector<int>> splitList(const vector<int>& list) {
    vector<vector<int>> halves(2);
    unsigned int mid = list.size() / 2;
    halves[0] = vector<int>(list.begin(), list.begin() + mid);
    halves[1] = vector<int>(list.begin() + mid, list.end());
    return halves;
}