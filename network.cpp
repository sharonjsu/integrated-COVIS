
//#include "IZK.h"
#include "network.h"
using namespace std;
#include <map>

network::network(){
	head1ptr = NULL;
	end1ptr= NULL;
	head2ptr= NULL;
	end2ptr = NULL;
	dopamine =NULL;
}

void network::setHead(Neuron* headNeuron, int whichIndex){
	if (whichIndex == 1){
		head1ptr = headNeuron;
		if (end1ptr == NULL)
			end1ptr = headNeuron;
	}
	if (whichIndex==2){
		head2ptr = headNeuron;
		if (end2ptr==NULL)
			end2ptr = headNeuron;
	}
	cout <<"Neuron set as network " << whichIndex <<" head."<< endl;
}




// string network::getCellType(Neuron* cell){
// 	map<int, string> indexToType;
// 	indexToType[1] = string("IZK");
// 	indexToType[2] = string("QIF")
// 	int k = cell->getType();
// 	return indexToType[k];
// }

//Haven't checked
void network::addConnection(Neuron* outputNeuron, Neuron* target, double weight, double lambda){
	// outputNeuron - Neuron whose output projects onto target's input.
	if (target->input1 == NULL){
		target->input1 = outputNeuron;
		target->weight1 = weight;
	}
	else if (target->input2 == NULL){
		target->input2 = outputNeuron;
		target->weight2 = weight;
	}
	else{
		cout<<"IT DOESN'T WORK"<<endl;
	}
	if(end1ptr == outputNeuron){
		end1ptr = target;
		cout <<"Neuron is now the end of network 1"<<endl;
	}
	if(end2ptr == outputNeuron){
		end2ptr = target;
		cout <<"Neuron is now the end of network 2"<<endl;
	}
}

void network::gaussian_stimulation(int stim_i, int stim_j, double amp, double cons, double a[100][100]){
    for (int i=0; i<100; i++){
        for (int j=0; j<100; j++){
            a[i][j] = amp * exp( - ((i-stim_i)*(i-stim_i) + (j-stim_j)*(j-stim_j))/cons);
        }
    }
}



double network::cortex_in(double cort_input[100][100], double cort_weights[100][100]){
    double temp=0;
    for (int i=0; i<100; i++){
        for (int j=0; j<100; j++){
            temp += cort_input[i][j]*cort_weights[i][j];
        }
    }
    return temp;
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