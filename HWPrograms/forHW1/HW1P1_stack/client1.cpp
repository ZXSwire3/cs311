//CS311 Yoshii F23 client1.cpp
//INSTRUCTION:
//Look for ** to complete this program and comments (Use control-S)
//The output should match my hw1stackDemo.out 
// NEVER delete my comments !!!
//=========================================================
//HW#: HW1P1 stack application (post-fix evaluation)
//Your name: Ben Foltz-Miranda
//Complier:  g++
//File type: client program client1.cpp
//===========================================================

using namespace std;

#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"

//Purpose of the program: **
//Algorithm: **

int main() {
    stack postfixstack;  // integer stack
    string expression;   // user entered expression

    cout << "type a postfix expression: ";
    cin >> expression;

    int i = 0;  // character position within expression
    char item;  // one char out of the expression

    int box1;  // receive things from pop
    int box2;  // receive things from pop

    while (expression[i] != '\0') // til the end of the expression
    {
        try {
            item = expression[i];  // current char

            // ** do all the steps in the algorithm given in Notes-2A


        } // this closes try
            // Catch exceptions and report problems and quit the program now (exit(1)).
            // Error messages describe what is wrong with the expression.
        catch (stack::Overflow) {
            cout << "Error: Expression too long." << endl;
            exit(1);
        }
        catch (stack::Underflow) {
            cout << "Error: Too few operands/numbers." << endl;
            exit(1);
        }
        catch (char const *errormsg) // for invalid item case
        {
            cout << "Error: Invalid item." << endl;
            exit(1);
        }

        // go back to the loop after incrementing i
        i++;
    }// end of while

    // After the loop successfully completes:
    // Pop the result and show it.
    postfixstack.pop(box1);
    // If anything is left on the stack, an incomplete expression
    // was found so also inform the user.
    if (!postfixstack.isEmpty()) {
        cout << "Error: Incomplete expression." << endl;
        exit(1);
    }

}// end of the program
