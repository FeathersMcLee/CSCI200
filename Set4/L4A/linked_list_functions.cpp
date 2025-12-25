/* CSCI 200: Lab 4A: A Linked List Test Suite
 *
 * Author: Isaac March
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // Stackoverflow
 *     // Cplusplus.com
 *
 * This program contains the implimentations of each function specified from the assignemnt. Functions create a linked list value, add values, remove values, and find values.
 */


#include "linked_list_functions.h"

#include <exception>
#include <iostream>
#include <string>

Node* linked_list_make_node(const int VALUE) { // Do not eddit
    Node* pNode = new Node;
    pNode->value = VALUE;
    pNode->pNext = nullptr;
    pNode->pPrev = nullptr;
    return pNode;
}

void linked_list_add_value_to_front(Node*& pHead, Node*& pTail, const int VALUE) { 
    // make a new node
    Node* pNewNode = linked_list_make_node(VALUE);      
    // if list is initially empty
    if (pHead == nullptr) {
        // head and tail are the new node 
        pHead = pTail = pNewNode;
    // otherwise, chain into existing node
    } else {
        // link new node and head, update head
        pNewNode->pNext = pHead;
        pHead->pPrev = pNewNode;
        pHead = pNewNode;
    }
}

int linked_list_get_size(const Node* const P_HEAD, const Node* const P_TAIL) {
    const Node* pCURR_NODE = P_HEAD;
    int counter = 0;
    // advance through list until end and count number of jumps
    while (pCURR_NODE != nullptr) {
        pCURR_NODE = pCURR_NODE->pNext;
        counter++;
    }
    return counter;
}

int linked_list_get_value_at_position(const Node* const P_HEAD, const Node* const P_TAIL, const int POS) {
    const Node* pCURR_NODE = P_HEAD;
    int counter = 0;
    // advance through list until end and count number of jumps
    while (pCURR_NODE != nullptr && counter < POS) {
        pCURR_NODE = pCURR_NODE->pNext;
        counter++;
    }
    // if valid position, return value
    // otherwise throw excepetion
    if (pCURR_NODE == nullptr || counter != POS) {
        throw std::out_of_range("Out of range");
    }
    return pCURR_NODE->value;
}

void linked_list_set_value_at_position(Node* const P_head, Node* const P_tail, const int POS, const int VALUE) {
    // if trying to set an invalid spot, or list is empty - do nothing
    if(POS < 0 || P_head == nullptr) {
        return;
    }
    Node* pCurrNode = P_head;
    int counter = 0;
    // advance through list until end and count number of jumps
    while (pCurrNode != nullptr && counter < POS) {
        pCurrNode = pCurrNode->pNext;
        counter++;
    }
    // if valid position, change value
    // otherwise do nothing
    if(pCurrNode != nullptr && counter == POS) {
        pCurrNode->value = VALUE;
    } else {
        return;
    }
}

void linked_list_remove_node_at_front(Node*& pHead, Node*& pTail) {
    // if list is empty - do nothing
    if(pHead == nullptr) {return;}                
    // store pointer to current head
    Node* pointer = pHead;
    // advance head
    pHead = pHead->pNext;
    
    // if we're now pointing at nothing, list only had one element
    if(pHead == nullptr) {
        //  set tail to also be null so it points to nothing
        pTail = nullptr;
    // otherwise, list still has elements
    } else {
        // set back pointer to be null
        pHead->pPrev = nullptr;
    }
    // delete former head
    delete pointer;
}

void linked_list_add_value_to_back(Node*& pHead, Node*& pTail, const int VALUE) {
    // make new node
    Node* pNewNode = linked_list_make_node(VALUE);
    // if list is initially empty
    if(pHead == nullptr) {
        // head and tail are the new node 
        pHead = pNewNode;
        pTail = pNewNode;
        
    // otherwise, chain off existing node
    }  else {
        // link new node and tail, update tail
        pTail->pNext = pNewNode;
        pNewNode->pPrev = pTail;
        pTail = pNewNode;
    }
}

void linked_list_remove_node_at_back(Node*& pHead, Node*& pTail) {
    // if list is empty, do nothing
    if(pTail == nullptr) {return;}
    // store pointer to current tail
    Node* pointer = pTail;
    // move tail backwards
    pTail = pTail->pPrev;
    // if we're now pointing at nothing, list only had one element
    if(pTail == nullptr) {
        //  set head to also be null so it points to nothing
        pHead = nullptr;
    // otherwise, list still has elements
    } else {
        // set next pointer to be null
        pTail->pNext = nullptr;
    }
    // delete former tail
    delete pointer;
    
}

void linked_list_add_value_before_position(Node*& pHead, Node*& pTail, const int POS, const int VALUE) {
    // if position is before the beginning, add to front
    if(POS <= 0 || pHead == nullptr) {
        linked_list_add_value_to_front(pHead, pTail, VALUE);
    } else {
        Node* pCurrNode = pHead;
        int counter = 0;
        // advance through list until end and count number of jumps
        while (pCurrNode != nullptr && counter < POS) {
            pCurrNode = pCurrNode->pNext;
            counter++;
        }
        // if we have gone past the end
        if(pCurrNode == nullptr) {
            // add to back
            linked_list_add_value_to_back(pHead, pTail, VALUE);
        } else {
            // otherwise add before target position
            Node* pNewNode = linked_list_make_node(VALUE);
            pNewNode->pNext = pCurrNode;
            pNewNode->pPrev = pCurrNode->pPrev;
            if (pCurrNode->pPrev != nullptr) {
                pCurrNode->pPrev->pNext = pNewNode;
            }
            else {
                pHead = pNewNode;
            }
            pCurrNode->pPrev = pNewNode;
        }
    }
}

int linked_list_min(const Node* const P_HEAD, const Node* const P_TAIL) {
    const Node* pCURR_NODE = P_HEAD;
    // if list is empty
    if(pCURR_NODE == nullptr) {
        // throw exception
        throw std::out_of_range("list is empty");
    }
    // traverse list tracking min value present
    int minVal = pCURR_NODE->value;
    pCURR_NODE = pCURR_NODE->pNext;
    while (pCURR_NODE != nullptr) {
        int numb = pCURR_NODE->value;
        if(numb < minVal) {
            minVal = numb;
        }
        pCURR_NODE = pCURR_NODE->pNext;
    }
    return minVal;
}

int linked_list_max(const Node* const P_HEAD, const Node* const P_TAIL) {
    const Node* pCURR_NODE = P_HEAD;
    // if list is empty
    if(pCURR_NODE == nullptr) {
        // throw exception
        throw std::out_of_range("list is empty");
    }
    // traverse list tracking max value present
    int maxVal = pCURR_NODE->value;
    pCURR_NODE = pCURR_NODE->pNext;
    while (pCURR_NODE != nullptr) {
        int numb = pCURR_NODE->value;
        if(numb > maxVal) {
            maxVal = numb;
        }
        pCURR_NODE = pCURR_NODE->pNext;
    }
    return maxVal;
}

int linked_list_find(const Node* const P_HEAD, const Node* const P_TAIL, const int TARGET) {
    const Node* pCURR_NODE = P_HEAD;
    int counter = 0;
    // advance through list until end and target is found or end reached
    while (pCURR_NODE != nullptr) {
        int numb = pCURR_NODE->value;
        if(numb == TARGET) {
            break;
        }
        pCURR_NODE = pCURR_NODE->pNext;
        counter++;
    }
    // return found position or -1 if end of list reached
    if(pCURR_NODE == nullptr){
        return -1;
    }
    return counter;
}

void linked_list_remove_node_at_position(Node*& pHead, Node*& pTail, const int POS) {
    // if list is empty
    if(pHead == nullptr) {
        // do nothing
        return;
    } 
    // if position is before start of list
    else if(POS <= 0) {
        // remove from front
        linked_list_remove_node_at_front(pHead, pTail);
    } else {
        Node* pCurrNode = pHead;
        int counter = 0;
        // advance through list until end and count number of jumps
        while (pCurrNode != nullptr && counter < POS) {
            pCurrNode = pCurrNode->pNext;
            counter++;
        }
        // if we have gone to tail or further
        if(pCurrNode == nullptr || pCurrNode == pTail) {
            // remove from back
            linked_list_remove_node_at_back(pHead, pTail);
        } else {
            // unlink current node
            Node* pPrevNode = pCurrNode->pPrev;
            Node* pNextNode = pCurrNode->pNext;
            if (pPrevNode != nullptr) {
                pPrevNode->pNext = pNextNode;
            } else {
                pHead = pNextNode;
            }
            if (pNextNode != nullptr) {
                pNextNode->pPrev = pPrevNode;
            } else {
                pTail = pPrevNode;
            }
            // delete current node
            delete pCurrNode;
        }
    }
}