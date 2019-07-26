#include "IZK.h"
//#include "neurons.h"
//Constructor for non-MSN IZK neuron
IZK::IZK(){
		int memCapacitance=100; 
		int vrest=-60; 
		int vthresh=-40; 
		double k=0.7; 
		double a=0.03;
		double b=-2;
		double c=-50;
		double d=100;
		double vpeak=35;
		bool isMSN=false;
		//double v[t] = {};
		cout <<"IZK"<<endl;

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
//same as euler_step_v_noise
double IZK::euler_step_v(int i, double noise){
	double step = v[i] + (k*(v[i]-vrest)*(v[i]-vthresh)-u[i]+(I[i]+noise))/memCapacitance;
	return step;
}

double IZK::euler_step_u(int i){
    double step = u[i] + a*(b*(v[i]-vrest)-u[i]);
    return step;
}

// int IZK::getType(){
// 	return 1;
// }
 void IZK::add_alpha_function(int i, double weight, double lambda, double pre_peak){
     for (int j=i; j<3000; j++){
         I[j] += weight*pre_peak*exp((lambda+(j-i))/lambda)*(i-j)/lambda;
     }
 } 

//Constructor for QIF  neuron
QIF::QIF(){
	beta=11.85;
	gamma=0.117;
	vrest=-60.0;
	vthresh=-40.0;
	vpeak=35;
	vreset=-50;
	cout<<"QIF"<<endl;
}

QIF::QIF(double betaSet){
	beta=betaSet;
	gamma=0.117;
	vrest=-60.0;
	vthresh=-40.0;
	vpeak=35;
	vreset=-50;
	cout<<"QIF with beta "<< beta<<endl;
}


 void QIF::add_alpha_function(int i, double weight, double lambda, double pre_peak){
     for (int j=i; j<3000; j++){
         I[j] = I[j] + weight*pre_peak*exp((lambda+(j-i))/lambda)*(i-j)/lambda;
     }
 }

double QIF::euler_step_v(int i, double noise){
	double step = v[i] + gamma*(v[i]-vrest)*(v[i]-vthresh) + beta + (I[i]+noise);	
	return step;
}
// int QIF::getType(){
// 	return 2;
// }
