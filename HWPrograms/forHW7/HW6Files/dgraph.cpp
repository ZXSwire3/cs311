//CS311 Yoshii F23 dgraph.cpp 
// INSTRUCTION:
//   Complete all the functions you listed in dgraph.h
//   Comment the file completely using How to Comment file.
//   Use HW6-help.docx to finish the functions.
//  NEVER delete my comments!!!
//-------------------------------------------------------

//======================================================
// HW#: HW6 dgraph
// Name: Ben Foltz-Miranda
// File Type: implementation file dgraph.cpp
//========================================================

using namespace std;

#include <iostream>
#include <fstream>
#include <string>
#include "stdlib.h"
#include "dgraph.h"

dgraph::dgraph() {
    // initialize vertexName (blank) and visit numbers (0) for all slots of the table
    for (int i = 0; i < SIZE; i++) {
        Gtable[i].vertexName = ' ';
        Gtable[i].visit = 0;
    }

    countUsed = 0; // initialize countUsed to be 0
}

dgraph::~dgraph() {  // do we have to delete all nodes of slists in table??
// Question: If we do not do this, will the llist destructor be called automatically??? Try it.
}

void dgraph::fillTable() { // be sure to read from a specified file
    // you will have to use a linked list function addRear.
    string fname;
    cout << "Enter the file name: ";
    cin >> fname;
    ifstream fin(fname.c_str(), ios::in); // declare and open fname

    if (!fin) { // if the file is not found exit program
        cout << "File not found" << endl;
        exit(0);
    }

    while (fin >> Gtable[countUsed].vertexName) { // IF I CAN READ THE NAME
        // read outDegree
        fin >> Gtable[countUsed].outDegree;
        for (int i = 0; i < Gtable[countUsed].outDegree; i++) {
            char x;
            // read adjacents
            fin >> x;
            (Gtable[countUsed].adjacentOnes).addRear(x);   // this is a slist function from HW3
        }
        countUsed++;
    }
    fin.close(); // close file
    // the rest is in HW6-help
}

void dgraph::displayGraph() { // be sure to display
// you will have to use a linked list function displayAll.

    // calculate the number of edges first
    int edges = 0;
    for (int i = 0; i < countUsed; ++i) {
        edges += Gtable[i].outDegree;
    }

    cout << "** The number of edges is: " << edges << endl;
    cout << "  Out Visit Adj" << endl <<
         " -----------------------" << endl;
//  for each Gtable slot:
    for (int i = 0; i < countUsed; i++) {
        cout << Gtable[i].vertexName << " " << Gtable[i].outDegree << "     " << Gtable[i].visit << " ";
        (Gtable[i].adjacentOnes).displayAll(); // display vertically
    }
// in a really nice table format -- all columns but no unused rows and include the total number of edges at the top (you have to sum it up)
}

int dgraph::findOutDegree(char V) { // throws exception if not found
    // does not use a loop - go directly to a slot using V
    int index = V - 'A'; // Convert the vertex character to an index
    if (index >= 0 && index < countUsed && Gtable[index].vertexName == V) {
        return Gtable[index].outDegree;
    }
    throw BadVertex(); // If the vertex is not found or the index is out of range, throw an exception
}

slist dgraph::findAdjacency(char V) {// throws exception if not found
    // does not use a loop - go directly to a slot using V
    int index = V - 'A'; // Convert the vertex character to an index
    if (index >= 0 && index < countUsed && Gtable[index].vertexName == V) {
        return Gtable[index].adjacentOnes;
    }
    throw BadVertex(); // If the vertex is not found or the index is out of range, throw an exception
}

void dgraph::visit(int visitNumber, char V) {
    // does not use a loop - go directly to a slot using V
    int index = V - 'A'; // Convert the vertex character to an index
    if (index >= 0 && index < countUsed && Gtable[index].vertexName == V) {
        Gtable[index].visit = visitNumber;
    }
}

bool dgraph::isMarked(char V) {
    // does not use a loop - go directly to a slot using V
    int index = V - 'A'; // Convert the vertex character to an index
    if (index >= 0 && index < countUsed && Gtable[index].vertexName == V) {
        return Gtable[index].visit != 0;
    }
}