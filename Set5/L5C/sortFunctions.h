#ifndef SORTFUNCTIONS_H
#define SORTFUNCTIONS_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> binarySearch(const vector<int>& list, const int target, int start, int right);

void printList(const vector<int> list);

vector<int> mergeSort(const vector<int>& list);

vector<vector<int>> splitList(const vector<int>& list);

vector<int> merge(const vector<int>& left, const vector<int>& right);

#endif