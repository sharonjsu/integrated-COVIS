#ifndef IZK_H
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
	//double v[];

	IZK();
	IZK(string neuronType);
	IZK(bool msn,string neuronType);
	double euler_step_v(int i, double noise = 0);
	double euler_step_u(int i);
	void add_alpha_function(int i, double weight, double lambda, double pre_peak);
	// int getType();
	void reset();
	void reset(double stim);

};

class QIF : public Neuron {
public:
	QIF();
	QIF(string neuronType);
	QIF(double betaSet, string name);
	double beta;
	double gamma;
	double vreset;
	void reset();
	double euler_step_v(int i, double noise=0);
	void add_alpha_function(int i, double weight, double lambda, double pre_peak);
	// int getType();
};

#endif