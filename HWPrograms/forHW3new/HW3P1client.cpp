//CS311 Yoshii F23 HW3P1client.cpp
//INSTRUCTION:
//Look for ** to complete all of them
//The output should match my assignment sheet. Check!!!!
//  NEVER delete my comments!!!
//=========================================================
//HW#: HW3P1 llist
//Your name: **
//Complier:  g++
//File type: client program (tester) HW3P1client.cpp
//===========================================================

using namespace std;
#include <iostream>
#include "llist.h"
#include <stdlib.h>

/*  Copy caseOne function here after case1 is approved. */

void caseTwo()
{ 
  cout << "Case 2: Insert and Delete ------------" << endl;
  llist L;  // another list for case 2
  int x;      // to hold the removed element 
  int c = 1;  // displayed step number

  // 1. add to front 4 times (9,8,6,5) 
  cout << "Step " << c << " addFront 9 8 6 5" << endl; c++;
  L.addFront(9); L.addFront(8); L.addFront(6); L.addFront(5);

  // 2. display all
  cout << "Step " << c << endl; c++;
  L.displayAll();

  // 3. insert the 1st  (element 4) 4 5 6 8 9
  cout << "Step " << c << " insert first 4" << endl; c++;
  L.insertIth(1, 4);

  // 4. insert the 4th  (element 7)  4 5 6 7 8 9
  cout << "Step " << c << " insert 4th 7" << endl; c++;
   **

  // 5. insert the 7th  (element 10) and displayAll 4 5 6 7 8 9 10
    cout << "Step " << c << " insert 7th 10" << endl; c++;
     **
     **

  // 6. insert the 9th  (element 12) error (out of range)
    cout << "Step " << c << " insert 9th" << endl; c++;
    //try{** } 
    //catch(**){**}  // do not exit

  // 7. insert the 0th (element 0) error (out of range)
  cout << "Step" << c << " insert 0th" << endl; c++;
  try{** } 
  catch(**){**} // do not exit

  // 8. displayAll (should be unchanged from step 5 display)
  cout << "Step " << c << endl; c++;
  L.displayAll();

  // 9. delete Ith I==1 (display  the element removed) 5 6 7 8 9 10
  cout << "Step " << c << " delete 1st" << endl; c++;
  L.deleteIth(1, x); cout << "removed " << x << endl;

  // 10. delete Ith I==6 (display the element removed) 5 6 7 8 9 
  cout << "Step " << c << " delete 6th" << endl; c++;
  **
  cout << "Removed: " << x << endl;

  // 11. delete Ith I==3 (display the element removed) and displayAll 5 6 8 9
    cout << "Step " << c << " delete 3rd" << endl; c++;
    **
    cout << "Removed: " << x << endl;
    **

  // 12. delete Ith I==5 . error (out of range)
    cout << "Step " << c << " delete 5th" << endl; c++;
    try {** }
    catch(**){** }

  // 13. delete Ith I==0 . error (out of range)
  cout << "Step " << c << " delete 0th" <<  endl; c++;
  try {**}
  catch(**){**}

  // 14. displayAll (should be unchanged from step 11 display)
  cout << "Step " << c << endl; c++;
  L.displayAll();

  // 15. delete from rear until empty (display the elements removed)
  cout << "Step " << c << " delete all" << endl; c++;
     // loop - use x for removed element
   **
  // 16. displayAll  - should be empty now
  cout << "Step " << c << endl; c++;
  L.displayAll();

  // 17. insert the 0th  (error out of range)
  cout << "Step " << c << " insert 0th" << endl;; c++;
  try {**}
  catch (**){**}

  // 18. delete front  (error underflow)
  cout << "Step " << c << " deleteFront" << endl; c++;
  try {**}
  catch (**){**}

  // 19. delete 2nd I == 2 (error out of range)
  cout << "Step " << c << " delete 2nd" << endl; c++;
  try {** }
  catch (**){**}
  // 20.  delete rear (error underflow)
  cout << "Step " << c << " deleteRear" <<  endl; c++;
  try {** }
  catch (**){**}

} // end of case 2


//PURPOSE: to test copy constructor which gets called automatically. 
// Adds 6 to the rear of the copiedList and displays the list.
//PARAMETER: list passed by value becomes copiedList via your copy constructor
void CopyTest(llist copiedList)
{
  cout << "in copy test" << endl;
  ** // add 6
  ** // display all
  cout << "finished" << endl;
}

void caseThree()
{
  cout << "Case 3: Copy Constructor and = -------" << endl;
  llist L1, L2; // two lists needed
  int x;        // local for removed element
  int counter = 1;  // step number

  //1. Create a 5 element list with  [1,2,3,4,5] (L1)
  cout << "Step" << counter << endl; counter++;
  **
  cout << "L1: "; L1.displayAll();   // 1 2 3 4 5

  //2. Simply pass L1  to a client function called CopyTest to 
  //test your copy constructor.
  cout << "Step" << counter << endl; counter++;
  CopyTest(L1);

 cout << "-- After copytest --- " << endl;
 
  //3. Display L1 (this should still be a 5 element list)
  cout << counter << endl; counter++;
  cout << "L1: "; L1.displayAll();
 
  cout << "-- Testing operator overloading ---" << endl;

  //4. Do L1 = L1;
  cout << "Step " << counter << " Gets" << endl; counter++;
  **

  //5. Display L1    (this should still be 1 2 3 4 5)
  cout << "Step " << counter << endl; counter++;
  cout << "L1: "; L1.displayAll();		

  //6. Create a 4 element list L2 with 7,8,9,10.
  cout << "Step " << counter << endl; counter++;
  **

  //7. Display L2
  cout << "Step " << counter << endl; counter++;
  cout << "L2: " ; L2.displayAll();

  //8. Do L2 = L1;  (L2 becomes 5 elements 1,2,3,4,5)
  cout << "Step " << counter << " Gets" << endl; counter++;
  **

  //9. Display L2.
  cout << "Step " << counter << endl; counter++;
  cout << "L2: "; L2.displayAll();

  //10. Remove a rear node from L1. (This should not affect L2).
  cout << "Step " << counter << endl; counter++;
  **

  //11. Display L1.   (L1 is 1,2,3,4)
  cout << "Step " << counter << endl; counter++;
  cout << "L1 :";	L1.displayAll();

  //12. Display L1 again. (4 elements just to make sure)
  cout << "Step " << counter << endl; counter++;
  cout << "L1: ";	L1.displayAll();

  //13. Display L2 again. (still 5 elements 1,2,3,4,5)
  cout << "Step " << counter << endl; counter++;
  cout << "L2: ";	L2.displayAll();
}

//PURPOSE of the Program: to test llist thoroughly
//Algorithm/Design: 3 test cases are divided into functions and ***
int main()
{
  int selection; // this will display what the user wants to do
  
  do
    {
      cout << endl << "MENU: These are your options: " << endl << endl;
      cout << "   (1) Case 1  " << endl;
      cout << "   (2) Case 2  " << endl;
      cout << "   (3) Case 3  " << endl;
      cout << "    Enter ( 0 ) to quit " << endl;
      cout << "===>";
      
      cin >> selection;
      
      switch(selection)
	{
	case 1: caseOne(); break;
	case 2: caseTwo(); break;
	case 3: caseThree(); break;
	}
    }
  while(selection !=0);

}// end of main

