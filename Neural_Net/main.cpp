#include <iostream>
#include <string>
#include <vector>
#include "Neuron_Net.h"

using namespace std;

int main()
{
	vector<unsigned> topology;
	for (int i = 0; i < 4; i++){
		topology.push_back(i);
	}
	Net myNet(topology);
	
	vector<double> inpVals;
	for (int i = 0; i < 4; i+=.1){
		inpVals.push_back(i);
	}
	myNet.feedForward(inpVals);
	
	vector<double> tgtVals;
	myNet.backProp(tgtVals);
	
	vector<double> outVals;
	myNet.getResults(outVals);
}

// Create Testing Data
// Fill Target Values
// And Input Values
// Recieve Output Values