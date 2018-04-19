#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int pascalsTriRec(vector<unsigned>, int);
int pascalsTriIte(int);

int main()
{
	int triNum;
	vector<unsigned> row0;
	vector<unsigned> row1;
	
		
	cout<<"Pascals Triangle up to what number?"<<endl;
	cin >> triNum;
	triNum++;
	
	//int timeBegRec = time(0);
	//for (int i  = 0; i < 10000; i++)
	pascalsTriRec(row1, triNum);
	//int timeEndRec = time(0);
	
	/*int timeBeg = time(0);
	for (int i  = 0; i < 10000; i++)
	pascalsTriIte(triNum);
	int timeEnd = time(0);
	cout<<"Total Time Iteration = "<<timeEnd - timeBeg << " seconds" <<endl;
	cout<<"Total Time Recursion = "<<timeEndRec - timeBegRec << " seconds" <<endl;*/
	
	
	return 0;
}

int pascalsTriRec(vector<unsigned> row, int triNum)
{
	if (triNum == 0)
		return 0;
	
	vector<unsigned> rowN;

	for(int i = 0; i < row.size()+1; i++){
		if(i == 0)
			rowN.push_back(1);
		else if(i == row.size())
			rowN.push_back(1);
			//cout<<"Adding the vectors"<<row[i]+row[i-1]<<endl;
		else
			rowN.push_back(row[i]+row[i-1]);
	}
	for(int i = 0; i < rowN.size(); i++)
		cout<<rowN[i]<<" ";
	cout<<endl;
	pascalsTriRec(rowN, triNum-1);
		
}
	
int pascalsTriIte(int rowNum){
	
	
	for (int i = 0; i < rowNum; i++)
		{
			int val = 1;
			for (int j = 1; j < (rowNum - i); j++)
			{
				cout << "   ";
			}
			for (int k = 0; k <= i; k++)
			{
				cout << "      " << val;
				val = val * (i - k) / (k + 1);
			}
			cout << endl << endl;
    }
    cout << endl;
}
	
		

	



//	int *arr = new int[size];
