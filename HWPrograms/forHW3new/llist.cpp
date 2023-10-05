//CS311 Yoshii F23 Linked List class

//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//  You can copy from a Word document to emacs (contrl-right click)
//  Highly recommended to copy HW3P1-help as PURPOSE of each function.
//
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//  NEVER delete my comments!!!!
//EMACS HINT:
//  cntr-K cuts and cntr-Y pastes. 
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Ben Foltz-Miranda
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;

#include<iostream>
#include"llist.h"

// llist constructor
llist::llist() {
    cout << "calling the llist constructor..." << endl;
    // initialize Front and Rear to be NULL and Count = 0.
    Front = NULL;
    Rear = NULL;
    Count = 0;
}

// llist destructor
llist::~llist() {
    cout << "calling the llist destructor..." << endl;
    // while (!isEmpty()) deleteFront();
    el_t temp;
    while (!isEmpty()) deleteFront(temp);
}

//PURPOSE: Checks if the list is empty
//PARAMETER: None
bool llist::isEmpty() { // be sure to check all 3 data members
    return Front == NULL && Rear == NULL && Count == 0;
}

//PURPOSE: Displays all the elements in the list
//PARAMETER: None
void llist::displayAll() {
    // special case: if the list is empty, display [ empty ]
    if (isEmpty()) {
        cout << "[ empty ]" << endl;
        return;
    }
    cout << "[ ";
    Node *P = Front;
    while (P != NULL) { // while not end of list
        cout << P->Elem << " ";
        P = P->Next;
    }
    cout << "]" << endl;
}  // be sure to display horizontally in [  ] with
// blanks between elements e.g. [ 1 2 3 4]
// You MUST use while (P != NULL) loop or you will not get the credit!

//PURPOSE: Adds a new element to the rear of the list
//PARAMETER NewNum - the element to be added to the rear of the list
void llist::addRear(el_t NewNum) {
    // Special case: if this is going to be the very first node, you must create a new node and make Front and Rear
    // point to it. Place NewNum and Count is updated.
    if (isEmpty()) {
        Front = new Node;
        Front->Elem = NewNum;
        Front->Next = NULL;
        Rear = Front;
        Count++;
        return;
    }
    // Regular: adds a new node at the rear and puts NewNum in the Elem field of this new node. Count is updated.
    Rear->Next = new Node;
    Rear = Rear->Next;
    Rear->Elem = NewNum;
    Rear->Next = NULL;
    Count++;
} // comment the 2 cases

//PURPOSE: Adds a new element to the front of the list
//PARAMETER: NewNum - the element to be added to the front of the list
void llist::addFront(el_t NewNum) {
    // Special case: if this is going to be the very first node, you must create a new node and make Front and Rear
    // point to it. Place NewNum and Count is updated.
    if (isEmpty()) {
        Front = new Node;
        Front->Elem = NewNum;
        Front->Next = NULL;
        Rear = Front;
        Count++;
        return;
    }
    // Regular: add a new node to the front of the list and
    //          Count is updated.
    Node *temp = new Node;
    temp->Elem = NewNum;
    temp->Next = Front;
    Front = temp;
    Count++;
} // comment the 2 cases

//PURPOSE: Deletes the front element of the list
//PARAMETER: OldNum - the element that is deleted from the front of the list
void llist::deleteFront(el_t &OldNum) {
    // Error case: if the List is empty, throw Underflow
    if (isEmpty()) throw Underflow();
    // Special case: if currently only one Node, give back the front node element through OldNum (pass by reference) and
    //               make sure both Front and Rear become NULL.
    if (Count == 1) {
        OldNum = Front->Elem;
        delete Front;
        Front = NULL;
        Rear = NULL;
        Count--;
        return;
    }
    // Regular: give back the front node element through OldNum (pass by reference) and also removes the front node.
    //          Count is updated.
    OldNum = Front->Elem;
    Node *temp = Front;
    Front = Front->Next;
    delete temp;
    Count--;
} // comment the 3 cases

//PURPOSE: Deletes the rear element of the list
//PARAMETER: OldNum - the element that is deleted from the rear of the list
void llist::deleteRear(el_t &OldNum) {
    // Error case: if empty, throw Underflow
    if (isEmpty()) throw Underflow();
    // Special case: if currently only one node, give back the rear node element through OldNum (pass by reference) and
    // make sure both Front and Rear become NULL.
    if (Count == 1) {
        OldNum = Rear->Elem;
        delete Rear;
        Front = NULL;
        Rear = NULL;
        Count--;
        return;
    }
    // Regular: give back the rear node element through OldNum (pass by reference) and also remove the rear node.
    // Count is updated.
    OldNum = Rear->Elem;
    Node *temp = Front;
    while (temp->Next != Rear) temp = temp->Next;
    delete Rear;
    Rear = temp;
    Rear->Next = NULL;
    Count--;
} // comment the 3 cases

/* --- harder ones for case 2 and 3 follow -- */

// Utility Function to move a local pointer to the Jth node
void llist::moveTo(int J, Node *&temp) { // moves temp J-1 times to go to the Jth node
    // for ( int K = ... ) temp = temp->Next;
    for (int K = 0; K <= J-1; ++K) {
        temp = temp -> Next;
    }
}

//PURPOSE: Deletes a element at the Ith position of the list
//PARAMETER: I - the index of the element to be deleted from the Ith position of the list
//           OldNum - the element that is deleted from the Ith position of the list
void llist::deleteIth(int I, el_t &OldNum) {
    // use moveTo to move local pointers. Be sure to comment to which node you are moving them.
    // Error cases: If I is an illegal value (i.e. > Count or < 1) throw OutOfRange.
    if (I > Count || I < 1) throw OutOfRange();
    // (note: this may simply call moveTo() then use an if-else)
    // Special cases: this should simply call deleteFront when I == 1
    //                this should simply call deleteRear when I == Count
    if (I == 1) {
        deleteFront(OldNum);
        return;
    }
    if (I == Count) {
        deleteRear(OldNum);
        return;
    }
    // Regular: delete the Ith node (I starts out at 1).  Count is updated.
    //          OldNum is set to the element of the Ith node.
    //          Node is deleted and recycled.
    //          Be sure to comment to which node you are moving them.
    Node *temp = Front;
    moveTo(I-1, temp);
    OldNum = temp->Next->Elem; // set OldNum to the element of the Ith node
    temp->Next = temp->Next->Next; // delete the Ith node by setting the I-1th node's next to the I+1th node
    Count--;
}

//PURPOSE:
//PARAMETER:
void llist::insertIth(int I, el_t newNum) {
    // use moveTo to move local pointers. Be sure to comment to which node you are moving them.
    // Error cases: If I is an illegal value (i.e. > Count+1 or < 1) throw OutOfRange.
    if (I > Count+1 || I < 1) throw OutOfRange();
    // (note: this may simply call moveTo() then use an if-else)
    // Special cases: this should simply call addFront when I == 1
    //                this should simply call addRear when I == Count+1
    if (I == 1) {
        addFront(newNum);
        return;
    }
    if (I == Count+1) {
        addRear(newNum);
        return;
    }
    // Regular: add right before the Ith node. Cout if updated.
    //          Be sure to comment to which node you are moving them.
    Node *temp = Front;
    moveTo(I-1, temp);
    Node *temp2 = new Node; // create a new node
    temp2->Elem = newNum; // set the new node's element to newNum
    temp2->Next = temp->Next; // set the new node's next to the Ith node
    temp->Next = temp2; // set the I-1th node's next to the new node
    Count++;
}

//PURPOSE:
//PARAMETER:
llist::llist(const llist &Original) {
    //  this->'s data members need to be initialized here first
    Front = NULL; Rear = NULL; Count = 0;
    //  this-> object has to be built up by allocating new cells
    //  and copying the values from Original into each cell as we did with
    //  operator= above. To do this,
    // copy here the (**) lines in Operator Overloading of = but note that it is Original and not OtherOne.
    // this-> object has to be built up by allocating new cells with OtherOne elements (**)
    Node* P;  // local pointer for OtherOne
    P = Original.Front;
    while (P != NULL)  // a loop which repeats until you reach the end of OtherOne.
    {
        this->addRear(P -> Elem);    //P’s element is added to this->
        P = P->Next;                         // Go to the next node in OtherOne
    }
    //  Nothing to return because this is a constructor.

} // use my code

//PURPOSE:
//PARAMETER:
llist &llist::operator=(const llist &OtherOne) {
    el_t x;
    // First make sure this-> and OtherOne are not the same object.
    // To do this, compare the pointers to the objects .
    if (&OtherOne != this)  // if not the same
    {
        // this-> object has to be emptied first.
        while (! this->isEmpty() )
            this->deleteRear(x);
        // this-> object has to be built up by allocating new cells with OtherOne elements (**)
        Node* P;  // local pointer for OtherOne
        P = OtherOne.Front;
        while (P != NULL)  // a loop which repeats until you reach the end of OtherOne.
        {
            this->addRear(P -> Elem);    //P’s element is added to this->
            P = P->Next;                         // Go to the next node in OtherOne
        }
    }// end of if
    return *this;    // return the result unconditionally.  Note that the result is returned by reference.
} // use my code

