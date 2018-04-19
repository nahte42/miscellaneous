/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Enemy.h
 * Author: Ethan
 *
 * Created on May 26, 2017, 4:51 PM
 */
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#ifndef ENEMY_H
#define ENEMY_H

class Enemy
{
private:
    string name;
    int health;
    int attck;
    int defense;
    int speed;
    
public:
    //Used to set initial values
    
    void setHlth(int);
    void setAttk(int);
    void setDfns(int);
    void setSpd(int);
    //Used for battle calculations and reassign 
    int getHlth();
    int getAttk();
    int getDfns();
    int getSped();
    string getName();
    void setName(string);
    
};

class Dragon:public Enemy
{
public:
    Dragon()
    {
        setName("Dragon");
        setHlth(200);
        setAttk(25);
        setDfns(10);
        setSpd(2);
    }
    
};

class Goblin:public Enemy
{
public:
    Goblin()
    {
        setName("Goblin");
        setHlth(50);
        setAttk(5);
        setDfns(5);
        setSpd(4);
    }
};
class HellHound:public Enemy
{
public:
    HellHound()
    {
        setName("Hell Hound");
        setHlth(25);
        setAttk(10);
        setDfns(4);
        setSpd(6);
    }
};
class Kobold:public Enemy
{
public:
    Kobold()
    {
        setName("Kobold");
        setHlth(40);
        setAttk(8);
        setDfns(0);
        setSpd(4);
    }
};
class GiantBat:public Enemy
{
public:
    GiantBat()
    {
        setName("Giant Bat");
        setHlth(15);
        setAttk(5);
        setDfns(5);
        setSpd(8);
    }
};
class Minotaur:public Enemy
{
public:
    Minotaur()
    {
        setName("Minotaur");
        setHlth(100);
        setAttk(15);
        setDfns(10);
        setSpd(3);
    }
};
class Zombie:public Enemy
{
public:
    Zombie()
    {
        setName("Zombie");
        setHlth(1);
        setAttk(100000000);
        setDfns(0);
        setSpd(1);
    }
};


#endif /* ENEMY_H */

