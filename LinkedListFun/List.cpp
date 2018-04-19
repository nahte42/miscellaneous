   #include <iostream>
#include <cstdlib>
#include <cmath>
#include "List.h"

using namespace std;

LinkedList *LinkedList::fillList(int x)
{
	if (head == NULL)
	{
		listNode = new Node;
		listNode -> data = x;
		listNode -> next = head;
		head = listNode;
	}
	else{
		listNode = new Node;
		listNode -> data = x;
		listNode -> next = head;
		head = listNode;
	}
} 

void LinkedList::printLst()
{
	listNode = head;
	
	while(listNode != NULL)
	{
		cout<<listNode->data<<" ";
		listNode = listNode -> next;
	}
}

int LinkedList::sumList( )
{
	int listSum = 0;
	listNode = head;
	
	while(listNode != NULL)
	{
		listSum += listNode -> data;
		listNode = listNode -> next;
	}
	
	return listSum;
	
}