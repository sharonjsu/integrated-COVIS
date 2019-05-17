#define IZK_H
#include "neurons.h"
class IZK : public Neuron{
public:

	double memCapacitance;
	double k;
	double a;
	double b;
	double c;
	double d;
	double u[3000];
	double cort_weights[100][100];
	bool isMSN;

	IZK();
	IZK(bool msn);
	double euler_step_v(int i, double noise = 0);
	double euler_step_u(int i);
	//void add_alpha_function(int i, double weight, double lambda, double pre_peak);

};

class QIF : public Neuron {
public:
	QIF();
	double beta;
	double gamma;
	double vreset;


	double euler_step_v(int i, double noise=0);
	//void add_alpha_function(int i, double weight, double lambda, double pre_peak);

};

