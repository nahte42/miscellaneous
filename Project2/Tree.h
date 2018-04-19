//***************************
//                          *
//TREE FOR SOMETHING        *
//                          *
//***************************


/* 
 * File:   Tree.h
 * Author: Ethan
 *
 * Created on May 18, 2017, 9:06 PM
 */

#include <iostream>
#include <string>

using namespace std;

#ifndef TREE_H
#define TREE_H

class Tree
{
private:
    struct node
    {
        string key;
        node* left;
        node* right;
    };
    node* root;
    node* createLeaf(string key);
    node* returnNodePriv(string key, node* ptr);
    node* rightrotatePrive(node* root);
    node* leftRotatePriv(node* root);
    void addLeafPriv(string key, node* ptr);
    void printInOrderPriv(node* ptr);
    //void removeRootMatch();
    void removeMatch(node* parent, node* match, bool left);
    void removeNodePriv(string key, node* parent);
    string findSmallestPriv(node*);
public:
    //Constructor
    Tree();
    //Add and Create Leafs
    node* returnNode(string key);
    void addLeaf(string key);
    string returnRootKey();
    void printInOrder();
    void removeNode(string key);
    void removeRootMatch();
    string findSmallest();


};

#endif /* TREE_H */

