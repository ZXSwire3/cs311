//CS311 Yoshii F23 llist.h
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// =======================================================
// HW#: HW3P1 llist
// Your name: Ben Foltz-Miranda
// Compiler:  g++ 
// File type: headher file  llist.h
//=======================================================

#include "elem.h"

//a list node is defined here as a struct Node for now
struct Node {
    el_t Elem;   // elem is the element stored
    Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist {

protected:
    Node *Front;       // pointer to the front node
    Node *Rear;        // pointer to the rear node
    int Count;        // counter for the number of nodes

    // utility function to move to a specified node position

    void moveTo(int, Node *&);

public:

    // Exception handling classes
    class Underflow {
    }; // thrown when an element is requested to be deleted but the list is empty

    class OutOfRange {
    }; // thrown when the specified Node is out of range

    llist();     // constructor to create a list object
    ~llist();     // destructor to destroy all nodes

    // Checks if the list is empty
    bool isEmpty();

    // Displays all the elements in the list
    void displayAll();

    // Adds a new element to the front of the list
    void addFront(el_t);

    // Adds a new element to the rear of the list
    void addRear(el_t);

    // Deletes the front element of the list
    void deleteFront(el_t &);


    // Deletes the rear element of the list
    void deleteRear(el_t &);

    //---------------------------------------


    // Deletes a element at the Ith position of the list
    void deleteIth(int, el_t &);  // calls moveTo

    // Adds a new element to the Ith position of the list
    void insertIth(int, el_t);   // calls moveTo

    // Copy Constructor to allow pass by value and return by value of a llist
    llist(const llist &);

    // Overloading of = (returns a reference to a llist)
    llist &operator=(const llist &);
};
