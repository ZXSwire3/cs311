// CS311 Yoshii F23 - HW5 Priority Queue Implementation File
// Complete all ** parts and give good comments
// ** NEVER delete my comments.

// =================================================
// HW5 Priority Printer Queue 
// YOUR NAME: Ben Foltz-Miranda
// File Type: implementation pqueue.cpp
// =================================================

#include "pqueue.h"

// constructor
pqueue::pqueue() {
    count = 0;  // no jobs yet
}

// destructor does nothing
pqueue::~pqueue() {}

// Purpose: to add a job to a right place in the Pqueue
// Argument: j is the job priority number
// Remember that the current last job is in slot count-1.
void pqueue::insertjob(int j) {
    cout << "Adding: " << j << endl;

    if (count == MAX) { // if impossible else display error message.
        cout << "Heap full, cannot add" << endl;
        return;
    } else { //  add the job j at the rear (and update count)
        Q[count++] = j;
    }
    trickleup(); // moves the job to the right place
}

// Purpose: to print a job and reheapify the Pqueue
void pqueue::printjob() {
    cout << "Printing: " << Q[0] << endl;
    reheapify();
}

// Purpose: to display all jobs
void pqueue::displayAll() {
    cout << "Jobs: ";
    // loop to display jobs from slot 0 to slot count-1 horizontally. No need to show a tree format.
    for (int i = 0; i <= count - 1; i++) {
        cout << Q[i] << " ";
    }
    cout << endl;

    // show queue in tree format
    int level = 0;
    int blanks = count - level;
    printblanks(blanks); // prints the appropriate number of blanks before printing the first job
    cout << Q[0] << endl; // prints the first job
    level = 1; // level is now 1
    int s = 1;
    while (s < count) { // while s is less than the number of jobs
        blanks = blanks - (level * 2); // calculates the number of blanks to print
        printblanks(blanks); // prints the appropriate number of blanks before printing the next job
        for (int i = 1; i <= pow(2, level); i++) { // loops through the number of jobs at the current level
            if (s < count) cout << Q[s] << " "; // prints the next job if s is less than the number of jobs
            s++; // increments s
        }
        level++; // increments level
        cout << endl;
    }
}


// Utility functions follow: ------------------

void pqueue::swap(int loc1, int loc2) {
    //  simply swap the values in these locations in Q
    int temp = Q[loc1]; // temp is a temporary place holder for the value in Q[loc1]
    Q[loc1] = Q[loc2]; // Q[loc1] is now equal to Q[loc2]
    Q[loc2] = temp; // Q[loc2] is now equal to temp
}

// Purpose: to make the very last job trickle up to the right location.
// Never do X--. 
void pqueue::trickleup() {
    int x = count - 1;  // the very last job's location
    //  While x is > 0
    //    compare Q[x] with the parent value (*)
    //    and if the parent value is bigger call swap & update x
    //    to be the parent location. Otherwise stop the loop.
    // (*) Call getParent to get the location of the parent
    //            based on the child's location.
    while (x > 0) {
        if (Q[x] < Q[getParent(x)]) {
            swap(x, getParent(x));
            x = getParent(x);
        } else {
            break;
        }
    }
}

// Purpose: find the location of the parent 
// The child location is given.  Need to call even.
int pqueue::getParent(int childloc) {
    //  return the parent location based on the child loc
    if (even(childloc)) {
        return (childloc - 2) / 2;
    } else {
        return (childloc - 1) / 2;
    }
}

// Purpose: is location i even? Important in finding its parent location
bool pqueue::even(int i) {
    if ((i % 2) == 0) return true; else return false;
}

// Purpose: to reheapify the Pqueue after printing
//  This trickles down.  Never do X++.
void pqueue::reheapify() {
    int X;   // the current location
    Q[0] = Q[count - 1];  // move the last job to the front
    count--;
    //  Start X at 0 (the root)
    X = 0;
    //  While X is within the array (the used portion):
    //       Find the location of the smaller child by calling getSmallerchild.
    //       (if the location of both children are off the tree, stop the loop).
    //       If the smaller child is smaller than the parent value,
    //          call swap and X becomes the smaller child's location.
    //       else no swaps so stop to loop.
    while (X < count) {
        int smallerChild = getSmallerchild(X);
        if (smallerChild == -1) {
            break;
        } else if (Q[smallerChild] < Q[X]) {
            swap(X, smallerChild);
            X = smallerChild;
        } else {
            break;
        }
    }
}

// Purpose: to find the location of the smaller child
// where children are at locations 2*i+1 and 2*i+2
int pqueue::getSmallerchild(int i) {
    int LC, RC; // locations of children
    // set LC and RC first.
    LC = 2 * i + 1;
    RC = 2 * i + 2;

//    return the location of the smaller child 
    if (LC > count - 1 && RC > count - 1) { //  if both are off the tree, return -1
        return -1;
    } else if (LC > count - 1) { //  if LC is off the tree, return RC
        return RC;
    } else if (RC > count - 1) { //  if RC is off the tree, return LC
        return LC;
    } else if (Q[LC] < Q[RC]) { //  otherwise return the location of the smaller child
        return LC;
    } else { //  otherwise return the location of the smaller child
        return RC;
    }
//    Be careful because one or both of them may be
//    beyond count-1 or just the RC is beyond count-1.
//    Check LC and RC against boundaries before you 
//    compare Q contents!!!!
//    If both are beyond count-1, you want to return a special value.
}
// NEVER GO TO UNUSED PART OF THE ARRAY 

void pqueue::printblanks(int blanks) {
    for (int i = 0; i < blanks; i++) {
        cout << " ";
    }
}