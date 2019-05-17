	#ifndef QIF_H
#define QIF_H
#include "neurons.h"
//using namespace std;

class QIF : public Neuron {
public:
	QIF();
	double beta;
	double gamma;
	double vreset;


	double euler_step_v(int i, double noise=0);
	//void add_alpha_function(int i, double weight, double lambda, double pre_peak);

};
#endif