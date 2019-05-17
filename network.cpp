#ifndef IZK_H
#define IZK_H
#include "IZK.h"
#include "QIF.h"

using namespace std;




//Haven't checked
void addConnection(Neuron* outputNeuron, Neuron* target){
	// outputNeuron - Neuron whose output projects onto target's input.
	if (target->input1 == NULL){
		target->input1 = outputNeuron;
	}
	else if (target->input2 == NULL){
		target->input2 = outputNeuron;
	}
	else{
		cout<<"IT DOESN'T WORK"<<endl;
	}
}
