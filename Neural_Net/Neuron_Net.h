#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>


using namespace std;
#ifndef NET_H
#define NET_H
class Neuron;
typedef vector<Neuron> Layer;

struct Connection{
	double weight;
	double deltaWeight;
};


//****************************************************
class Neuron{
private:
	static double randomWeight(void) { return rand()/double (RAND_MAX);}
	static double transferFunction (double x);
	static double transferFunctionDeriv (double x);
	double m_outputVal;
	unsigned m_myIndex;
	double m_gradient;
	static double eta, alpha;
	double sumDow(const Layer &nextLayer);
	vector<Connection> m_outputWeights;
public:
	Neuron(unsigned numOutputs, unsigned myIndex);
	void feedForward(const Layer &prevLayer);
	void setOutputVal(double val);
	double getOutputVal(void)const;
	void calOpGrad(double trgtVals);
	void calHidGrad(const Layer &nextLayer);
	void updInpWts(Layer &prevLayer); //update input weights
	
};

//******************-NET CLASS-********************

class Net{
private:
	vector<Layer> m_layers; // m_layers[layersNum][neuronNum]
	double m_error;
	double m_recentAvgErr, m_recentAvgErrSmthFctr;
	
public:
	Net(const vector<unsigned> &topology);
	void feedForward(const vector<double> &inpVals);
	void backProp(const vector<double> &trgtVals);
	void getResults(vector<double> &outVals) const;
	
};

#endif

