/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Character.h
 * Author: Ethan
 *
 * Created on May 26, 2017, 4:38 PM
 */

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#ifndef CHARACTER_H
#define CHARACTER_H

class Hero
{
private:
    string name;
    string location;
    int health,attk,spd,luck,strn;
    
public:
    Hero();
    string CurrentWeapon;
    string getName(string);
    int getHealth();
    int getAttack();
    int getSpeed();
    int getLuck();
    int getStrength();
    string getWepn(string);
    string SwapWeapon(string);
    void setHealth(int);
};



#endif /* CHARACTER_H */

