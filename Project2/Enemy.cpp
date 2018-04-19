/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <iostream>
#include <string>

#include "Enemy.h"

using namespace std;

int Enemy::getHlth()
{
    return health;
}
int Enemy::getAttk()
{
    return attck;
}
int Enemy::getDfns()
{
    return defense;
}
int Enemy::getSped()
{
    return speed;
}

void Enemy::setHlth(int a)
{
    health = a;
}
void Enemy::setAttk(int a)
{
    attck = a;
}
void Enemy::setDfns(int a)
{
    defense = a;
}
void Enemy::setSpd(int a)
{
    speed = a;
   
}

void Enemy::setName(string a)
{
    name = a;
}
string Enemy::getName()
{
    return name;
}