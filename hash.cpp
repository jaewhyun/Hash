//
//  hash.cpp
//  final1.1
//
//  Created by Jae Won Hyun on 12/21/16.
//  Copyright © 2016 Jae Won Hyun. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "hash.h"
using namespace std;

Hash::Hash()
{
    
}

// return full truth value
bool Hash::getfull()
{
    return full;
}

// start calculating hash with input
void Hash::start()
{
    cin.getline(inputLine, 80);
        
    if(!cin.eof())
    {
        calchashvalue();
    }
}

// calculate hash value
void Hash::calchashvalue()
{
    for(i = 0; i < strlen (inputLine); i++)
    {
        hashValue += (int) inputLine[i];
    }
}

// test hashvalue
void Hash::testhashvalue()
{
    // test initial hash value for available array entry
    modHash = hashValue % MAX;
    
    if(occupied[modHash] == false)
    {
        name[modHash] = inputLine;
        firstHash[modHash] = modHash;
        occupied [modHash] = true;
        cout << "Your input line " << inputLine << " hashes to "
        << modHash << endl;
    }
    // initial test failed, look for alternate location in array
    else
    {
        cout << "Hash collision! "
        << "We need to find an open table entry." << endl;
        
        findopentableentry();
    }
}

void Hash::findopentableentry()
{
    bool found = false;  // declare binary state variable "found":
    // false means an available  array position
    // not found, true means it is found.
    for (i = 0; i < MAX && found == false && full == false; i++)
    {
        // test found == false, need to stop execution of loop when
        //  an available array position is found
        if (occupied[i] == false)
        { // test if selected hash table element is occupied
            name[i] = inputLine;
            firstHash[i] = modHash;
            occupied [i] = true;
            cout << "Your input line " << inputLine
            << " hashes to " << i << endl;
            found = true; // Set array position found
            // remove unnecessary } right curly bracket
            // remove break; statement
        }
        else
        {
            if (i >= MAX-1)
            {
                cout << "Sorry! Table is full!"
                <<" We cannot place your entry."
                << endl << endl;
                full = true;  // set state flag hash
                //array full
            }
        }
    }
}

void Hash::listmemebers()
{
    for (i = 0; i < MAX; i++)  // finally, list members of hash table
    {
        if (occupied[i] == true)
        {
            cout << " Position in table is " << i << " Hashed to "
            << firstHash[i] << ".\tString is " << name[i] << endl;
        }
    }
}
