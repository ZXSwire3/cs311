//CS311 Yoshii F23 client2.cpp
//INSTRUCTION:
//Look for ** to complete this program and comments.
//The string output should match my hw1queueDemo.out 
// NEVER delete my comments!!!!
//=========================================================
//HW#: HW1P2 queue application (generate all strings)
//Your name: Ben Foltz-Miranda
//Compiler:  g++
//File type: client program client2.cpp
//===========================================================

using namespace std;

#include <iostream>
#include <stdlib.h>
#include <string>
#include "queue.h"

//Purpose of the program: find all possible strings of A, B, and C
//Algorithm: while loop with a try-catch block inside
// add "A", "B", "C" to the queue
// while the queue is not empty or full
// remove the first value from the queue
// display the removed value
// add removed value + "A" to the queue
// add removed value + "B" to the queue
// add removed value + "C" to the queue

int main() {
    queue queue;
    //  place "A", "B", "C" in the queue
    queue.add("A");
    queue.add("B");
    queue.add("C");

    while(true) { //  while loop -- indefinitely while(true)
        try {
            string currentString; // hold value that is removed
            queue.remove(currentString); // remove first value
            cout << currentString << endl; // display removed value

            queue.add(currentString + "A"); // add A to currentString and add to queue
            queue.add(currentString + "B"); // add B to currentString and add to queue
            queue.add(currentString + "C"); // add C to currentString and add to queue

        } catch (queue::Overflow) { // if there is an overflow, the queue is full, so exit the program
            cout << "Cannot add";
            exit(1);
        }
        catch (queue::Underflow) { // if there is an underflow, the queue is empty, so exit the program
            cout << "Cannot remove";
            exit(1);
        }
    }// end of loop
}

