#ifndef IZK_H
#define IZK_H
#include "IZK.h"
#include "QIF.h"
#include <string>

using namespace std;

//Consider removing, is unnecessary.
//Make sure you model this code after the python code; not the c code...
class network{
public:
	network();
	Neuron* head1ptr;
	Neuron* head2ptr;
	Neuron* end1ptr;
	Neuron* end2ptr;
	DA_sys* dopamine;
	void createNet(); // change this to a constructor later
	void addNeuron(Neuron* ptr, string type) // ptr and type of neuron/neuron parameters
	void oneTrial(); // will use update weights.
	void updateWeights();

	//DA stuff

	double predicted_reward();
	double obtained_reward(); //probably put in network
	double D();
}

struct DA_sys{
	DA_sys();
	double r;
	double p;
	double rpe;
	// double predicted_reward();
	// double obtained_reward(); //probably put in network
	// double D();

}
