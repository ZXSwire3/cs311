//CS311 Yoshii F23 dgraph.cpp 
// INSTRUCTION:
//   Complete all the functions you listed in dgraph.h
//   Comment the file completely using How to Comment file.
//   Use HW6-help.docx to finish the functions.
//  NEVER delete my comments!!!
//-------------------------------------------------------

//======================================================
// HW#: HW6 dgraph
// Name: **
// File Type: **
//========================================================

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include "dgraph.h"

dgraph::dgraph()
 // initialize vertexName (blank) and visit numbers (0) for all slots of the table
// - need a loop
 // initialize countUsed to be 0
{
}

dgraph::~dgraph()   // do we have to delete all nodes of slists in table??
// Question: If we do not do this, will the llist destructor be called automatically??? Try it.
{
}

void dgraph::fillTable()  // be sure to read from a specified file
// you will have to use a linked list function addRear. 
{
  string fname;
  cout << "Enter a file name: ";
  cin >> fname;
  ifstream fin (fname.c_str(), ios::in); // declare and open fname

  // the rest is in HW6-help


}
void dgraph::displayGraph() // be sure to display
// you will have to use a linked list function displayAll. 
{// in a really nice table format -- all columns but no unused rows and include the total number of edges at the top (you have to sum it up)
} 

int dgraph::findOutDegree(char V)// throws exception if not found
{// does not use a loop - go directly to a slot using V
}

slist dgraph::findAdjacency(char V)// throws exception if not found
{// does not use a loop - go directly to a slot using V
}
