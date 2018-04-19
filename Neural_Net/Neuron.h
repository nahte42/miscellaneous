#include "Net.h"


using namespace std;

#ifndef NEURON_H
#define NEURON_H

struct Connection{
	double weight;
	double deltaWeight;
};


//****************************************************
class Neuron{
private:
	static double randomWeight(void) { return rand()/double (RAND_MAX);}
	double m_outputVal;
	vector<Connection> m_outputWeights;
public:
	Neuron(unsigned numOutputs);
	void feedForward(Layer &)
	
};

#endif