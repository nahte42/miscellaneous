/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>

#include "Character.h"

using namespace std;

Hero::Hero()
{
   srand((unsigned)(int)(time(0)));
   int mod = rand()%10/2+1;
   health = 100;
   attk = mod;
   mod = rand()%10/2+1;
   spd = mod;
   mod = rand()%10/2+1;
   luck = mod;
   mod = rand()%10/2+1;
   strn = mod;
}


int Hero::getAttack()
{
    return attk;
}

int Hero::getLuck()
{
    return luck;
}

int Hero::getStrength()
{
    return strn;
}

int Hero::getSpeed()
{
    return spd;
}

int Hero::getHealth()
{
    return health;
}

string Hero::getWepn(string wpn)
{

    return CurrentWeapon;
}

string Hero::SwapWeapon(string wpn)
{
    CurrentWeapon = wpn;
    return CurrentWeapon;
}

void Hero::setHealth(int a)
{
    health = a;
}