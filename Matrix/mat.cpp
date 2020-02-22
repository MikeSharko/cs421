#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

//--------------------------------------
// CS421 File mat.cpp for HW2A Matrix Practice
// Your name: Mike Sharko
//--------------------------------------
// I wrote this program in cs311 class, just added a few comments in it and recompiled it to see if it still works :)))


// the following can be changed and the rest of the code should work
int const R = 3;  // number of rows
int const C = 4;  // number of columns
int const VM = 3; // table entry length

vector<char>  T[R][C];  // 3 rows and 4 columns table for now 

// ------------------ Functions --------------------------------

int convert(char x)
{
	//in ASCII 'a' is 97, by subtracking  char -97 we will get the number we need, in our case 0
	return x - 97;
}


int readTable()
{
	 
    int row, col; //row and col numbers
	char col_c; // column indicator
	ifstream fin("lines.txt", ios::in);
	// Read in the file into T
	while (fin >> row) //next line of file
	{
		fin >> col_c; col = convert(col_c);  // converting col_c to a slot number
		vector<char> v;  // a vector to fill
		char c; // one char from the file
		for (int i = 0; i < VM; i++) {
			fin >> c;
			v.push_back(c);   // ** Fill v with chars from the file (a loop)
		}

		T[row][col].push_back('-'); // didn't know how to make without it.
		for (int i = 0; i < 3; i++) {
			T[row][col].push_back(v[i]); // putting v into T[row][col]
		}
	}//end of while
	return 0;
}

//Display a vector
void showVector(vector<char> v)
{
	if (v.size() == 0)  // empty entry
		for (int i = 1; i <= VM; i++) cout << "- ";
	else // show the content of v separated by blanks
		for (int i = 1; i < v.size(); i++)
			cout << v[i] << " ";
}


void displayTable()
{
	// Display T nicely labeled with row numbers
	//    by calling showVector

	for (int row = 0; row < R; row++)
	{
		cout << row << "| ";
		for (int col = 0; col < C; col++)
		{
			//calling my function showVector with a separator
            showVector(T[row][col]);
			cout << " | ";
		}
		cout << endl;
	}
}

int main()
{
    cout << "Reading table from lines.txt..." << endl;
	//calling functions
    readTable();
	displayTable();

}
