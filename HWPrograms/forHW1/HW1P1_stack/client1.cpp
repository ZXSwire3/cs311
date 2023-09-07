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

//Purpose of the program:
// This program evaluates postfix expressions.
// It takes a postfix expression from the user and evaluates it.
// Algorithm: while loop with a try-catch block inside
// loop through each character in the expression
// if the character is an operand, push it onto the stack
// if the character is an operator, pop the first two operands and perform the operation on them
// if the character is not an operand or operator, throw an exception
// after the loop, pop the result and display it
// if anything is left on the stack, the expression is incomplete, so throw an exception

int main() {
    stack postfixstack;  // integer stack
    string expression;   // user entered expression

    while (true) { // loop until the user enters "quit"
        beginning:

        cout << "type a postfix expression: ";
        cin >> expression;

        int i = 0;  // character position within expression
        char item;  // one char out of the expression

        int box1;  // receive things from pop
        int box2;  // receive things from pop

        if (expression == "quit") { // if the user enters "quit", exit the program
            exit(1);
        }

        while (expression[i] != '\0') // til the end of the expression
        {
            try {
                item = expression[i];  // current char

                // do all the steps in the algorithm given in Notes-2A
                if (item >= '0' && item <= '9') { // if item is an operand (number)
                    postfixstack.push(int(item) - 48);
                } else if (item == '*' || item == '+' || item == '-') { // if item is an operator
                    postfixstack.pop(box1); // pop the first operand
                    postfixstack.pop(box2); // pop the second operand
                    if (item == '*') { // if item is multiplication
                        postfixstack.push(box2 * box1);
                    } else if (item == '+') { // if item is addition
                        postfixstack.push(box2 + box1);
                    } else if (item == '-') { // if item is subtraction
                        postfixstack.push(box2 - box1);
                    }
                } else { // if item is not an operand or operator
                    throw "Invalid item.";
                }
            } // this closes try
                // Catch exceptions and report problems and quit the program now (exit(1)).
                // Error messages describe what is wrong with the expression.
            catch (stack::Overflow) { // for too many operands case
                cout << "Error: Expression too long." << endl;
                postfixstack.clearIt();
                goto beginning; // go back to the beginning of the loop
            }
            catch (stack::Underflow) { // for too few operands/numbers case
                cout << "Error: Too few operands/numbers." << endl;
                postfixstack.clearIt();
                goto beginning; // go back to the beginning of the loop
            }
            catch (char const *errormsg) // for invalid item case
            {
                cout << "Error: Invalid item." << endl;
                postfixstack.clearIt();
                goto beginning; // go back to the beginning of the loop
            }

            // go back to the loop after incrementing i
            i++;
        }// end of while

        // After the loop successfully completes:
        // Pop the result and show it.
        postfixstack.pop(box1);
        cout << "Result: " << box1 << endl;
        // If anything is left on the stack, an incomplete expression
        // was found so also inform the user.
        if (!postfixstack.isEmpty()) {
            cout << "Error: Incomplete expression." << endl;
            postfixstack.clearIt();
            continue;
        }

        cout << "Type 'quit' to exit the program." << endl << endl;
    }
}// end of the program
