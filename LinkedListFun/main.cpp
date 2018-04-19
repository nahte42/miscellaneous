#include <iostream>
#include <cstdlib>
#include <cmath>
#include "List.h"
#include <time.h>
using namespace std;


int main(int argc, char **argv)
{
	srand (static_cast<unsigned int>(time(0)));
	int sum[4];
	LinkedList testLst[7];
	LinkedList temp;
	for (int i = 0; i < 7; i++)
		for (int n = 0; n < 7; n++)
			testLst[i].fillList(rand()%100);
	for(int i = 0; i < 7; i++)
	{	cout<<"List "<<i+1<<": ";
		testLst[i].printLst();
		cout<<endl;
	}
	cout<<endl;
	for(int i = 0; i < 7; i++)
		sum[i] = testLst[i].sumList();
		
	cout<<"The sum of the lists are: \n";
	for (int i = 0; i < 7; i++)
		cout<<"List "<<i+1<<": "<<testLst[i].sumList()<<endl;
	
	int i = 0;
	int itemp;
	bool flag = false;
	while (flag == false){
		flag = true;
		for (int i = 0; i < 6; i++)
		{
			if (sum[i] > sum[i+1])
			{
				itemp = sum[i];
				sum[i] = sum[i+1];
				sum[i+1] = itemp;
			
				temp = testLst[i];
				testLst[i] = testLst[i+1];
				testLst[i+1] = temp;
				flag = false;
			}
			
		}
		
		
	}
	
	cout<<endl;
	for(int i = 0; i < 7    ; i++)
	{	cout<<"List "<<i+1<<": ";
		testLst[i].printLst();
		cout<<endl;
	}
	
	return 0;
}
