// CS311 YOSHII F23 mat.cpp
// Complete by searching for **
// NEVER delete my comments!!!
//---------------------------------------
#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

//--------------------------------------
// CS311 File mat.cpp for HW1P3 Matrix 
// Compiler: g++
// Your name: Ben Foltz-Miranda
//--------------------------------------

// the following can be changed and the rest of the code should work
int const R = 3;  // number of rows
int const C = 4;  // number of columns
int const VL = 3; // table entry vector length

vector<char> T[R][C];  // 3 rows and 4 columns table for now

// ------------------ Functions --------------------------------

int convert(char x) {
    // use a formula to convert a to 0, b to 1, c to 2 etc.
    return (x - 97);
}

// this reads the input file into the matrix table
void readTable() {
    int row, col;
    char col_c;
    ifstream fin(
            "lines.txt",
            ios::in);
    // Read in the file into T
    while (fin >> row) { // per row
        vector<char> V;
        fin >> col_c;
        col = convert(col_c);  // to a slot number
        char c; // one char from the file

        // Fill vector V with chars from the file (a for loop)
        for (int i = 0; i < VL; i++) { // loop through every char in the vector
            fin >> c; // get the char from the file
            V.push_back(c); // put the char in the vector
        }

        T[row][col] = V; //  Put the vector in T[row][col]
    }//end of while
}

// display the vector nicely to the outstream
void showVector(vector<char> v, ostream &ost) {
    if (v.size() == 0)  // empty entry will be dashes
        for (int i = 1; i <= VL; i++) {
            ost << "- ";
        }
    else {
        // show the content of v separated by blanks
        for (char i: v) { // loop through every char in the vector
            ost << i << " ";
        }
    }
}


// display the matrix
void displayTable() {
    // display T nicely labeled with row numbers
    //    by calling showVector with cout
    //    for each column
    for (int r = 0; r < R; r++) {
        cout << r << ":";
        for (int c = 0; c < C; c++) {
            showVector(T[r][c], cout);
            cout << "|";
        }
        cout << endl;
    }
}

// save the matrix to the output file
void saveTable() {
    ofstream fout(
            "table.txt",
            ios::out);

    //    output T nicely labeled with row numbers
    //    by calling showVector with fout
    //    for each column

    for (int r = 0; r < R; r++) { // loop through every row
        fout << r << ":"; // print the row number
        for (int c = 0; c < C; c++) { // loop through every column
            showVector(T[r][c], fout); // print the vector and send it to fout
            fout << "|";
        }
        fout << endl;
    }
}


int main() {
    cout << "reading from lines.txt" << endl;
    readTable();
    displayTable();

    cout << "saving the table in table.txt" << endl;
    saveTable();

}//the end
