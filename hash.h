//
//  hash.h
//  final1.1
//
//  Created by Jae Won Hyun on 12/21/16.
//  Copyright © 2016 Jae Won Hyun. All rights reserved.
//

#include <string>
#ifndef hash_h
#define hash_h
using namespace std;

class Hash{
public:
    static const int MAX = 23;
    
    char inputLine[80] = " ";
    string name[MAX];
    int firstHash[MAX];
    bool occupied [MAX] = {MAX * false};
    
    Hash();
    void start();
    void calchashvalue();
    void testhashvalue();
    void testhashtableelement();
    void findopentableentry();
    void listmemebers();
    bool getfull();
    
private:
    bool full = false;
    int hashValue = 0;
    int modHash;
    int i;
};

#endif /* hash_h */
