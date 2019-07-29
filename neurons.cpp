#include "neurons.h"
#include <algorithm>

Neuron::Neuron(){
	for (int i = 0; i < 3000; i++){
		v[i] = vrest;
		I[i]= 0;
	}
	cout<<"Neuron created with type ";
}

void Neuron::reset(){
	cout<<"Calling reset from neuron rather than overwritten function"<<endl;
}

void Neuron::reset(double ok){
	cout<<"Calling reset from neuron (DOUBLEOK) rather than overwritten function"<<endl;
}

double max(double a, double b){
    if (a >= b){
        return a;
    }
    else {
        return b;
    }
}

double updated_weight(double w, double D_n, double I, double S, double D_base, double a,
        double b, double g, double tN, double tA, double w_max){
    return w + a*I*max(0,S-tN)*max(0,D_n-D_base)*(w_max-w) - b*I*max(0,S-tN)*max(0,D_base-D_n)*w - g*I*(max(0,(max(0,tN-S)-tA)))*w;
}

double S(double v[3000]){
    double ans;
    ans = 0;
    for (int t=0; t<3000; t++){
        ans = ans + max(0,v[t]);
    }
    return ans;
};

// void Neuron::updateInputs(int time){

// }

// void Neuron::updateOutputs(int time){}
//};
