#include "IZK.h"
//#include "neurons.h"
//Constructor for non-MSN IZK neuron
IZK::IZK(){
		memCapacitance=100; 
		vrest=-60; 
		vthresh=-40; 
		k=0.7; 
		a=0.03;
		b=-2;
		c=-50;
		d=100;
		vpeak=35;
		isMSN=false;
	}	
//Constructor for MSN IZK neuron
IZK::IZK(bool msn){
	isMSN=msn;
	memCapacitance=50;
	vrest=-80;
	vthresh=-25;
	k=1;
	a=0.01;
	b=-20;
	c=-55;
	d=150;
	vpeak=40;
}
double IZK::euler_step_v(int i, double noise){
	double step = v[i] + (k*(v[i]-vrest)*(v[i]-vthresh)-u[i]+(I[i]+noise))/memCapacitance;
	return step;
}

double IZK::euler_step_u(int i){
    double step = u[i] + a*(b*(v[i]-vrest)-u[i]);
    return step;
}

// void IZK::add_alpha_function(int i, double weight, double lambda, double pre_peak){
//     for (int j=i; j<3000; j++){
//         I[j] += weight*pre_peak*exp((lambda+(j-i))/lambda)*(i-j)/lambda;
//     }
// } 

//Constructor for QIF  neuron
QIF::QIF(){
	beta=11.85;
	gamma=0.117;
	vrest=-60.0;
	vthresh=-40.0;
	vpeak=35;
	vreset=-50;
}


// void QIF::add_alpha_function(int i, double weight, double lambda, double pre_peak){
//     for (int j=i; j<3000; j++){
//         I[j] = I[j] + weight*pre_peak*exp((lambda+(j-i))/lambda)*(i-j)/lambda;
//     }
// }

double QIF::euler_step_v(int i, double noise){
	double step = v[i] + gamma*(v[i]-vrest)*(v[i]-vthresh) + beta + (I[i]+noise);	
	return step;
}
