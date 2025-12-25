#ifndef SEARCHFUNCTIONS_H
#define SEARCHFUNCTIONS_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct Position {
    int r, c;
};

void breadthFirstSearch(vector<vector<char>>& list, vector<vector<bool>>& checkList);

void depthFirstSearch(vector<vector<char>>& list, vector<vector<bool>>& checkList);

void print2DList(const vector<vector<char>>& list);

void printCheckList(const vector<vector<bool>>& checkList);

#endif