#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

int greatest(int n, int i, vector<int> v);

int main()
{
	srand(time(0));
	vector<int> numbers;
	
	numbers.push_back(rand());
	numbers.push_back(rand());
	numbers.push_back(rand());
	numbers.push_back(rand());
	numbers.push_back(rand());
	numbers.push_back(rand());
	
	for (int i = 0; i < numbers.size(); i++)
		cout<<numbers[i]<<endl;
	
	int GN = greatest(numbers[0],0, numbers);
	
	cout<<"The greatest number is: "<<GN<<endl;
	
	return 0;
}

int greatest(int n, int i, vector<int> v){
	if(i >= v.size()-1){
		return n;
	}
	if(n >= v[i]){
		return greatest(n, i+1,v);
	}
	if(n < v[i]){
		return greatest(v[i], i+1,v);
	}
}


