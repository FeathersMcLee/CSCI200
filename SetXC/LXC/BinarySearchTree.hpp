/* CSCI 200: Lab XC: LXC - Binary Search Trees
 *
 * Author: Isaac March
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // used code from LinkedList and L6C
 *
 * program to create class BinarySearchTree and apply its implimentations
 */
#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include "TreeNode.hpp"
#include <iostream>

using namespace std;

template <typename T>
class BinarySearchTree {
    public:
        BinarySearchTree(); // Constructor that sets the root pointer to be null and set the size to be zero
        BinarySearchTree(const BinarySearchTree& OTHER); // Copy Constructor that performs a deep copy of the other tree
        ~BinarySearchTree(); // Destructor that deallocates the entire tree, sets the root pointer to be null, sets the size to be zero
        BinarySearchTree& operator=(const BinarySearchTree& OTHER); // Copy Assignment Operator that deallocates the existent tree (if any) then performs a deep copy of the other tree
        // inserts a node for the given VAL. If VAL is less than the root, recursively attempt to add to the left subtree. If VAL is greater or equal to the root, 
        // recursively attempt to add to the right subtree. Increments the size by one. (Note: We are not going to be implementing the balanced binary search tree.)
        void insert(const T VAL); 
        int size() const; // returns the current total number of nodes in the tree
    private:
        TreeNode<T>* root;
        int numNodes;
};

// Constructor that sets the root pointer to be null and set the size to be zero
template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
    numNodes = 0;
    root = nullptr;
}

// Copy Constructor that performs a deep copy of the other tree
template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree& OTHER) {

}

// Destructor that deallocates the entire tree, sets the root pointer to be null, sets the size to be zero
template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    
}

// Copy Assignment Operator that deallocates the existent tree (if any) then performs a deep copy of the other tree
template <typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree& OTHER) {

}

// inserts a node for the given VAL. If VAL is less than the root, recursively attempt to add to the left subtree. If VAL is greater or equal to the root, 
// recursively attempt to add to the right subtree. Increments the size by one. (Note: We are not going to be implementing the balanced binary search tree.)
template <typename T>
void BinarySearchTree<T>::insert(const T VAL) {
    TreeNode<T>* newNode = new TreeNode<T>(VAL);
    if (!root) { // if there is no root create a new one
        root = newNode;
        numNodes++;
        return;
    }
    TreeNode<T>* currentNode = root; // make current node the root
    while (currentNode) { // while on current node
        if (VAL < currentNode->value) { // if value is less than curent node value then add it to the left subtree
            if (!currentNode->left) {
                currentNode->left = newNode;
                numNodes++;
                return;
            }
            currentNode = currentNode->left;
        } else { // if value is greater than or equal to root add it to right subtree
            if (!currentNode->right) {
                currentNode->right = newNode;
                numNodes++;
                return;
            }
            currentNode = currentNode->right;
        }
    }
}

// returns the current total number of nodes in the tree
template <typename T>
int BinarySearchTree<T>::size() const {
    return this->numNodes;
}

#endif