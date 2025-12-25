/* CSCI 200: Assignment XC: AXC - Forest Walk: Traversing BSTs
 *
 * Author: Isaac March
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // used code from LinkedList and L6C
 *
 * program to create the struct for each node and assign its pointers accordingly
 */
#ifndef TREENODE_HPP
#define TREENODE_HPP

// creating a new struct for TreeNode to store the left and right pointers
template <typename T>
struct TreeNode {
    T value; // templated value to take multiple data types
    TreeNode* left;
    TreeNode* right;

    TreeNode(const T& val) : value(val), left(nullptr), right(nullptr) {} // helps assign new pointer when node created for a linked list
};

#endif