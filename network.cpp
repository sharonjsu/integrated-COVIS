
//#include "IZK.h"
#include "network.h"
using namespace std;

network::network(){
	head1ptr = NULL;
	end1ptr= NULL;
	head2ptr= NULL;
	end2ptr = NULL;
	dopamine =NULL;
}

//Haven't checked
void network::addConnection(Neuron* outputNeuron, Neuron* target){
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


//DA stuff

double network::obtained_reward(char f){
    if (f=='c'){
        return 1.0;
    }
    if (f=='i'){
        return -1.0;
    }
    else {
        return 0.0;
    }
}

double network::predicted_reward(DA_sys d){
    return d.p + 0.025*(d.r-d.p);
}

double network::D(DA_sys d){
    if (d.rpe > 1.0){
        return 1.0;
    }
    if (d.rpe > -0.25 && d.rpe <= 1.0){
        return 0.8*d.rpe+0.2;
    }
    else {
        return 0.0;
    }
};