#include "LinkedList.hpp"
#include "Node.hpp"

#include <iomanip>
#include <iostream>
using namespace std;

void printList(LinkedList<int>* myList) {
    if (myList == nullptr) {
        cout << "LinkedList is null" << endl;
    }
    int lSize = myList->size();
    for (int i = 0; i < lSize; ++i) {
        cout << "Element at position " << i << ": " << myList->get(i) << endl;
    }
    cout << endl;
}

void printSize(LinkedList<int>* List) {
    int lSize = List->size();
    cout << "LinkedList size: " << lSize << endl;
}

int main() {
    // create a linked list in free store
    LinkedList<int>* myList = new LinkedList<int>();

    // create linked list
    myList->insert(0, 6);
    myList->insert(0, 5);
    myList->insert(5, 7);
    myList->insert(-3, 1);
    myList->insert(1, 2);
    myList->insert(2, 9);
    myList->insert(2, 3);

    // print elements from the list forwards
    printList(myList);
    myList->set(3, 4);
    printList(myList);
    myList->remove(-2);
    myList->remove(9);
    myList->remove(2);
    int atPos = myList->get(2);
    cout << "Item at position 2: " << atPos << endl;
    printSize(myList);
    printList(myList);

    LinkedList<int>* myList2 = new LinkedList<int>();
    
    myList2 = myList;
    printSize(myList);
    printSize(myList2);
    myList->insert(0, 1);
    myList->insert(0, 0);
    printSize(myList);
    printSize(myList2);

    LinkedList<int>* copyList(myList);
    //printList(&copyList);

    LinkedList<int>* copyList2(myList);
    //printList(&copyList2);

    myList->insert(10, 8);
    myList->insert(10, 9);

    printSize(myList);
    printSize(myList2);
    printSize(copyList2);
    
    delete myList;
    delete myList2;
    delete copyList;
    delete copyList2;

    //LinkedList<string>* stringList = new LinkedList<string>();
    //myList->insert(0, "Hello");
    //myList->insert(1, "World");
    //printList(stringList);

    return 0;
}