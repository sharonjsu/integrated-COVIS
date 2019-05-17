#ifndef two_Stage_H
#define two_Stage_H
#include "IZK.h"
#include "QIF.h"
#include <random>

using namespace std;

// struct DA_sys{
// 	DA_sys();
// 	double r;
// 	double p;
// 	double rpe;
// 	double predicted_reward();
// 	//double obtained_reward(); //probably put in network
// 	double D();

// }

class two_stage{
public:
	two_stage();
	char getGuess();

private:
	double cortex_in();
	double obtained_reward(char f);
	double da_R;
	double da_P;
	double da_RPE;
	double predicted_reward();
	double D();
	//
	Neuron bodyandtail_1,bodyandtail_2,GPi_1,GPi_2,VA_1,VA_2,PreSMA_1,PreSMA_2, putamen_A,putamen_B,GPi_A,GPi_B,VL_A,VL_B,SMA_A,SMA_B,motor_a,motor_b;
	double bta_btb[2]={-3.5,-30};
    double gpi_bt[2]={-0.0055,-35};
    double va_gpi[2]={-0.005,-25};
    double presma_va[2]={2,-35};
    double puta_presma1[2]={1.75 + 0.1 * gsl_rng_uniform(rng),-40};
    double puta_presma2[2]={1.75 + 0.1 * gsl_rng_uniform(rng),-40};
    double putb_presma1[2]={1.75 + 0.1 * gsl_rng_uniform(rng),-40};
    double putb_presma2[2]={1.75 + 0.1 * gsl_rng_uniform(rng),-40};
    double gpi_put[2]={-0.0065,-35};
    double motor_sma[2]={0.085,-35};

}