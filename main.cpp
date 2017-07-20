// John Maslanka October 2009 HashProg1a.cpp
// A program which does hashing of user data to a fixed-length array.
// Edits 10/24/2014 JM -- (1) Remove two break; statements from the code. (2) Define
// a "full" boolean variable to discontinue processing when the array is full.
// (3) Define a "found" boolean variable to indicate that a location in the array is
// found for a new entry. The "found" variable terminates further search for a new location
// for an input value when a location has been successfully found.

#include <iostream>
#include <string>
#include "hash.h"
using namespace std;

int main ()
{
    // declare object
    Hash A;
    
    cout << "Please enter each string of characters followed by <Enter>." << endl << "Terminate by entering EOF on keyboard (control-z in Windows)." << endl;
    
    while(!cin.eof() && A.getfull() == false)
    {
        A.start();
        A.testhashvalue();
        
    }
    
    A. listmemebers();
    
    return 0;
}
