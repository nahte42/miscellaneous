#include <iostream>
#include <cstdlib>
#include <cmath>

#ifndef LIST_H
#define LIST_H

class LinkedList
{
private:
	struct Node{
		int data;
		Node* next;
	};
	
public:
	Node *head, *listNode, *temp;
	
	LinkedList(){head = NULL; temp = NULL; listNode = NULL;}
	LinkedList *fillList(int data);
	void printLst();
	int sumList();
};
  
#endif