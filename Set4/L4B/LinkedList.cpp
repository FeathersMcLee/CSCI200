/* CSCI 200: Lab 4B: A Linked List Class Test Suite
 *
 * Author: Isaac March
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // Asked a Mines graduate student to help explain linked lists. Helped with insert position function
 *
 * This program contains the implimentations of each function specified from the assignemnt. Functions create a linked list value, add values, remove values, and find values.
 */

#include "LinkedList.h"

#include <iostream>
using namespace std;

LinkedList::LinkedList() {
    mpHead = nullptr;
    mpTail = nullptr;
    //mSize = 0;
}

LinkedList::~LinkedList() {
    Node* pCurrNode = mpHead;
    while (pCurrNode != nullptr) {
        Node* deleteNode = pCurrNode;
        pCurrNode = pCurrNode->pNext;
        delete deleteNode;
    }
}

Node* LinkedList::mMakeNodeForValue(const int VALUE) {
    Node* pNode = new Node;
    pNode->value = VALUE;
    pNode->pNext = nullptr;
    pNode->pPrev = nullptr;
    return pNode;
}

int LinkedList::get(const int POS) {
    if (POS < 0 || POS >= mSize || mpHead == nullptr) { // if position is out of range or the list does not exist throw
        throw std::out_of_range("Out of range");
    }
    const Node* pCURR_NODE = mpHead;
    int counter = 0;
    while (pCURR_NODE != nullptr && counter < POS) { // traverse list tracking count and seting pointer to next untill counter is equal to desired position
        pCURR_NODE = pCURR_NODE->pNext;
        counter++;
    }

    return pCURR_NODE->value;
}

int LinkedList::find(const int TARGET) {
    const Node* pCURR_NODE = mpHead;
    int counter = 0;
    while (pCURR_NODE != nullptr) { // traverse list tracking count, if value in position is equal to target return counter
        int numb = pCURR_NODE->value;
        if (numb == TARGET) {
            return counter;
        }
        pCURR_NODE = pCURR_NODE->pNext;
        counter++;
    }

    return -1;
}

void LinkedList::insert(const int POS, const int VALUE) {
    Node* pNewNode = LinkedList::mMakeNodeForValue(VALUE);
    int newPOS;
    if (POS < 0) {
        newPOS = 0; // if position is less than 0 set position to 0
    } else if (POS > mSize) {
        newPOS = mSize; // if position is greater than size set position to mSize
    } else {
        newPOS = POS;
    }
    if (newPOS == 0 || mpHead == nullptr) { // insert at the head
        pNewNode->pNext = mpHead;
        if (mpHead != nullptr) {
            mpHead->pPrev = pNewNode;
        }
        mpHead = pNewNode;
        if (mpTail == nullptr) {
            mpTail = pNewNode;
        }
    } else if (newPOS == mSize) { // insert at the tail
        pNewNode->pPrev = mpTail;
        if (mpTail != nullptr) {
            mpTail->pNext = pNewNode;
        }
        mpTail = pNewNode;
        if (mpHead == nullptr) {
            mpHead = pNewNode;
        }
    } else { // insert at position
        Node* pCurrNode = mpHead;
        int counter = 0;
        while (pCurrNode != nullptr && counter < newPOS) { // traverse list tracking count
            pCurrNode = pCurrNode->pNext;
            counter++;
        }
        pNewNode->pNext = pCurrNode;
        pNewNode->pPrev = pCurrNode->pPrev;
        if (pCurrNode->pPrev != nullptr) {
            pCurrNode->pPrev->pNext = pNewNode;
        } else {
            mpHead = pNewNode;
        }
        pCurrNode->pPrev = pNewNode;
    }
    //mSize++;
}

int LinkedList::max() {
    if (mpHead == nullptr) { // if list is empty
        throw std::out_of_range("list is empty");
    }
    const Node* pCURR_NODE = mpHead;
    int maxVal = pCURR_NODE->value;
    pCURR_NODE = pCURR_NODE->pNext;
    while (pCURR_NODE != nullptr) { // traverse list tracking max value present
        int numb = pCURR_NODE->value;
        if (numb > maxVal) {
            maxVal = numb;
        }
        pCURR_NODE = pCURR_NODE->pNext;
    }

    return maxVal;
}

int LinkedList::min() {
    if (mpHead == nullptr) { // if list is empty
        throw std::out_of_range("list is empty");
    }
    const Node* pCURR_NODE = mpHead;
    int minVal = pCURR_NODE->value;
    pCURR_NODE = pCURR_NODE->pNext;
    while (pCURR_NODE != nullptr) { // traverse list tracking min value present
        int numb = pCURR_NODE->value;
        if (numb < minVal) {
            minVal = numb;
        }
        pCURR_NODE = pCURR_NODE->pNext;
    }
    return minVal;
}

void LinkedList::remove(const int POS) {
    int newPOS; // clamps position to head or tail if position is out of range
    if (mpHead == nullptr) { // if list does not exist
        mSize = 0;
        return;
    } else if (mpHead != nullptr && POS < 0) { // if list exists and pos is less than length
        newPOS = 0;
    } else if (mpHead != nullptr && POS > mSize-1) { // if list exists and pos is greater than length
        newPOS = mSize-1;
    } else { // if list exists and pos is within range
        newPOS = POS;
    }
    Node* pCurrNode = mpHead;
    int counter = 0;
    while (pCurrNode != nullptr && counter < newPOS) { // counts length of linked list until position is reached
        pCurrNode = pCurrNode->pNext;
        counter++;
    }
    if (pCurrNode == nullptr) { // Position exceeds the list size, do nothing
        return;
    }
    if (pCurrNode == mpHead) { // Current node is head set next pointers to next node, set prev pointers to null
        mpHead = pCurrNode->pNext;
        if (mpHead != nullptr) {
            mpHead->pPrev = nullptr;
        } else {
            mpTail = nullptr;
        }
    } else if (pCurrNode == mpTail) {
        mpTail = pCurrNode->pPrev;
        if (mpTail != nullptr) {
            mpTail->pNext = nullptr;
        } else {
            mpHead = nullptr;
        }
    } else {
        pCurrNode->pPrev->pNext = pCurrNode->pNext;
        pCurrNode->pNext->pPrev = pCurrNode->pPrev;
    }
    delete pCurrNode;
    //mSize--;
}

void LinkedList::set(const int POS, const int VALUE) {
    if (POS < 0 || mpHead == nullptr) { // if trying to set an invalid spot, or list is empty do nothing
        return;
    }
    Node* pCurrNode = mpHead;
    int counter = 0;
    while (pCurrNode != nullptr && counter < POS) { // advance through list until end and count number of jumps
        pCurrNode = pCurrNode->pNext;
        counter++;
    }
    if (pCurrNode != nullptr && counter == POS) { // if valid position, change value otherwise do nothing
        pCurrNode->value = VALUE;
    }
}

unsigned int LinkedList::size() { // returns size
    Node* pCurrNode = mpHead;
    int counter = 0;
    while (pCurrNode != nullptr) { // counts length of linked list until position is reached
        pCurrNode = pCurrNode->pNext;
        counter++;
    }
    mSize = counter;
    return mSize;
}