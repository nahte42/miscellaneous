#include <iostream>
#include <cstdlib>
#include <string>

#include "Map.h"

using namespace std;

MapClass::MapClass()
{
    start = NULL;
    current = NULL;
    end = NULL;
}


void MapClass::buildMap()
{
    string areas[33]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n",
    "o","p","q","r","s","t","u","v","w","x","y","z","aa","ab","ac","ad","ae",
    "zy","zz"};
       
    if (start == NULL)
    {
            node* gnu = new node;
            gnu ->area = areas[10]; //K
            gnu -> north = NULL;
            start = gnu;
            end = gnu;
    }
    if(start != NULL){
            node* gnu = new node;
            gnu ->area = areas[0]; //A
            gnu->north = start;
            gnu->west = NULL;
            start -> south = gnu;
            end = gnu;
            current = end;
    }
    if(start != NULL)
    {
            node* gnu = new node;
            gnu ->area = areas[1]; //B
            gnu->west = end;
            end -> east = gnu;
            end = gnu; 
    }
    if(start != NULL)
    {
            node* gnu = new node;
            gnu ->area = areas[2]; //C
            gnu->west = end;
            end -> east = gnu;
            end = gnu;
    }
        if(start != NULL)
    {
            node* gnu = new node;
            gnu ->area = areas[3]; //D
            gnu->north = current;
            current -> south = gnu;
            end = gnu;
            current = end;
    }
            if(start != NULL)
    {
            node* gnu = new node;
            gnu ->area = areas[4]; //E
            current -> south = gnu;
            end = gnu;
            current = end;
    }
            if(start != NULL)
    {
            node* gnu = new node;
            gnu ->area = areas[5]; //F
            gnu->west = end;
            end -> east = gnu;
            current = gnu;
            
    }
            if(start != NULL)
    {
            node* gnu = new node;
            gnu ->area = areas[6]; //G
            gnu->north = current;
            current -> south = gnu;  
    }
            if(start != NULL)
    {
            node* gnu = new node;
            gnu ->area = areas[7]; //H
            gnu->south = current;
            current -> north = gnu;
            current = gnu;    
    }
            if(start != NULL)
    {
            node* gnu = new node;
            gnu ->area = areas[8]; //I
            gnu->west = current;
            current ->east = gnu;
            current = gnu;    
    }
    
            if(start != NULL)
    {
            node* gnu = new node;
            gnu ->area = areas[9]; //J
            gnu->north = end;
            end ->south = gnu;
            current = gnu;  
            end = current;
    }
            if(start != NULL)
    {
            node* gnu = new node;
            gnu ->area = areas[13]; //N
            gnu->west = end;
            end ->east = gnu;
            current = gnu;  
    }
            if(start != NULL)
    {
            node* gnu = new node;
            gnu ->area = areas[11]; //L
            current->south = gnu;
            current = gnu;  
    }
            if(start != NULL)
    {
            node* gnu = new node;
            gnu ->area = areas[17]; //R
            gnu->north = end;
            current->west = gnu;
            current = gnu;   
    }
            if(start != NULL)
    {
            node* gnu = new node;
            gnu ->area = areas[12]; //M
            gnu->east = end;
            end->west = gnu;
            end = gnu;   
    }
            if(start != NULL)
    {
            node* gnu = new node;
            gnu ->area = areas[15]; //P
            gnu->east = end;
            end->west = gnu;  
    }
            if(start != NULL)
    {
            node* gnu = new node;
            gnu ->area = areas[14]; //P
            gnu->south = end;
            end->north = gnu;  
    }
          if(start != NULL)
    {
            node* gnu = new node;
            gnu ->area = areas[16]; //Q
            gnu->east = current;
            current->west = gnu;
            current = gnu;
            end = current;
    }
          if(start != NULL)
    {
            node* gnu = new node;
            gnu ->area = areas[18]; //S
            current->south = gnu;
            current = gnu;
            end = current;
            complex = end;
    }
        if(start != NULL)
    {
            node* gnu = new node;
            gnu ->area = areas[19]; //T
            current->east = gnu;
            current = gnu;
            end = current;
    }
        if(start != NULL)
    {
            node* gnu = new node;
            gnu ->area = areas[20]; //U
            current->east = gnu;
            current = gnu;
            end = current;
            
    }
        if(start != NULL)
    {
            node* gnu = new node;
            gnu ->area = areas[21]; //V
            current->south = gnu;
            current = gnu;
            end = current;
    }
        if(start != NULL)
    {
            node* gnu = new node;
            gnu ->area = areas[23]; //X
            gnu->west = current;
            current->east = gnu;
            current = gnu;    
    }
        if(start != NULL)
    {
            node* gnu = new node;
            gnu ->area = areas[24]; //Y
            gnu->south = current;
            current->north = gnu;
               
    }
          if(start != NULL)
    {
            node* gnu = new node;
            gnu ->area = areas[25]; //Z
            gnu->west = current;
            current->east = gnu;
               
    }
          if(start != NULL)
    {
            node* gnu = new node;
            gnu ->area = areas[22]; //W
            gnu->north = current;
            current->south = gnu;
            current = gnu;         
    }
        if(start != NULL)
    {
            node* gnu = new node;
            gnu ->area = areas[26]; //AA
            gnu->north = current;
            current->south = gnu;
            current = gnu;         
    }
        if(start != NULL)
    {
            node* gnu = new node;
            gnu ->area = areas[31]; //ZY
            gnu->north = current;
            current->south = gnu;
            current = gnu;         
    }
        if(start != NULL)
    {
            node* gnu = new node;
            gnu ->area = areas[32]; //ZZ
            gnu->north = current;
            current->south = gnu;
            current = gnu;         
    }
        if(start != NULL)
    {
            node* gnu = new node;
            gnu ->area = areas[27]; //AB
            gnu->north = complex;
            complex->south = gnu;
            end->west = gnu;
            current = gnu;
            end = current;
    }
        if(start != NULL)
    {
            node* gnu = new node;
            gnu ->area = areas[28]; //AC
            gnu->north = end;
            end->south = gnu;
            current = gnu;
            end = current;
    }
        if(start != NULL)
    {
            node* gnu = new node;
            gnu ->area = areas[29]; //AD
            gnu->north = end;
            end->south = gnu;
            current = gnu;
            end = current;
    }
        if(start != NULL)
    {
            node* gnu = new node;
            gnu ->area = areas[30]; //AE
            gnu->east= end;
            end->west = gnu;
            end = gnu;
            
    }
    current = start;
    
}

void MapClass::prntMap()
{
        current = start;
        cout<<current->area<<endl;
        current = current -> south;
        cout<<current->area<<endl;
        current = current -> south;
        cout<<current->area<<endl;
        current = current -> south;
        cout<<current->area<<endl;
        current = current -> south;
        cout<<current->area<<endl;
        current = current -> east;
        cout<<current->area<<endl;
        current = current -> south;
        cout<<current->area<<endl;
        current = current -> west;
        cout<<current->area<<endl;
        current = current -> west;
        cout<<current->area<<endl;
        current = current -> south;
        cout<<current->area<<endl;
        current = current -> east;
        cout<<current->area<<endl;
        current = current -> east;
        cout<<current->area<<endl;
        current = current -> south;
        cout<<current->area<<endl;
        current = current -> west;
        cout<<current->area<<endl;
        current = current -> south;
        cout<<current->area<<endl;
        current = current -> south;
        cout<<current->area<<endl;
        current = current -> west;
        cout<<current->area<<endl;
        cout<<endl;
        current = start;
}
  
string MapClass::traverseMap(string n)
{
    
    int k = 0;
    while (k<1 || k>4)
    { 
        
        if (n == "n")
            k = 1;
        else if (n == "s")
            k = 2;
        else if (n == "w")
            k = 3;
        else if (n == "e")
            k = 4;
        else
        {
            cout<<"Sorry, but is not a correct direction, please stick to, n, s, w, e\n";
            cin>>n;
        }
    }
    cout<<"Currently you are in area "<<current->area<<endl;
    
    switch (k)
    {
        case 1:
        {
            if(current->north != NULL && current->north->area!=current->area)
            {
                current = current -> north;
                cout<<"\nAnd you have moved to area "<<current->area<<endl;
                return current->area;
            }
           
          
        }
        case 2:
        {
            if(current->south != NULL)
            {
                current = current ->south; 
                cout<<"\nAnd you have moved to area "<<current->area<<endl;
                return current->area;
            }
           
        }
        case 3:
        {
            if(current->west != NULL)
            {
                current = current ->west;
                cout<<"\nAnd you have moved to area "<<current->area<<endl;
                return current->area;
            }
          
        }
        case 4:
        {
            if(current->east != NULL)
            {
                current = current ->  east;
                cout<<"\nAnd you have moved to area "<<current->area<<endl;
                return current->area;
            }
           
        }       
    }
}

string MapClass::getArea()
{
    
    return current->area;
}