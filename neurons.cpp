#include "neurons.h"
#include <algorithm>

//Constructor for QIF  neuron
Neuron::Neuron(){
	vector<double> I(n, 0.0);
	vector<double> v(n, vrest);
	vector<double> u(n,0.0);
}

void Neuron::reset(){
	this->v = fill(this->v.begin(), this->v.end(), this->vrest);
	this->u = fill(this->u.begin(), this->u.end(), 0.0);
	this->I= fill(this->I.begin(), this->I.end(), 0.0);
};

// void Neuron::updateInputs(int time){

// }

// void Neuron::updateOutputs(int time){}
//};
