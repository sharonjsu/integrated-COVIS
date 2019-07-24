
#define NEURONS_H
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


//Neuron is a parent class for IZH and QIF.

class Neuron{
public:
	Neuron();
	int n = 3000;
	double vthresh;
	double vpeak;
	double vrest;
	vector<double> u;
	vector<double> I; // CONSIDER CHANGING TO VECTORS
	vector<double> v;
	//double updated_weight();
	//double S(double v[3000]);
	//void add_alpha_function(int i, double weight, double lambda, double pre_peak);
	void reset();
	//double max(double a, double b);

/*
	// Consider using a vector of pointers for input.
	// might be better in network.h, or better yet, implemented
	Neuron* input1=NULL;
	Neuron* input2=NULL;*/
};

