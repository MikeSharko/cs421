#include<iostream>
#include<string>
using namespace std;
#include <queue> // std::queue // include queue.h or equivalent such as <queue>

//----------------------------------------------
// CS421 HW1
// Write a generator in C++ for L = {x | x is a binary number}.
// Your name: Mike Sharko
//----------------------------------------------

// Copy the recognizer function here from the other file.

bool recognizer(string s)
{
    // looping from the 1st character to the last
    for(string::size_type i = 0; i < s.size(); ++i) {
        if(s[i] != '0' && s[i] != '1') return false;
    }
    return true;
}
// end of recognizer

// main: It should create each string over E = {0,1,2} systematically
//   (short to long) and pass each string to the recognizer function
//   created in Part a).  Hint: use a queue to generate strings
//   Only those strings for which the recognizer returned TRUE
//   should be displayed.
//   Keeps on going until the queue overflows but the user can
//   terminate the program with control-C
//   after about 20 strings have been displayed.
int main()
{
    string tmpString;
    bool res = false; // variable to pass for recognizer and to check if it is valid or not
    int counter = 0; // general counter
    //pushing to queue before the loop, it's like our initial setup.
    queue <string> sQueue;
     string E[3] = {"0", "1", "2"}; // using an array
     for (int i=0; i<3; i++) {
         sQueue.push(E[i]);
     }
     int x = 32; // how many strings to generate;
      
    while(counter!=x)
    {
        // generate a string
        
        tmpString = sQueue.front(); // assigning to tmpString the front element of the queue;
        sQueue.pop(); //poping the front element;
        res = recognizer(tmpString); // will return  true if it is a valid string . e.g (0 or 1)
        if (res) // if true
        {
            cout << tmpString <<endl; // displaying a valid string;
            counter ++; // obvious :)
            sQueue.push(tmpString + "0"); // adding our alphabet to the front of the queue
            sQueue.push(tmpString + "1"); // adding our alphabet to the front
            sQueue.push(tmpString + "2"); // adding our alphabet to the front
            
            if (counter == x) {
                cout << counter<<" strings were generated" << endl<< endl;
                
                cout << "Continue generating? Type y/n" << endl;
                char answer;
                cin >> answer;
                if (answer == 'y') {
                 x*=2; // multiplying x by 2 in order to generate twice more binary numbers than before
                continue; // returning to while
                }
                else
                    return 0; // exit
            }
        }
    }// end of while
}// end of main
