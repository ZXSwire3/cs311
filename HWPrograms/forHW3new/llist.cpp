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
//Your name: **
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 

llist::llist()
{ cout << "... in llist constructor..." << endl; }

llist::~llist()
{ cout << ".... in llist destructor..." << endl; }

//PURPOSE:
//PARAMETER:
bool llist::isEmpty() { } // be sure to check all 3 data members

//PURPOSE:
//PARAMETER:
void llist::displayAll() { }  // be sure to display horizontally in [  ] with
// blanks between elements e.g. [ 1 2 3 4]
// You MUST use while (P != NULL) loop or you will not get the credit!
  
//PURPOSE:
//PARAMETER:
void llist::addRear(el_t NewNum) { } // comment the 2 cases

//PURPOSE:
//PARAMETER:
void llist::addFront(el_t NewNum) { } // comment the 2 cases

//PURPOSE:
//PARAMETER:
void llist::deleteFront(el_t& OldNum) { } // comment the 3 cases

//PURPOSE:
//PARAMETER:
void llist::deleteRear(el_t& OldNum){} // comment the 3 cases



/* --- harder ones for case 2 and 3 follow -- */

// Utility Function to move a local pointer to the Jth node
void llist::moveTo(int J, Node*& temp)
{ // moves temp J-1 times to go to the Jth node  
  // for ( int K = ... ) temp = temp->Next;
}

//PURPOSE:
//PARAMETER:
void llist::deleteIth(int I, el_t& OldNum) { } // must use moveTo to move local pointers. Be sure to comment to which node you are moving them. Do not forget to set OldNum.  

//PURPOSE:
//PARAMETER:
void llist::insertIth(int I, el_t newNum) { } // must use moveTo to move local pointers. Be sure to comment to which node you are moving them.

//PURPOSE:
//PARAMETER:
llist::llist(const llist& Original) { } // use my code

//PURPOSE:
//PARAMETER:
llist& llist::operator=(const llist& OtherOne) { } // use my code

