/* CSCI 200: Assignment XC: AXC - Forest Walk: Traversing BSTs
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
    tree.insert(5);
    tree.insert(7);
    tree.insert(1);
    tree.insert(2);
    tree.insert(9);
    tree.insert(3);

    //cout << "Size of the tree: " << tree.size() << endl;
    
    //tree.printInOrder();
    //tree.printPreOrder();
    //tree.printPostOrder();

    BinarySearchTree<int> tree2;
    tree2.insert(5);
    tree2.insert(1);
    tree2.insert(9);
    tree2.insert(7);
    tree2.insert(6);
    tree2.insert(3);
    tree2.insert(2);

    //tree2.printInOrder();
    //tree2.printPreOrder();
    //tree2.printPostOrder();
    //tree2.printBreadthOrder();
    //tree2.printDepthOrder();
    //tree2.printByLevels();
    //cout << tree2.height() << endl;

    return 0;
}