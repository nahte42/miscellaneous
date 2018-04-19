//***************************
//                          *
//HASH TABLE FOR EQUIPMENT  *
//                          *
//***************************


/* 
 * File:   Hash.h
 * Author: Ethan
 *
 * Created on May 12, 2017, 1:25 AM
 */

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
#ifndef HASH_H
#define HASH_H

class hashClass
{
private:
    static const int tblSize = 10;
   
    struct item
    {
        string equip;
        int atkValue;
        item* next;      
    };
    
    item* hashTbl[tblSize];
    
public:
    hashClass();
    int hashFun(string key);
    void addItem(string equip, int atkValue); 
    int numOfItem(int index);
    void prntTbl();
    void printItems(int index);
    int getAttk(string equip);
    void remItem(string equip);
};

#endif /* HASH_H */

