/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include<string>
#include <cstdlib>

#include "Hash.h"

using namespace std;

hashClass::hashClass()
{
    for(int i = 0; i < tblSize; i++)
    {
        hashTbl[i] = new item;
        hashTbl[i] ->equip = "empty";
        hashTbl[i] ->atkValue= 0;
        hashTbl[i] ->next = NULL;
    }
}

int hashClass::hashFun(string key)
{
    int hash = 0, index;
  
    
    for (int i = 0; i < key.length(); i++)
    {
       int temp = (int)key[i++]*325; 
        hash = (hash + temp)/2;
    }

    
    index = hash % tblSize;
    
    
    return index;
           
}

void hashClass::addItem(string equip, int atkValue)
{
    int index = hashFun(equip);
    
    if(hashTbl[index]->equip == "empty")
    {
        hashTbl[index]->equip = equip;
        hashTbl[index]->atkValue = atkValue;           
    }
    else
    {
        item* ptr = hashTbl[index];
        item* gnu = new item;
        gnu->equip = equip;
        gnu->atkValue = atkValue;
        gnu->next = NULL;
        while (ptr->next!= NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = gnu;
    }
}

int hashClass::numOfItem(int index)
{
    int count = 0;
    
    if (hashTbl[index]->equip == "empty")
    {
        return count;
    }
    else
    {
        count++;
        item* ptr = hashTbl[index];
        while(ptr->next != NULL)
        {
            count++;
            ptr = ptr->next;
        }
    }
    return count;
}

void hashClass::prntTbl()
{
    int number;
    for (int i = 0; i < tblSize; i++)
    {
        number = numOfItem(i);
        cout<<"----------------------------\n";
        cout<<"Current index = "<<i<<endl;
        cout<<hashTbl[i]->equip<<endl;
        cout<<hashTbl[i]->atkValue<<endl;
        cout<<"Number of items = "<< number<<endl;
        cout<<"----------------------------\n";
    }
}

void hashClass::printItems(int index)
{
    item* ptr = hashTbl[index];
    if (ptr->equip == "empty")
    {
        cout<<" Index = "<<index<<" is empty"<<endl;
    }
    else
    {
        cout <<"Index " <<index<<" contains the following items\n";
        while(ptr != NULL)
        {
            cout<<"-----------------\n";
            cout<<ptr->equip<<endl;
            cout<<ptr->atkValue<<endl;
            cout<<"-----------------\n";
            ptr= ptr->next;
        }
    }
}

int hashClass::getAttk(string equip)
{
    int index = hashFun(equip);
    bool foundName = false;
    int atkValue;
    
    item* ptr = hashTbl[index];
    while(ptr != NULL)
    {
        if(ptr->equip == equip)
        {
            foundName = true;
            atkValue = ptr->atkValue;
            return atkValue;
        }
        ptr=ptr->next;
    }
    if (foundName == true)
    {
        cout<<"atkValue = "<< atkValue << endl;
    }
    else
    {
        cout<<equip<<"'s  info was not found in your inventory"<<endl;
    }
    
}

void hashClass::remItem(string equip)
{
    int index = hashFun(equip);
    item* delPtr;
    item* p1;
    item* p2;
    
    //Is Empty
    if (hashTbl[index]->equip == "empty")
        cout<<equip<<" was not found in your inventory"<<endl;
    //Contains 1 item, and its the item needed
    else if(hashTbl[index]->equip == equip && hashTbl[index]->next == NULL) 
    {
        hashTbl[index]->equip = "empty";
        hashTbl[index]->atkValue = 0;
        
        cout<<equip<<" was removed from your inventory\n";
    }
    //located in the bucket, and there are multiple items
    else if (hashTbl[index]->equip == equip)
    {
        delPtr = hashTbl[index];
        hashTbl[index] = hashTbl[index]->next;
        delete delPtr;
        
        cout<<equip<<" was removed from your inventory\n";
    }
    //located in bucket, and is not the first item
    else
    {
        p1 = hashTbl[index]->next;
        p2 = hashTbl[index];
        
        while (p1 != NULL && p1->equip != equip)
        {
            p2 = p1;
            p1 = p1->next;           
        }
        if (p1 == NULL)
        {
             cout<<equip<<" was not found in your inventory"<<endl;
        }
        else
        {
            delPtr = p1;
            p1 = p1->next;
            p2->next = p1;
            
            delete delPtr;
            
            cout<<equip<<" was removed from your inventory\n";
        }
    }
}