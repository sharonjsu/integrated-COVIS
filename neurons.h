#ifndef NEURONS_H
#define NEURONS_H
#include <iostream>
#include <cmath>
using namespace std;
#include <string>

//Neuron is a parent class for IZH and QIF.

class Neuron{
public:
	Neuron();
	string name;
	int n = 3000;
	double vthresh;
	double vpeak;
	double vrest;
	double I[3000]; // changed to arrays
	double v[3000];
	double updated_weight(double w, double D_n, double I, double S, double D_base, double a,
        double b, double g, double tN, double tA, double w_max);
	double S(double v[3000]);
	//void add_alpha_function(int i, double weight, double lambda, double pre_peak);
	void reset();
	void reset(double ok);
	double max(double a, double b);



	// Consider using a vector of pointers for input.
	// might be better in network.h, or better yet, implemented
	Neuron* input1 = NULL;
	double weight1 = 0.0;
	double lambda1 = 0.0;
	Neuron* input2 = NULL;
	double weight2 = 0.0;
	double lambda2 = 0.0;
};
#endif