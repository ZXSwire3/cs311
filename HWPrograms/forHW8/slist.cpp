// CS311 Yoshii F23 slist.cpp
// Complete all functions with their comments
// NEVER delete my comments!!
// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: Ben Foltz-Miranda
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

using namespace std;

#include<iostream>
#include"slist.h"

// ** Make sure llist constructor and destructors have couts in them

// do not change this one
slist::slist() {}

// positions always start at 1
int slist::search(el_t key) {
    Node *P = Front; // set P to point to the front node
    int pos = 1; // initialize position
    while (P != NULL) { // while P hasn't reached the end of the list
        if (P->Elem == key) { // if the element at P is the key
            return pos;
        }
        P = P->Next; // move P to the next node
        pos++; // increment position
    }
    return 0; // if the key was not found, return 0
}

el_t slist::search2(el_t key) {
    Node *P = Front; // set P to point to the front node
    int pos = 1; // initialize position
    while (P != NULL) { // while P hasn't reached the end of the list
        if (P->Elem == key) { // if the element at P is the key
            el_t element = P->Elem; // set element to the element at P
            return element;
        }
        P = P->Next; // move P to the next node
        pos++; // increment position
    }

    el_t blank;
    return blank; // if the key was not found, return blank el_t
}

// don't forget to throw OutOfRange for bad pos 
// You must use moveTo to go to the pos
void slist::replace(el_t element, int pos) {
    if (pos < 1 || pos > Count) { // if the position is out of range
        throw OutOfRange(); // throw an OutOfRange exception
    }
    Node *P = Front; // set P to point to the front node
    moveTo(pos, P); // move P to the specified position
    P->Elem = element; // replace the element at P with the new element
}

bool slist::operator==(const slist &OtherOne) {
    // if not the same length, return false immediately
    if (this->Count != OtherOne.Count) {
        return false;
    }
    // if the same lengths,
    // check each node to see if the elements are the same
    Node *P = Front; // set P to point to the front node
    Node *OP = OtherOne.Front; // set OP to point to the front node of the other list
    while (P != NULL) { // while P hasn't reached the end of the list
        if (P->Elem != OP->Elem) { // if the elements at P and OP are not the same
            return false;
        }
        P = P->Next; // move P to the next node
        OP = OP->Next; // move OP to the next node
    }
    return true; // if all elements were the same, return true
}
