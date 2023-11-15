// CS311 Yoshii F23 hw6client.cpp
// HW6 Client file 
// INSTRUCTION: Complete this file and comment using How to Comment file.
//---------------------------------------------

// ================================================
// HW#: HW6 dgraph client 
// Name: Ben Foltz-Miranda
// File type: client program (tester) hw6client.cpp
// ================================================

#include<iostream>
#include "dgraph.h" // includes

int main() {
    //**
    //0.Declare dgraph object
    dgraph G;
    //1.fillTable()
    G.fillTable();
    //2.displayGraph()
    G.displayGraph();

    // Prompt the user to input a vertex name
    string userInput;
    cout << "Enter a vertex name or 'quit' to exit: ";
    cin >> userInput;
    //while (the user does not want to stop)
    while (userInput != "quit") {
        //a.the user will specify which vertex
        char vertex = toupper(userInput[0]);

        try { //c.catch exception to display error mesg but do not exit
            //b.findOutDegree of the vertex and display the result
            cout << "Out degree of " << vertex << " is " << G.findOutDegree(vertex) << endl;
            //b.findAdjacency of the vertex and display the result (see Hint)
            slist l1;
            l1 = G.findAdjacency(vertex);
            // how do you display l1?  Hint: it is an slist from HW3.
            l1.displayAll();
        } catch (dgraph::BadVertex) {
            cout << "n/a - Vertex not found" << endl;
        }

        // prompt user for next vertex
        cout << "Enter a vertex name or 'quit' to exit: ";
        cin >> userInput;
    } // end of while
}

/*
Hint:
  slist l1;
  l1 = G.findAdjacency('a');
  // how do you display l1?  Hint: it is an slist from HW3.

*/
