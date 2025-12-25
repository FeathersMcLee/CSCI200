/* CSCI 200: Lab XC: LXC - Binary Search Trees
 *
 * Author: Isaac March
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // used code from LinkedList and L6C
 *
 * program to create a list to be searched using a node tree
 */
#include <iostream>

#include "TreeNode.hpp"
#include "BinarySearchTree.hpp"

using namespace std;

int main() {
    // create a list of values in a list called tree
    BinarySearchTree<int> tree;
    tree.insert(6);
    tree.insert(6);
    tree.insert(7);
    tree.insert(1);
    tree.insert(2);
    tree.insert(9);
    tree.insert(3);

    cout << "Size of the tree: " << tree.size() << endl;
    for (int i = 0; i < tree.size(); i++) { // print values
        //cout << tree.value() << endl;
    }

    return 0;
}