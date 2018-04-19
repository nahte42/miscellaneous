/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <cstdlib>
#include <cstring>

#include "Tree.h"

using namespace std;


Tree::Tree()
{
    root = NULL;
}

 Tree::node* Tree::createLeaf(string key)
{
    node* gnu = new node;
    gnu->key = key;
    gnu->left = NULL;
    gnu->right = NULL;
    
    return gnu;
}
 
 void Tree::addLeaf(string key)
 {
     addLeafPriv(key, root);
 }
 
 void Tree::addLeafPriv(string key, node* ptr)
 {
     if (root == NULL)
     {
         root=createLeaf(key);
     }
     else if(key < ptr->key)
     {
         if(ptr->left != NULL)
         {
             addLeafPriv(key, ptr->left);
         }
         else
         {
             ptr->left = createLeaf(key);
         }
     }
     else if(key > ptr->key)
     {
         if(ptr->right != NULL)
         {
             addLeafPriv(key, ptr->right);
         }
         else
         {
             ptr->right = createLeaf(key);
         }
     }
     else
         cout<<"Sorry you can only hold one of the item, I know thats stupid\n";
 }
 
 
 
string Tree::returnRootKey()
 {
     if (root != NULL)
         return root->key;
     else
         return "nah!";
 }

 void Tree::printInOrder()
 {
     printInOrderPriv(root);
 }



 void Tree::printInOrderPriv(node* ptr)
 {
     if (root!= NULL)
     {
         if (ptr->left != NULL)
         {
             printInOrderPriv(ptr->left);
         }
         cout<<ptr->key<<" ";
         if (ptr->right != NULL)
         {
              printInOrderPriv(ptr->right);
         }
     }
     else
     {
         cout<<"The tree is empty"<<endl;
     }
 }
 
 /*void Tree::removeNode(string key)
{
  removeNodePriv(key, root);   
}

void Tree::removeNodePriv(string key, node* parent)
{
    if (root != NULL)
    {
        if (root->key == key)
        {
            removeRootMatch();
        }
        else
        {
            if(key < parent->key.at(0) && parent-> key != NULL)
            {
                parent->left->key == key ?
                    removeMatch(parent, parent->left, true):    
                    removeNodePriv(key, parent->left);
            }
            else if(key>parent->key && parent-> key != NULL)
            {
                parent->right->key == key ?
                    removeMatch(parent, parent->right, true):    
                    removeNodePriv(key, parent->right);
            }
            else
            {
                cout<<"The Key "<<key<<" was not in the tree"<<endl;
            }
        }
    }
    else
    {
        cout<<"Empty Tree\n";
    }
}

void Tree::removeRootMatch()
{
    if(root != NULL)
    {
        node* delptr = root;
        string  rootKey = root->key;
        string smallestInRightSubtree;
        
        //Case 0 - 0 Children
        if (root->left == NULL && root->right == NULL)
        {
            root = NULL;
            delete delptr;
        }
        //case 1 - 1 Child
        else if (root ->left == NULL && root->right != NULL)
        {
            root = root->right;
            delptr->right = NULL;
            delete delptr;
            cout<<"The root node with key "<<rootKey<<" was deleted<<"
                    "The new root contains key"<<root->key<<endl;
        }
        else if (root ->left != NULL && root->right == NULL)
        {
            root = root->left;
            delptr->left = NULL;
            delete delptr;
            cout<<"The root node with key "<<rootKey<<" was deleted<<"
                    "The new root contains key"<<root->key<<endl;
        }
        //case 2 - 2 children
    }
    else
        cout<<"Empty Tree"<<endl;
}
string Tree::findSmallestPriv(node* ptr)
{
    if (root == NULL)
    {
        cout<<"The Tree Is Empty\n";
        return "";
    }
    else
    {
        if(ptr->left!=NULL)
        {
            return findSmallestPriv(ptr->left);
        }
        else
        {
            return ptr->key;
        }
    }
}

string Tree::findSmallest()
{
    return findSmallestPriv(root);
}
  * 
  * */