#include "QIF.h"

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
