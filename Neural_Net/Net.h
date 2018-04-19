#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;
#ifndef NET_H
#define NET_H

typedef vector<Neuron> Layer;

class Net{
private:
	vector<Layer> m_layers; // m_layers[layersNum][neuronNum]
	
public:
	Net(const vector<unsigned> &topology);
	void feedForward(const vector<double> &inpVals);
	void backProp(const vector<double> &tgtVals);
	void getResults(vector<double> &outVals) const{};
};

#endif