using namespace std;

#include <iostream>
#include <vector>

// CS311 YOSHII F23 combine.cpp
// Must use the algorithm that is in the notes! 
//  NEVER delete my comments!!
//--------------------------------------------
//CS311 HW2P2 Combine 
//Name: Ben Foltz-Miranda
//Compiler: g++
//--------------------------------------------

// combines two sorted lists A and B into R
// displays comparison every time it is done
void combine(vector<int> A, vector<int> B, vector<int> &R) {
    int ia = 0; // index for A
    int ib = 0; // index for B

    // Until you run out of elements in A or run out of elements in B:
    while (ia < A.size() && ib < B.size()) {
        if (A[ia] < B[ib]) { // Compare the elements at the current index
            // get the A element to R
            R.push_back(A[ia++]);
        } else {
            // get the B element to R
            R.push_back(B[ib++]);
        }
        cout << "comparison" << endl; // display "comparison" to show how many times it is done
    }

    // After the loop:
    // Copy the remaining elements from A (if any) into R
    while (ia < A.size()) {
        R.push_back(A[ia++]);
    }

    // Copy the remaining elements from B (if any) into R
    while (ib < B.size()) {
        R.push_back(B[ib++]);
    }
}


int main() {
    vector<int> L1;
    vector<int> L2;
    vector<int> L3;
    int N;  // how many elements in each of L1 and L2
    int e;  // for each element

    cout << "How many elements in each list?" << endl;
    cin >> N;

    cout << "List1" << endl;
    for (int i = 1; i <= N; i++) {
        cout << "element :";
        cin >> e;
        L1.push_back(e);
    }

    cout << "List2" << endl;
    for (int i = 1; i <= N; i++) {
        cout << "element :";
        cin >> e;
        L2.push_back(e);
    }


    // call combine here to combine L1 and L2 into L3
    combine(L1, L2, L3);
    cout << "The result is: ";
    for (int i = 0; i < N * 2; i++) {
        cout << L3[i];
    }
    cout << endl;

}// end of main
