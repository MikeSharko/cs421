//------------------------------------------------
// CS421 File fa.cpp for HW2B DFA->Scanner Function
// Your name: Mike Sharko
//------------------------------------------------

// ** Change this to fit the HW2B specification - look for **
// ** Must have the same types of tracing couts as mytoken.
// ** Must complete the ** comments with RE

// ---------- DFAs follow -------------------------

// MYTOKEN DFA done by Rika Sensei has a sample
// This FA is for    (ab^+)

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// -------  I commented it , because we are not using it
//bool mytoken(string s)
//{
//  int state = 0;
//  int charpos = 0;
//
//  cout << "Trying the mytoken machine..." << endl;
//
//  while (s[charpos] != '\0')
//    {
//      cout << "current state: " << state << endl;
//      cout << "character: " << s[charpos] << endl;
//
//      if (state == 0 && s[charpos] == 'a')
//      state = 1;
//      else if (state == 1 && s[charpos] == 'b')
//      state = 2;
//      else if (state == 2 && s[charpos] == 'b')
//      state = 2;
//      else
//    {
//      cout << "I am stuck in state " << state << endl;
//      return(false);
//    }
//      charpos++;
//    }//end of while
//
//  // where did I end up????
//  if (state == 2) return(true);  // end in a final state
//   else return(false);
//}// end of mytoken


//Note: l(letter) can be either a or b
//d can be either 2 or 3

// ----------IDENT DFA---------------
// This FA is for RE:  a|b ( (a|b) | (2|3) | _ )^*
bool ident_token(string s)
{
  int state = 0;
  int charpos = 0;
  cout << "Trying the mytoken machine for l ( l | d | _ )^* " << endl; //added this to the cout to visually see what function is checking the RE (it is more for me)
    
    while (s[charpos] != '\0'){
        cout << "current state: " << state << endl;
        cout << "character: " << s[charpos] << endl;
    
    if (state == 0 && s[charpos] == 'a')  //handling first a's or b's
        state = 1;
    else if (state == 0 && s[charpos] == 'b')//handling first a's or b's
    state = 1;
    // handling the ( (a|b) | (2|3) | _ )^*
    else if ((state == 1 && s[charpos] == 'a') || (state == 1 && s[charpos] == 'b') || (state == 1 && s[charpos] == '_') || (state == 1 && s[charpos] == '2') || (state == 1 && s[charpos] == '3')) // instead of writing a banch of else if statements
    state = 1;
    
    else {
        cout << "I am stuck in state " << state << endl;
        return(false);
    }
        charpos++;
    }
    if (state == 1) return(true);  // end in a final state
     else return(false);
}//end of ident


// -----------REAL DFA--------------
// This FA is for RE:  (2|3)^* . (2|3)^+
bool real_token(string s)
{
    int state = 0;
    int charpos = 0;
    cout << "Trying the mytoken machine for d^*.d^+" << endl;//added this to the cout to visually see what function is checking the RE (it is more for me)
    while (s[charpos] != '\0'){
        cout << "current state: " << state << endl;
        cout << "character: " << s[charpos] << endl;
           
    if (state == 0 && s[charpos] == '2') //handling 0 or more 2's and 3's before '.'
        state = 0;
    else if (state == 0 && s[charpos] == '3') //handling 0 or more 2's and 3's before '.'
    state = 0;
    else if (state == 0 && s[charpos] == '.') // could be without first digit
        state = 1;
    else if (state == 1 && s[charpos] == '2' ) //handling only 1 digit
           state = 2;
    else if (state == 1 && s[charpos] == '3')  //handling only 1 digit
    state = 2;
    else if ((state == 2 && s[charpos] == '2') || (state == 2 && s[charpos] == '3') ) // handling 1+ digits
        state = 2;
   
    else{
        cout << "I am stuck in state " << state << endl;
        return(false);
    }
    
        charpos++;
    }
        
        if (state == 2) return(true);  // end in a final state
        else return(false);
   
}//end of real


//---------INT DFA-------------
// This FA is for RE:  (2|3)^+
bool integer_token(string s)
{
    int state = 0;
    int charpos = 0;
    cout << "Trying the mytoken machine for d^+" << endl; //added this to the cout to visually see what function is checking the RE (it is more for me)
       while (s[charpos] != '\0'){
           cout << "current state: " << state << endl;
           cout << "character: " << s[charpos] << endl;
    
    if (state == 0 && s[charpos] == '2')
        state = 1;
    else if (state == 0 && s[charpos] == '3')
        state = 1;
    else if ((state == 1 && s[charpos] == '2') || (state == 1 && s[charpos] == '3') )
        state = 1;
    else{
        cout << "I am stuck in state " << state << endl;
        return(false);
    }
           charpos++;
       }
    if (state == 1) return(true);  // end in a final state
        else return(false);
    
}// end of int


// -----------------------------------------------------

enum tokentype {ERROR, MYTOKEN, IDENT, REAL, INT};
int scanner(tokentype& , string& );  // to be called by main
fstream fin;   // file stream to use

// The test-driver -- NO NEED TO CHANGE THIS
int main()
{ string fname;
  cout << "Enter the input file name:";
  cin >> fname;

  fin.open( fname.c_str(), fstream::in);

  string tokens[5] = {"ERROR", "MYTOKEN", "IDENT", "REAL", "INT"};
  tokentype thetype;
  string theword;

  while (true)  // keep on going
    {
      scanner(thetype, theword);  // the paramers will be set by Scanner
      if (theword == "EOF") break;

      cout << ">>>>>Type is:" << tokens[thetype]  << endl;
    }

  cout << ">>>>>End of File encountered" << endl;
  fin.close();
}// end of main


// Scanner sets the_type and w - TO BE COMPLETED **
int scanner(tokentype& the_type, string& w)
{
  
  // This goes through all machines one by one on the input string w

  cout << endl;
  cout << ".....Scanner was called..." << endl;

  fin >> w;  // grab next word from fain.txt
  cout << ">>>>>Word is:" << w << endl;

//    if (mytoken(w))
//       {
//           the_type = MYTOKEN;
//       }
       if(ident_token(w))
       {
           the_type = IDENT;
       }
       else if(real_token(w))
       {
           the_type = REAL;
       }
       else if(integer_token(w))
       {
           the_type = INT;
       }

  else //none of the FAs returned TRUE
    { cout << ">>>>>Lexical Error: The string is not in my language" << endl;
      the_type = ERROR; }
    return 0;
}//the very end of scanner

