#ifndef LinkedList_HPP
#define LinkedList_HPP
#include "Node.hpp"

#include <string>
#include <iostream>

template <typename T>
class LinkedList {
    public:
        LinkedList();
        LinkedList(const LinkedList<T>& OTHER);
        LinkedList& operator=(const LinkedList<T>& OTHER);
        ~LinkedList();
        T get(const int POS) const;
        int find(const T TARGET);
        void insert(const int POS, const T VAL);
        T max();
        T min();
        void remove(const int POS);
        void set(const int POS, const T VAL);
        unsigned int size();
    private:
        Node<T>* mpHead;
        Node<T>* mpTail;
        unsigned int mSize;
        Node<T>* mMakeNodeForValue(const T VALUE);
};

/***********************************************************/
/*Implementations*/

template <typename T>
LinkedList<T>::LinkedList() {
    mpHead = nullptr;
    mpTail = nullptr;
    mSize = 0;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& OTHER) {
    // Initialize the member variables
    mpHead = nullptr;
    mpTail = nullptr;
    mSize = 0;
    Node<T>* pCurrNode = OTHER.mpHead;
    while (pCurrNode != nullptr) {
        insert(size(), pCurrNode->value);
        pCurrNode = pCurrNode->pNext;
    }
}

template <typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* pCurrNode = mpHead;
    while (pCurrNode != nullptr) {
        Node<T>* deleteNode = pCurrNode;
        pCurrNode = pCurrNode->pNext;
        delete deleteNode;
    }
}

template <typename T>
Node<T>* LinkedList<T>::mMakeNodeForValue(const T VAL) {
    Node<T>* pNode = new Node<T>;
    pNode->value = VAL;
    pNode->pNext = nullptr;
    pNode->pPrev = nullptr;
    return pNode;
}

template <typename T>
T LinkedList<T>::get(const int POS) const {
    if (POS < 0 || (unsigned int)POS >= mSize || mpHead == nullptr) { // if position is out of range or the list does not exist throw
        throw std::out_of_range("Out of range");
    }
    const Node<T>* pCURR_NODE = mpHead;
    int counter = 0;
    while (pCURR_NODE != nullptr && counter < POS) { // traverse list tracking count and seting pointer to next untill counter is equal to desired position
        pCURR_NODE = pCURR_NODE->pNext;
        counter++;
    }

    return pCURR_NODE->value;
}

template <typename T>
int LinkedList<T>::find(const T TARGET) {
    const Node<T>* pCURR_NODE = mpHead;
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

template <typename T>
void LinkedList<T>::insert(const int POS, const T VAL) {
    Node<T>* pNewNode = LinkedList<T>::mMakeNodeForValue(VAL);
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
        Node<T>* pCurrNode = mpHead;
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
    mSize++;
}

template <typename T>
T LinkedList<T>::max() {
    if (mpHead == nullptr) { // if list is empty
        throw std::out_of_range("list is empty");
    }
    const Node<T>* pCURR_NODE = mpHead;
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

template <typename T>
T LinkedList<T>::min() {
    if (mpHead == nullptr) { // if list is empty
        throw std::out_of_range("list is empty");
    }
    const Node<T>* pCURR_NODE = mpHead;
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

template <typename T>
void LinkedList<T>::remove(const int POS) {
    int newPOS;
    if (mpHead == nullptr) {
        mSize = 0;
        return;
    } else if (POS < 0) {
        newPOS = 0; // if position is less than 0, set position to 0
    } else if ((unsigned int)POS > mSize - 1) {
        newPOS = mSize - 1; // if position is greater than size, set position to mSize - 1
    } else {
        newPOS = POS;
    }

    Node<T>* pCurrNode = mpHead;
    int counter = 0;
    while (pCurrNode != nullptr && counter < newPOS) {
        pCurrNode = pCurrNode->pNext;
        counter++;
    }

    if (pCurrNode == nullptr) {
        return; // Position exceeds the list size, do nothing
    }

    if (pCurrNode == mpHead) {
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

    mSize--;
    delete pCurrNode;
}
template <typename T>
void LinkedList<T>::set(const int POS, const T VAL) {
    if (POS < 0 || mpHead == nullptr) { // if trying to set an invalid spot, or list is empty do nothing
        return;
    }
    Node<T>* pCurrNode = mpHead;
    int counter = 0;
    while (pCurrNode != nullptr && counter < (unsigned int)POS) { // advance through list until end and count number of jumps
        pCurrNode = pCurrNode->pNext;
        counter++;
    }
    if (pCurrNode != nullptr && counter == (unsigned int)POS) { // if valid position, change value otherwise do nothing
        pCurrNode->value = VAL;
    }
}

template <typename T>
unsigned int LinkedList<T>::size() { // returns size
    Node<T>* pCurrNode = mpHead;
    int counter = 0;
    while (pCurrNode != nullptr) { // counts length of linked list until position is reached
        pCurrNode = pCurrNode->pNext;
        counter++;
    }
    mSize = counter;
    return mSize;
}

#endif