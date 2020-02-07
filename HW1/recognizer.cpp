//Recognizer
#include<iostream>
#include<string>
using namespace std;

//-------------------------------------------------------
// CS421 HW1
// Write a recognizer in C++ for L = {x | x is a binary number}.
// Your name: Mike SHarko
//-------------------------------------------------------

//  The recognizer function should return TRUE or FALSE
//  checking each character
//  to make sure it is 0 or 1. (leading 0's are allowed).
bool recognizer(string s)
{
    // looping from the 1st character to the last
    for(string::size_type i = 0; i < s.size(); ++i) {
        if(s[i] != '0' && s[i] != '1') return false;
    }
    return true;
}
// end of recognizer

//main: Given a string (from E) cined from the user, pass it to
//      the recognizer function.
//      Cout "YES IN L" or "NO NOT IN L" depending on what was returned.
int main()
{
      cout << "Enter a string to check, enter \"end\" to exit" << endl;
      string userInput;
     while (true) {
    cin >> userInput;
         //Exiting normally
         if (userInput == "end")
             return 0;
         // passing userinput to recognizer fuction
         if (recognizer(userInput))
        {cout << "Yes in L " << endl;}
        else
        {
        cout << "No, Not in L" << endl;
        }
   }
}// end of main
