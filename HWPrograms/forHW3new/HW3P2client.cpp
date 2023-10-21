//CS311 Yoshii F23 HW3P2client.cpp
//INSTRUCTION:
// Read the whole file first.
//Look for ** to complete all of them.
//The output should match my assingment sheet. Check!!!
//DO not forget to Tab on each line
// NEVER delete my comments!!
//=========================================================
//HW#: HW3P2 slist
//Your name: Ben Foltz-Miranda
//Complier:  g++
//File type: client program (tester) HW3P2client.cpp
//===========================================================

using namespace std;

#include <iostream>
#include "slist.h"
#include <stdlib.h>

//PURPOSE: Testing search and replace functions
void testOne() {
    slist L;  // the list
    int foundPos; // to hold the found position from Search
    int counter = 1; // used to display test line number

    try {
        //  1)add to front once (element 4)
        cout << endl << "Step " << counter << ": add 4 to front" << endl;
        L.addFront(4);
        counter++;

        //  2)add to rear 3 times (elements 6,7,8)
        cout << "Step " << counter << ": add to rear 3 times (6, 7, 8)" << endl;
        counter++;
        L.addRear(6);
        L.addRear(7);
        L.addRear(8);

        //  3)displayAll - 4 6 7 8
        cout << "Step " << counter << ": displayAll" << endl;
        counter++;
        L.displayAll();

        //  4)search for 6, report the result  - found in pos 2
        cout << endl << "Step " << counter << ": search list for 6" << endl;
        counter++;
        foundPos = L.search(6);
        cout << " - Found 6 in location " << foundPos << endl;

        //  5)replace the 6 with 0 using the search result (foundPos)
        cout << endl << "Step " << counter << ": replace 6 with 0" << endl;
        counter++;
        L.replace(0, foundPos);

        // 6)displayAll - 4 0 7 8
        cout << "Step " << counter << ": displayAll" << endl;
        counter++;
        L.displayAll();

        // 7)search for 8 and report the result - found in pos 4
        cout << endl << "Step " << counter << ": search list for 8" << endl;
        counter++;
        foundPos = L.search(8);
        cout << " - Found 8 in location " << foundPos << endl;

        // 8)replace the 8 with 2 using the search result (foundPos)
        cout << endl << "Step " << counter << ": replace 8 with 2" << endl;
        counter++;
        L.replace(2, foundPos);

        // 9)displayAll - 4 0 7 2
        cout << "Step " << counter << ": displayAll" << endl;
        counter++;
        L.displayAll();

        // 10)search for 5 and report the result   - not found
        cout << endl << "Step " << counter << ": search list for 5" << endl;
        counter++;
        foundPos = L.search(5);
        cout << " - Found 5 in location " << foundPos << endl;

        // 11) replace position 7 with 10
        cout << "Step " << counter << ": replace position 7 with 10" << endl;
        counter++;
        L.replace(10, 7);
    } catch (llist::OutOfRange) {
        cout << "ERROR: Bad position was given" << endl;
    }
}//end of testOne

// PURPOSE: Testing overloading of ==
void testTwo() {
    slist L1, L2;
    int counter = 1;

    //1. L1 is empty and L2 is empty
    cout << endl << "Step " << counter++ << ": check if L1 == L2 (true)" << endl
         << " - ";
    if (L1 == L2) cout << "true" << endl; else cout << "false" << endl;

    //2. L1 is empty and L2 with 4, 5
    cout << "Step " << counter++ << ": add to L2 rear 2 times (4, 5); check if L1 == L2 (false)" << endl
         << " - ";
    L2.addRear(4);
    L2.addRear(5);
    if (L1 == L2) cout << "true" << endl; else cout << "false" << endl;

    //3.  The opposite
    cout << "Step " << counter++ << ": check if L2 == L1 (false)" << endl
         << " - ";
    if (L2 == L1) cout << "true" << endl; else cout << "false" << endl;

    //4. L1 with 1,2,3 and L2 with  1,2,3
    cout << "Step " << counter++ << ": add to L1 rear 3 times (1, 2, 3);\n"
                                    " remove L2 front 2 times;\n"
                                    " add to L2 rear 3 times (1, 2, 3);\n"
                                    " check if L1 == L2 (true)" << endl
         << " - ";
    L1.addRear(1);
    L1.addRear(2);
    L1.addRear(3);
    int x;
    L2.deleteFront(x);
    L2.deleteFront(x);
    L2.addRear(1);
    L2.addRear(2);
    L2.addRear(3);
    if (L1 == L2) cout << "true" << endl; else cout << "false" << endl;

    //5. L1 with 1,2,3 and L2 with  1,2
    cout << "Step " << counter++ << ": remove L2 rear 1 time;\n"
                                    " check if L1 == L2 (false)" << endl
         << " - ";
    L2.deleteRear(x);
    if (L1 == L2) cout << "true" << endl; else cout << "false" << endl;

    //6. L1 has 1,2,3 and L2 has 1,2,3,4
    cout << "Step " << counter++ << ": add to L2 rear 2 times (3, 4);\n"
                                    " check if L1 == L2 (false)" << endl
         << " - ";
    L2.addRear(3);
    L2.addRear(4);
    if (L1 == L2) cout << "true" << endl; else cout << "false" << endl;

    //7. L1 has 1,2,3 and L2 has 1,2,4
    cout << "Step " << counter++ << ": remove L2 rear 2 times;\n"
                                    " add to L2 rear 1 time (4);\n"
                                    " check if L1 == L2 (false)" << endl
         << " - ";
    L2.deleteRear(x);
    L2.deleteRear(x);
    L2.addRear(4);
    if (L1 == L2) cout << "true" << endl; else cout << "false" << endl;

}//end of testTwo


//PURPOSE: to test slist thoroughly
int main() {
    testOne(); // for search and replace

    cout << endl << "---- First Part testing done ----- " << endl << endl;

    testTwo();  // for testing ==

}// end of program

