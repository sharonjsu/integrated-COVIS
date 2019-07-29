#include "IZK.h"
//#include "neurons.h"
//Constructor for non-MSN IZK neuron
IZK::IZK(){
		memCapacitance=100.0; 
		Neuron::vrest=-60; 
		Neuron::vthresh=-40; 
		k=0.7; 
		a=0.03;
		b=-2;
		c=-50;
		d=100;
		Neuron::vpeak=35;
		isMSN=false;
		//double v[t] = {};
		cout <<"IZK"<<endl;

	}	
IZK::IZK(string neuronType){
		memCapacitance=100.0; 
		Neuron::vrest=-60; 
		Neuron::vthresh=-40; 
		k=0.7; 
		a=0.03;
		b=-2;
		c=-50;
		d=100;
		Neuron::vpeak=35;
		isMSN=false;
		//double v[t] = {};
		Neuron::name = neuronType;
		cout <<"IZK "<<Neuron::name<<endl;
	}
//Constructor for MSN IZK neuron
IZK::IZK(bool msn, string neuronType){
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
	Neuron::name = neuronType;
	cout <<"IZK "<<Neuron::name<<endl;
}

void IZK::reset(double stim){
	cout<<"resetting "<< Neuron::name<<", stim: "<<stim <<endl;
	for (int bins=0;bins<3000;bins++){
		Neuron::v[bins] = vrest;
		u[bins] = 0;
		//cout<<vrest<<" "<<Neuron::v[bins]<<" ";
		if (bins<500){
		    Neuron::I[bins] = 0;
		}
		else {
		    Neuron::I[bins] = stim;
		}
	}
	cout<<endl;
}

void IZK::reset(){
	for (int bins = 0; bins<3000; bins++){
		Neuron::v[bins] = vrest;
		Neuron::I[bins]=0;
		u[bins]=0;
	}
	cout<<"reset "<<Neuron::name<<" with izk fx"<<endl;
}

//same as euler_step_v_noise
double IZK::euler_step_v(int i, double noise){
	double step = Neuron::v[i] + (k*(Neuron::v[i]-Neuron::vrest)*(Neuron::v[i]-Neuron::vthresh)-u[i]+(Neuron::I[i]+noise))/memCapacitance;
	//cout<< memCapacitance<<endl;
	Neuron::v[i+1] = step;
	return step;
}

double IZK::euler_step_u(int i){
    double step = u[i] + a*(b*(Neuron::v[i]-Neuron::vrest)-u[i]);
    //cout<< a <<" "<< k <<" "<< b <<" "<< u[i]<<endl;
    u[i+1] = step;
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

QIF::QIF(string neuronType){
	beta=11.85;
	gamma=0.117;
	vrest=-60.0;
	vthresh=-40.0;
	vpeak=35;
	vreset=-50;
	Neuron::name = neuronType;
	cout <<"QIF "<<Neuron::name<<endl;
}

QIF::QIF(double betaSet, string neuronType){
	beta=betaSet;
	gamma=0.117;
	vrest=-60.0;
	vthresh=-40.0;
	vpeak=35;
	vreset=-50;
	Neuron::name = neuronType;
	cout <<"QIF "<<Neuron::name<<endl;
}
void QIF::reset(){
	for (int bins = 0; bins<3000; bins++){
		Neuron::v[bins] = vrest;
		Neuron::I[bins]=0;
	}
	cout<<"reset "<<Neuron::name<<" with qif fx"<<endl;

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
