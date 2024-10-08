// CS311 Yoshii F23 slist.h
// HW3P2 Instruction: Inherit everything publicly from llist
// Put only the following in class slist.h 
//    inheriting everything from llist.h
//
// Then create slist.cpp with only the following functions
// Complete all ** parts 
//=================================================
// HW#: HW3P2 slist
// Name: Ben Folz-Miranda
// File: header file for slist class
//=================================================

#include "llist.h"  // for includes

class slist : public llist {

public:

    slist();   // constructor. cout "in slist constructor".
    // Make it do nothing else.
    // Experiment and see what happens.
    // Taking this out completely would not work.
    // But note that there is no destructor.
    // PLEASE DO NOT delete the couts in slist and llist
    // constructors and destructors for HW6!!!!!

    int search(el_t);
    // search through the list to see if any node contains the key.
    // If so, return its position (>=1). Otherwise, return 0.

    el_t search2(el_t);
    // search through the list to see if any node contains the key.
    // If so, return the element. Otherwise, return a blank element.

    void replace(el_t, int);
    // go to the Ith node (if I is between 1 and Count) and
    // replace the element there with the new element.
    // If I was an illegal value, throw OutOfRange

    bool operator==(const slist &);
    // checks to see of the two lists look the same
};
