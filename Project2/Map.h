//***********************
//                      *
//THE MAP OF THE GAME   *
//                      *
//***********************

/* 
 * File:   Map.h
 * Author: Ethan
 *
 * Created on May 26, 2017, 4:14 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#ifndef MAP_H
#define MAP_H

class MapClass
{
private:
    struct node
    {
        string area;
        node* north;
        node* south;
        node* east;
        node* west; 
        node* mapPtr;   
        ;
    };
    
    string getAreaPriv( );
    string traverseMapPriv(string);
public:
    //string areas[33];
    node* complex;
    node* start;
    node* end;
    node* current;
    MapClass();
    void buildMap();
    string traverseMap(string n);
    string getArea();
    void prntMap();
};
#endif /* MAP_H */