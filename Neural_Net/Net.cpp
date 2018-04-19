#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include "Neuron_Net.h"



using namespace std;

Net::Net(const vector<unsigned> &topology){
	unsigned numLayers = topology.size();
	
	for(unsigned layerNum = 0; layerNum < numLayers; layerNum++)
	{
		m_layers.push_back(Layer());
		unsigned numOutputs = layerNum == topology.size() - 1 ? 0 : topology [layerNum + 1];
		
		//we made a new layer, fill it with neurons
		//and add a bias neuron to the layer:
		for(unsigned neuronNum = 0; neuronNum <= topology[layerNum]; neuronNum++)
			{
				m_layers.back().push_back(Neuron(numOutputs, neuronNum));
				cout<<"Made a Neuron!"<<endl;
			}
	}
}

void Net::feedForward(const vector<double> &inpVals){
	assert(inpVals.size() == m_layers[0].size() - 1);
	
	//Assign latch the input values into the input neurons
	
	for(unsigned i = 0; i < inpVals.size(); i++)
	{
		m_layers[0][i].setOutputVal(inpVals[i]); 
	}
	
	//Forward Propogate
	for (unsigned layerNum = 1; layerNum < m_layers.size(); layerNum++)
	{
		Layer &prevLayer = m_layers[layerNum - 1];
		for (unsigned n = 0; n < m_layers[layerNum].size() - 1; n++)
		{
			m_layers[layerNum][n].feedForward(prevLayer);
		}
	} 
}

void Net::backProp(const vector<double> &trgtVals)
{
	//calc overal net error ()RMS
	
	Layer &outputLayer = m_layers.back();
	m_error = 0.0;
	
	for(unsigned n = 0; n < outputLayer.size() - 1; n++)
	{
		cout<<trgtVals[n]<<endl;
		double delta = trgtVals[n] - outputLayer[n].getOutputVal();
		m_error += delta *delta;
		
	}
	m_error /+ outputLayer.size()-1;
	m_error = sqrt(m_error);
	
	//Avg error
	 m_recentAvgErr = 
					( m_recentAvgErr *  m_recentAvgErrSmthFctr + m_error)
					/ (m_recentAvgErrSmthFctr + 1.0);
	
	//calcualte output layer gradients
	
	for(unsigned n = 0; n < outputLayer.size()-1; n++)
		{
			outputLayer[n].calOpGrad(trgtVals[n]);
		}
	//calculate gradients on hidden layers
	
	for(unsigned layerNum = m_layers.size()-2; layerNum > 0; layerNum--)
	{
		Layer &hiddenLayer = m_layers[layerNum];
		Layer &nextLayer = m_layers[layerNum + 1];
		
		for (unsigned n = 0; n < hiddenLayer.size(); n++)
		{
			hiddenLayer[n].calHidGrad(nextLayer);
		}
	}
	
	//Update weights
	for(unsigned layerNum = m_layers.size() - 1; layerNum > 0; layerNum--)
	{
		Layer &layer = m_layers[layerNum];
		Layer &prevLayer = m_layers[layerNum - 1];
		
		for(unsigned n = 0; n < layer.size() - 1; n++)
		{
			layer[n].updInpWts(prevLayer);
		}
	}
}

void Net::getResults(vector<double> &outVals) const
{
	outVals.clear();
	
	for(unsigned n = 0; n < m_layers.back().size() - 1; n++)
		outVals.push_back(m_layers.back()[n].getOutputVal());
}



//*******************-Neuron Functions-********************

double Neuron::eta = 0.15;
double Neuron::alpha = 0.5;

Neuron::Neuron(unsigned numOutputs, unsigned myIndex){

		for (unsigned c = 0; c < numOutputs; c++)
		{
			m_outputWeights.push_back(Connection());
			m_outputWeights.back().weight = randomWeight();
		}
		
		m_myIndex = myIndex;
}


void Neuron::feedForward(const Layer &prevLayer)
{
	double sum = 0.0;
	
	//sum the prev layers outputs 
	//include the bias node from previous node
	
	for (unsigned n = 0; n < prevLayer.size(); n++)
	{
		sum += prevLayer[n].getOutputVal() * prevLayer[n].m_outputWeights[m_myIndex].weight;
	}
	
	m_outputVal = Neuron::transferFunction(sum); 
}

double Neuron::transferFunction(double x)
{
	return tanh(x);
}

double Neuron::transferFunctionDeriv(double x)
{
	return 1.0 - x*x;
}

void Neuron::calOpGrad(double tgtVal)
{
	double delta = tgtVal - m_outputVal;
	m_gradient = delta * Neuron::transferFunctionDeriv(m_outputVal);
}

void Neuron::calHidGrad(const Layer &nextLayer)
{
	double dow = sumDow(nextLayer);
	m_gradient = dow * Neuron::transferFunctionDeriv(m_outputVal);
}

double Neuron::sumDow(const Layer &nextLayer)
{
	double sum = 0.0;
	
	for (unsigned n = 0; n < nextLayer.size() - 1; n++)
	{
		sum += m_outputWeights[n].weight * nextLayer[n].m_gradient;
	}
	
	return sum;
}

void Neuron::updInpWts(Layer &prevLayer)
{
	for (unsigned n = 0; n < prevLayer.size(); n++)
	{
		Neuron &neuron = prevLayer[n];
		double oldDeltaWeight = neuron.m_outputWeights[m_myIndex].deltaWeight;
		
		double newDeltaWeight = 
							//individual input magnifies by the gradient and train rate
							eta 
							* neuron.getOutputVal()
							* m_gradient
							+ alpha
							* oldDeltaWeight;
		 neuron.m_outputWeights[m_myIndex].deltaWeight = newDeltaWeight;
		 neuron.m_outputWeights[m_myIndex].weight += newDeltaWeight;
		
	}
	
}

double Neuron::getOutputVal() const
{ 
	return m_outputVal;
}

void Neuron::setOutputVal(double val)
{
	m_outputVal = val;
}