/* CSCI 200: Assignment 5: A5 - a-MAZE-ing
 *
 * Author: Isaac March
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // folowed the psudocode given in the lectures.
 *     // Cplusplus.com
 *     // www.tutorialspoint.com/data_structures_algorithms/depth_first_traversal.htm
 *
 * This program takes an input file ant writes the charactars to a 2D list and performs a BFS search to find a path to the end of a maze if a path exists.
 */
#include <vector>
#include <list>
#include <iostream>
#include "searchFunctions.h"

using namespace std;

// recursive Breadth First Search function for 2D lists using a que
void breadthFirstSearch(vector<vector<char>>& list, vector<vector<bool>>& checkList) {
    int rows = list.size();
    int cols = list[0].size();
    std::list<Position> positionsToCheck;
    char ch;
    // Find starting position S to begin search
    int startX, startY; 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            ch = list[i][j];
            if (ch == 'S') {
                startX = i; startY = j;
            }
        }
    }
    positionsToCheck.push_back({startX, startY}); // start at positions found in the double for loop
    checkList[startX][startY] = true; // check off start position in the checkList

    while (!positionsToCheck.empty()) {
        Position currPos = positionsToCheck.front();
        positionsToCheck.pop_front();

        //cout << "Current position: (" << currPos.r << ", " << currPos.c << ")" << endl; // debuging

        if (list[currPos.r][currPos.c] == 'E') {
            //cout << "Found the target at position: (" << currPos.r << ", " << currPos.c << ")" << endl; // debuging
            cout << "End was reached!" << endl;
            return;
        } else {
            // Check and uneque neighboring positions (up, right, down, left)
            vector<Position> neighbors = {
                {currPos.r - 1, currPos.c},
                {currPos.r, currPos.c + 1},
                {currPos.r + 1, currPos.c},
                {currPos.r, currPos.c - 1}
            };

            for (unsigned int i = 0; i < neighbors.size(); i++) {
                int r = neighbors[i].r;
                int c = neighbors[i].c;

                if (r >= 0 && r < rows && c >= 0 && c < cols && !checkList[r][c] && list[r][c] != '#') {
                    positionsToCheck.push_back({r, c});
                    checkList[r][c] = true;
                    if (list[r][c] != 'E') {
                        list[r][c] = '@';
                    }
                }
            }
        }
    }

    cout << "End cannot be reached" << endl;
}

// Depth First Search function for 2D lists using a stack
void depthFirstSearch(vector<vector<char>>& list, vector<vector<bool>>& checkList) {
    int rows = list.size();
    int cols = list[0].size();
    std::list<Position> positionsToCheck;
    char ch;
    // Find starting position S to begin search
    int startX, startY;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            ch = list[i][j];
            if (ch == 'S') {
                startX = i; startY = j;
            }
        }
    }
    positionsToCheck.push_back({startX, startY}); // start at positions found in the double for loop
    checkList[startX][startY] = true; // check off start position in the checkList

    while (!positionsToCheck.empty()) {
        Position currPos = positionsToCheck.back();
        positionsToCheck.pop_back();

        //cout << "Current position: (" << currPos.r << ", " << currPos.c << ")" << endl; // debugging

        if (list[currPos.r][currPos.c] == 'E') {
            //cout << "Found the target at position: (" << currPos.r << ", " << currPos.c << ")" << endl; // debugging
            cout << "End was reached!" << endl;
            return;
        } else {
            // Check and uneque neighboring positions (up, right, down, left)
            vector<Position> neighbors = { // creates a list of places to check relative to current position
                {currPos.r - 1, currPos.c},
                {currPos.r, currPos.c + 1},
                {currPos.r + 1, currPos.c},
                {currPos.r, currPos.c - 1}
            };

            for (unsigned int i = 0; i < neighbors.size(); i++) { // run through list of positions to chuck relative to curr position and inspect
                int r = neighbors[i].r;
                int c = neighbors[i].c;

                if (r >= 0 && r < rows && c >= 0 && c < cols && !checkList[r][c] && list[r][c] != '#') { // check that position inspected exists and is not a wall
                    positionsToCheck.push_back({r, c});
                    checkList[r][c] = true;
                    if (list[r][c] != 'E') { // ensure that end goal is not overwriten by the checklist
                        list[r][c] = '@';
                    }
                }
            }
        }
    }

    cout << "End cannot be reached" << endl;
}

// prints the contents of an input 2D list
void print2DList(const vector<vector<char>>& list) {
    int rows = list.size();
    int cols = list[0].size(); // Assuming all rows have the same number of columns

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << list[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

// prints the checklist for debuging
void printCheckList(const vector<vector<bool>>& checkList) {
    int rows = checkList.size();
    int cols = checkList[0].size(); // Assuming all rows have the same number of columns

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << checkList[i][j];
        }
        cout << endl;
    }
    cout << endl;
}