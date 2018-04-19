//***********************************************
//                                              *
//Project 2                          *
//                                              *
//                                              *
//                                              *
//***********************************************

/* 
 * File:   main.cpp
 * Author: Ethan
 *
 * Created on May 26, 2017, 4:06 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "Tree.h"
#include "Map.h"
#include "Hash.h"
#include "Character.h"
#include "Enemy.h"
#include <cstring>
#include <time.h>
using namespace std;
//GLOBALS
string item[3] = {"small potion", "mega potion", "bomb"};
int itmValu[3] = {20, 50, 15};

string weapon[11]={"Fists","Sword","Axe","Scythe","Hammer","Gauntlets",
                   "Staff","Spear","Flail","Dagger","Super Mega Sword"
                  };
int attkVal[11]  ={10,20,15,13,21,15,15,20,18,18,50};


//FUNcTIONS
int getScene(string);
//void noEnemy(MapClass, Tree);
void instructions();
void controls();
void recursiveSort();
void heapIt(int[], int, int);
int battleFunct(Hero, hashClass, Enemy, Enemy, Tree);
int setScene(Hero,int,hashClass, Tree);
string traverseMap(MapClass, string);
string searchRoom(Tree, hashClass, Hero);


int main(int argc, char** argv) 
{
    //INSTANCES OF THE CLASSES
    MapClass Map;
    Hero character;
    hashClass equipment;
    Tree bag;
   
   //MAKE HERO
   string currWpn = weapon[1]; 
   equipment.addItem(currWpn, attkVal[1]);
   character.SwapWeapon(currWpn);
   //MODIFIERS
   int attkMod = character.getAttack();
   int spdModi = character.getSpeed();
   int luckMod = character.getLuck();
   int strnMod = character.getStrength();
   int curHlth = character.getHealth();
   
   
       //MENU
   int n = 0;
   while (n != 1)
   {
       cout<<"---------Project 2 The Dungeon Crawler Game---------\n"
           <<"| 1. START GAME                                    |\n"
           <<"| 2. CRONTROLS                                     |\n"
           <<"| 3. INSTRUCTIONS                                  |\n"
           <<"| 4. EXIT                                          |\n"
           <<"| 5. Special Mini Game                             |\n"    
           <<"----------------------------------------------------\n";
       cin >> n;
       if(n == 2)
       {
           controls();
       }
       else if(n == 3)
       {
           instructions();
       }
       else if (n == 4)
       {
           exit(0);
       }
       else if (n == 5)
       {
           recursiveSort();
       }
   }
   
   
   Map.buildMap();

   
   string movement, area;
   int scenario = 0;
   int num = 0;
   cout<<endl<<"You start off in a dark dingy room, hint: go south : s"<<endl;
   while (true)
   {  
       
       cout<<"Current health = "<<character.getHealth()<<endl;
       cout<<"-----------------------\n"
           <<"|1.Move n, s, e, w    |\n"
           <<"|2.Search Current Room|\n"
           <<"|3.Use Item           |\n"
           <<"-----------------------"<<endl;
       cin>>num;
       switch (num)
       {
           case 1:
           {
              cout<<endl<<"Movement: ";
              cin>>movement;
              area = Map.traverseMap(movement);
              scenario = getScene(area);
              if (scenario > 0)
                  character.setHealth(setScene(character, scenario, equipment, bag));
              break;
           } 
           case 2:
           {
               bag.addLeaf(searchRoom(bag, equipment, character));
               
               break;
           }
           case 3:
           {
               cout<<"You have the current items in your bag: ";
               bag.printInOrder();
               cout<<endl;
               cout<<"Which item would you like to use! enter it now!: ";
               string itemUse;
               cin >> itemUse;
               if (itemUse.at(0) == 's' || itemUse.at(0) == 'S' ){
                   character.setHealth(character.getHealth()+itmValu[0]);
                   cout<<"You were healed by "<<itmValu[0]<<" points\n";
                   //bag.removeNode(item[0]);
               }
               
               else if(itemUse.at(0) == 'm' || itemUse.at(0) == 'M'){
                   character.setHealth(character.getHealth()+itmValu[1]);
                   cout<<"You were healed by "<<itmValu[1]<<" points\n"; 
                    //bag.removeNode(item[1]);
                   
               }
               
               
               
               
               break;
           }

       } 
        
        
   }
   
   //move->fight if enemy->search
           
   
   
   
    return 0;
}
//SEARCH THE ROOM FOR AN ITEM
string searchRoom(Tree bag, hashClass equipment, Hero character)
{
    srand((unsigned)(int)(time(0)));
    int chance = rand()%10;
    if (chance < 2)
    {
        cout<<"sorry, but you didnt find anything\n\n";
        return "\n";
    }
    else if (chance >=2 && chance <= 6){
        int i = rand()%3;
        bag.addLeaf(item[i]);
        
        cout<<"Congratulations! A(n)" << item[i]<<" was added to your bag!!"<<endl;
        return item[i];
    
    }
    else
    {
        int i  = rand()%10;
        cout<<"Congratulations!! You just found a(n) "<<weapon[i]<<endl;
        equipment.addItem(weapon[i], attkVal[i]);
        if(equipment.getAttk(weapon[i]) > equipment.getAttk(character.CurrentWeapon))
        {
            cout<<"Since the weapon you found had a higher attack than the weapon you had\n"
                <<"You went ahead and equipped the better one"<<endl;
            character.SwapWeapon(weapon[i]);
        }
    } return "";
}




//FIGHT
int battleFunct(Hero character, hashClass equip, Enemy enemy1, Enemy enemy2, Tree bag)
{
    
    int choice = 0;
    int btlChoc;
    if (enemy1.getHlth()+enemy2.getHlth() == enemy1.getHlth()*2)
    {
        cout<<"Your path is blocked by two "<<enemy1.getName()<<"'s, Fight!\n";
    }
    else
        cout<<"Your path is blocked by a "<<enemy1.getName()<<", Fight!\n";
        
    
    
    while (enemy1.getHlth() > 0 || enemy2.getHlth() > 0 || character.getHealth() != 0)
        {
            cout<<"\n1.Attack\n2.Use Item\n3.Something\n";
            
            
            //while (choice < 1 || choice > 3)
            
                cin>>choice;
                
                if (choice == 1)
                { 
                    if(enemy1.getHlth() >0 || enemy2.getHlth() >0)
                        {
                            if (enemy2.getHlth() <= 0)
                                cout<<"1."<<enemy1.getName()<<endl;

                            else if (enemy1.getHlth() <=0)
                                cout<<"2."<<enemy2.getName()<<endl;

                            else
                            {
                                cout<<"1."<<enemy1.getName()<<endl;
                                cout<<"2."<<enemy2.getName()<<endl;
                            }
                            
                            cin>>btlChoc;
                            if (enemy2.getHlth() <= 0)
                                btlChoc = 1;
                            else if (enemy1.getHlth() <= 0)
                                btlChoc = 2;
                            else
                                btlChoc = btlChoc;


                            if (btlChoc == 1)
                            {
                                int damageTkn;
                                srand((unsigned)(int)(time(0)));
                                int num1 = rand()%10;
                                int num2 = rand()%10/2+1;

                                if (num1 + enemy1.getSped()%1 > character.getSpeed()+num2)
                                    cout<<"You miss the "<<enemy1.getName()<<endl;
                                else
                                {
                                    damageTkn = equip.getAttk(character.CurrentWeapon) - enemy1.getDfns();
                                    cout<<enemy1.getName()<<" 1's health was "<<enemy1.getHlth()<<endl;
                                    int currHlth = enemy1.getHlth()-damageTkn;
                                    enemy1.setHlth(currHlth);
                                    cout<<"\n"<<enemy1.getName()<<" 1's health is now "<<enemy1.getHlth()<<endl;
                                }
                            }
                            else if (btlChoc == 2)
                            {
                                int damageTkn;
                                srand((unsigned)(int)(time(0)));
                                int num1 = rand()%10;
                                int num2 = rand()%10/2+1;

                                if (num1 + enemy2.getSped()%1 > character.getSpeed()+num2)
                                    cout<<"You miss the "<<enemy2.getName()<<endl;
                                else
                                {
                                    damageTkn = equip.getAttk(character.CurrentWeapon) - enemy2.getDfns();
                                    cout<<enemy2.getName()<<" 2's health was "<<enemy2.getHlth()<<endl;
                                    int currHlth = enemy2.getHlth()-damageTkn;
                                    enemy2.setHlth(currHlth);
                                    cout<<"\n"<<enemy2.getName()<<" 2's health is now "<<enemy2.getHlth()<<endl;
                                }
                             }
                            else
                                cout<<"You attack the air! You hit it, technically, it wasnt doing anything to you though.\n\n";

                        } 
                    }
                else if (choice == 2)
                    {
                        cout<<"You have the current items in your bag: ";
                        bag.printInOrder();
                        cout<<endl;
                        cout<<"Which item would you like to use! enter it now!: ";
                        string itemUse;
                        cin >> itemUse;
                        if (itemUse.at(0) == 's' || itemUse.at(0) == 'S' ){
                            character.setHealth(character.getHealth()+itmValu[0]);
                            cout<<"You were healed by "<<itmValu[0]<<" points\n";
                            //bag.removeNode(item[0]);
                        }

                        else if(itemUse.at(0) == 'm' || itemUse.at(0) == 'M'){
                            character.setHealth(character.getHealth()+itmValu[1]);
                            cout<<"You were healed by "<<itmValu[1]<<" points\n"; 
                             //bag.removeNode(item[1]);
                            }
                        else if (itemUse.at(0) == 'b' || itemUse.at(0) == 'B')
                        {
                            if (enemy1.getHlth() > 0){
                                enemy1.setHlth(enemy1.getHlth() - 20);
                                cout<<enemy1.getName()<<" 1's health is now "<<enemy1.getHlth()<<endl;
                            }
                            if (enemy2.getHlth() > 0){
                                enemy2.setHlth(enemy2.getHlth() - 20);
                                cout<<enemy2.getName()<<" 2's health is now "<<enemy2.getHlth()<<endl;
                            }
                        }
                        else
                            cout<<"Sorry, thats not an item\n\n";
                    }
                else if (choice == 3)
                    cout<<"You did someting, sorta, not really, nevermind\n\n";
            


         
            if (enemy1.getHlth() > 0 && enemy2.getHlth() > 0)
            {
                srand((unsigned)(int)(time(0)));
                int dmgTkn;
                for (int i = 1; i < 3; i++)
                {   int num1 = rand()%10;
                    int num2 = rand()%10/2+1;
                    if (num1 + enemy1.getSped()%1 > character.getSpeed()+num2)
                    {
                        dmgTkn = enemy1.getAttk();
                        int crntHlt = character.getHealth()- dmgTkn;
                        character.setHealth(crntHlt);
                        cout<<endl<<enemy1.getName()<<" "<<i<<" "<<" hit you, "<<"your health is: "<<character.getHealth()<<endl;
                    }
                    else
                        cout<<enemy1.getName()<<" "<<i<<" "<<" Missed you by an inch!\n";
                }
            }
            else if (enemy1.getHlth() > 0 || enemy2.getHlth() > 0)
            {
                if (enemy1.getHlth() <= 0)
                { 
                    int dmgTkn;
                    int num1 = rand()%10;
                    int num2 = rand()%10/2+1;
                    if (num1 + enemy2.getSped()%1 > character.getSpeed()+num2)
                    {
                        dmgTkn = enemy1.getAttk();
                        int crntHlt = character.getHealth()- dmgTkn;
                        character.setHealth(crntHlt);
                        cout<<endl<<enemy2.getName()<<" 2"<<" hit you, "<<"your health is: "<<character.getHealth()<<endl;
                    }
                    else
                    cout<<enemy2.getName()<<" 2"<<" Missed you by an inch!\n";
                }
                if (enemy2.getHlth() <= 0)
                {
                    int dmgTkn;
                    int num1 = rand()%10;
                    int num2 = rand()%10/2+1;
                    if (num1 + enemy1.getSped()%1 > character.getSpeed()+num2)
                    {
                        dmgTkn = enemy1.getAttk();
                        int crntHlt = character.getHealth()- dmgTkn;
                        character.setHealth(crntHlt);
                        cout<<endl<<enemy1.getName()<<" 1"<<" hit you, "<<"your health is: "<<character.getHealth()<<endl;
                    }
                    else
                    cout<<enemy1.getName()<<" 2"<<" Missed you by an inch!\n";
                } 
                 
                
            }
                    if (character.getHealth() <= 0){
                        cout<<"Sorry but you failed to make it out alive.\n\n\n\n";
                    exit(0);
                    }
                    
                        
                    else if (enemy1.getHlth() <= 0 && enemy2.getHlth() <= 0)
                        return character.getHealth();
            }
}



void instructions()
{
    cout<<endl<<"Make your way through the cave, fight any monsters, and get out"<<endl;
}

void controls()
{
    cout<<endl<<"Move through the map by entering: n - s - w - or e\n"
              <<"Enter in the corresponding numbers to perform certain actions\n"
              <<"When using items, for a small potion enter 'small', \n for a mega potion, enter 'mega'\n"
              <<"and for a bomb, enter 'bomb'\n\n";
}

int getScene(string area)
{
    if (area == "a")
        return 1;
    else if (area == "c")
        return 2;
    else if (area == "d")
        return 3;
    else if (area == "i")
        return 4;
    else if (area == "g")
        return 5;
    else if (area == "l")
        return 6;
    else if (area == "m")
        return 7;
    else if (area == "n")
        return 8;
    else if (area == "o")
        return 9;
    else if (area == "q")
        return 10;
    else if (area == "r")
        return 11;
    else if (area == "u")
        return 12;
    else if (area == "w")
        return 13;
    else if (area == "x")
        return 14;
    else if (area == "y")
        return 15;
    else if (area == "z")
        return 16;
    else if (area == "ab")
        return 17;
    else if (area == "ad")
        return 18;
    else if (area == "zz")
        return 19; 
    else if (area == "ae")
    {
        cout<<endl<<endl<<"After vanquishing the horrible dragon, you can finally see the light that leads outwards."<<endl;
        cout<<"Congratulations hero, you have survived"<<endl<<endl;
        exit(0);
    }
    else
        return 0;
}

//SET THE SCENE
int setScene(Hero character, int scene, hashClass equip, Tree bag)
{
    if (scene == 1 || scene == 7 || scene == 8 ||scene == 10 ||scene == 12 || scene == 13)
    {
        Goblin enemy1, enemy2;
        int curHlth = battleFunct(character,equip, enemy1, enemy2, bag);
        return curHlth;
    }
    else if (scene == 2 || scene == 3 || scene == 11 || scene == 14 )
    {
        Kobold enemy1, enemy2;
        enemy2.setHlth(0);
        int curHlth = battleFunct(character,equip, enemy1, enemy2, bag);
        return curHlth;
    }
    else if (scene == 9 || scene == 15 ||scene == 17)
    {
        Minotaur enemy1, enemy2;
        enemy2.setHlth(0);
        int curHlth =battleFunct(character,equip, enemy1, enemy2, bag);
        return curHlth;
    }
    else if (scene == 4 || scene == 6)
    {
       GiantBat enemy1, enemy2;
       int curHlth = battleFunct(character,equip, enemy1, enemy2, bag);
       return curHlth;
    }
    else if (scene == 5 || scene == 16)
    {
       HellHound enemy1, enemy2;
       int curHlth = battleFunct(character,equip, enemy1, enemy2, bag);
       return curHlth;
    }
    else if (scene == 18)
    {
        Dragon enemy1, enemy2;
        enemy2.setHlth(0);
        int curHlth =battleFunct(character,equip, enemy1, enemy2, bag);
        return curHlth;
    }
    else if (scene == 19)
    {
        Zombie enemy1, enemy2;
        int curHlth = battleFunct(character,equip, enemy1, enemy2, bag);
        return curHlth;
    }
    else
        return 0;
  
    
}


void recursiveSort()
{
    
    cout<<"Can you sort this array faster than the computer?\nPress enter now to get the array:";
    cin.get();
    if (cin.get() == '\n')
    {
        int arr[1000];
        srand((unsigned)(int)(time(0)));
        for (int i = 0; i < 999; i++)
             arr[i] = rand()%100-10;
        cout<<"Unsorted Array: \n";
        for (int i = 0; i < 999; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        int n = sizeof(arr)/sizeof(arr[0]);
        
        cout<<"Press enter twice when youre ready, and try to sort it faster than the cpu!";
        cin.get();
        if(cin.get() == '\n')
        {
            // Build heap (rearrange array)
            for (int i = n / 2 - 1; i >= 0; i--)
                heapIt(arr, n, i);

            // One by one extract an element from heap
            for (int i=n-1; i>=0; i--)
            {
                // Move current root to end
                swap(arr[0], arr[i]);

                // call max heapify on the reduced heap
                heapIt(arr, i, 0);
            }
            cout<<"Sorted array: \n";

            for (int i = 0; i < 999; i++)
                cout<<arr[i]<<" ";
            cout<<endl;
           }
    }
            
}

void heapIt(int arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapIt(arr, n, largest);
    }

}


/*     
 *      TO DO LIST
 *      1. INCORPORATE RECURSIVE SORTING
 */


////MAIN MENU IS BELOW!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*

   
   cout<<"You find yourself in a dark desolate cave, equipped with nothing but\n"
       <<"the clothes on your back, and your fists, will you take up the challenge?\n"
       <<"1. yes\n"
       <<"2. Nah\n"
       <<endl;
   int decision = 0;
   while (decision != 1)
   {
       cin>>decision;
       if (decision == 2)
       {
           cout<<"For sure bro, next time\n";
           exit(0);
       }
      if (decision < 1 || decision > 2)
          cout<<"Sorry that is not an accepted answer.\n";
   }

   cout<<endl<<"You made the right choice, good luck\n";*/