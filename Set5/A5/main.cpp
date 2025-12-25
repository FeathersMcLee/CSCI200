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
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "searchFunctions.h"

using namespace std;

int main() {
    // open file
    string fileName;
    cout << "Enter a file name i.e. \"mazefile/1.maze\":"; 
    cin >> fileName; 
    cout << endl;
    ifstream fileIn(fileName);

    // Validate files
    if ( !fileIn ) {
        cerr << "Error opening input file" << endl;
        return -1;
    }

    // create maze vector using input file
    int rows, cols;
    fileIn >> rows >> cols;
    vector<vector<char>> maze(rows, vector<char>(cols));
    char ch;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fileIn >> ch;
            maze[i][j] = ch;
        }
    }
    
    // close file and print contents
    fileIn.close();
    cout << "Unsolved maze:" << rows << "x" << cols << endl; // used for debuging
    print2DList(maze); // used for debuging

    // perform a BSF or a DFS on the maze. start by looking for unchecked points athat are not '#'
    vector<vector<bool>> checkList(rows, vector<bool>(cols, false));
    cout << "Enter 1 to search via BFS.\nEnter 2 to search via DFS." << endl;
    int searchType; cin >> searchType;
    if (searchType == 1) {
        breadthFirstSearch(maze, checkList);
    } else if (searchType == 2) {
        depthFirstSearch(maze, checkList);
    } else {cout << "Invalid input" << endl; return 0;}
    cout << "Solved maze:" << endl;
    print2DList(maze);

    // commands used for debuging code
    //printCheckList(checkList);
    //cout << maze[rows-1][cols-1];
}