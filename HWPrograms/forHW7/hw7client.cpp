// CS311 YOSHII F23 hw7client.cpp

//==========================================
// HW#: HW7 DFS client using dgraph.h
// Name: Ben Foltz-Miranda
// File type: client hw7client.cpp 
//==========================================

// ** Be sure to include both dgraph  and stack
#include "dgraph.h"
#include "stack.h"

// This client uses the dgraph class and stack class
// to do depth first traversal of the graph stored in table.txt
int main() {
    // ** copy here the algorithm (read carefully) in the HW7
    // assignment sheet and use that for the comments.

    dgraph dgraph; // create a graph object
    dgraph.fillTable(); // fill the table from table.txt
    dgraph.displayGraph(); //Display the graph before DFS begins.

    stack stack; // create a stack object
    //Push A onto the stack to start.
    stack.push('A');

    char vertex; // variable to hold the vertex

    int visits = 1; // initialize the visit number to 1

    while (!stack.isEmpty()) { // While the stack is not empty do:
        //Remove a vertex v from the stack.
        stack.pop(vertex);

        //Display the vertex name.  E.dgraph. “Removed B from stack”
        cout << "Removed " << vertex << " from stack" << endl;

        if (!dgraph.isMarked(vertex)) { //If v is not marked yet (visit number is 0) then
            //•	mark it (visit it **) and inform the user E.dgraph. “Visit B as 1”.
            dgraph.visit(visits, vertex);
            cout << "Visit " << vertex << " as " << visits++ << endl;

            //•	get its adjacency list (slist)
            slist l1 = dgraph.findAdjacency(vertex);

            //o	if no adjacent ones inform the user E.dgraph. “Deadend reached – backup”
            if (l1.isEmpty()) {
                cout << "Deadend reached - backup" << endl;
            } else { //o else put adjacent ones on the stack (delete from the rear and push) informing the user
                cout << "...pushing ";
                l1.displayAll(); // display the adjacent ones

                while (!l1.isEmpty()) { // while the adjacent list is not empty
                    l1.deleteRear(vertex); // delete the rear of the list
                    stack.push(vertex); // push the vertex onto the stack
                }
            }
        } else { //else inform the user E.dgraph. “B had been visited already - backup.”
            cout << vertex << " had been visited already - backup" << endl;
        }
        //Display the stack clearly labeling it as the current stack
        stack.displayAll();
    }
    //Display the Graph nicely with visit numbers for all vertices.
    dgraph.displayGraph();
}