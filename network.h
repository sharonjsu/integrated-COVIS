
#include "neurons.h"
#include <string>

using namespace std;



struct DA_sys{
	DA_sys();
	double r;
	double p;
	double rpe;
	// double predicted_reward();
	// double obtained_reward(); //probably put in network
	// double D();
};

//class that will have different models.
//Make sure you model this code after the python code; not the c code...
class network{
public:
	network();
	Neuron* head1ptr;
	Neuron* head2ptr;
	Neuron* end1ptr;
	Neuron* end2ptr;
	DA_sys* dopamine;
	void addConnection(Neuron* outputNeuron, Neuron* target, double weight, double lambda);
	void setHead(Neuron* headNeuron, int whichIndex);
	void gaussian_stimulation(int stim_i, int stim_j, double amp, double cons, double a[100][100]);
	double cortex_in(double cort_input[100][100], double cort_weights[100][100]);

	// void oneStage();
	// void twoStage();
	// void oneTANS();
	// //add automaticity in later.

	// void addNeuron(Neuron* ptr, string type) // ptr and type of neuron/neuron parameters
	// void oneTrial(); // will use update weights.
	// void updateWeights(); //updates all weights at once

	//DA stuff

	double predicted_reward(DA_sys d);
	double obtained_reward(char f); //probably put in network
	double D(DA_sys d);
};
