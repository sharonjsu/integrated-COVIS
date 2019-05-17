#include "IZK.h"
#include <random>
using namespace std;

int main(){
	//initializing network.
	IZK bodyandtail_1(true);
	IZK bodyandtail_2(true);
	QIF GPi_1;
	QIF GPi_2;
	QIF VA_1;
	QIF VA_2;
	IZK PreSMA_1;
	IZK PreSMA_2;
	IZK putamen_A(true);
	IZK putamen_B(true);
	QIF GPi_A;
	QIF GPi_B;
	QIF VL_A;
	QIF VL_B;
	IZK SMA_A;
	IZK SMA_B;
	QIF motor_a;
	QIF motor_b;
	//changing parameters
	GPi_1.beta=12.1;
    GPi_2.beta=12.1;
    VA_1.beta=11.95;
    VA_2.beta=11.95;
    GPi_A.beta=12.1;
    GPi_B.beta=12.1;
    VL_A.beta=11.95;
    VL_B.beta=11.95;
    motor_a.beta=0;
    motor_b.beta=0;
    // putting in lists 
    IZK *izlist[8];
    izlist[0]=&bodyandtail_1;
    izlist[1]=&bodyandtail_2;
    izlist[2]=&PreSMA_1;
    izlist[3]=&PreSMA_2;
    izlist[4]=&putamen_A;
    izlist[5]=&putamen_B;
    izlist[6]=&SMA_A;
    izlist[7]=&SMA_B;

    QIF *qilist[10];
    qilist[0]=&GPi_1;
    qilist[1]=&GPi_2;
    qilist[2]=&VA_1;
    qilist[3]=&VA_2;
    qilist[4]=&GPi_A;
    qilist[5]=&GPi_B;
    qilist[6]=&VL_A;
    qilist[7]=&VL_B;
    qilist[8]=&motor_a;
    qilist[9]=&motor_b;

  	default_random_engine rng;
  	normal_distribution<double> distribution(5.0,2.0);

    // connections
    double bta_btb[2]={-3.5,-30};
    double gpi_bt[2]={-0.0055,-35};
    double va_gpi[2]={-0.005,-25};
    double presma_va[2]={2,-35};
    double puta_presma1[2]={1.75 + 0.1 * distribution(rng),-40};
    double puta_presma2[2]={1.75 + 0.1 * distribution(rng),-40};
    double putb_presma1[2]={1.75 + 0.1 * distribution(rng),-40};
    double putb_presma2[2]={1.75 + 0.1 * distribution(rng),-40};
    double gpi_put[2]={-0.0065,-35};
    double motor_sma[2]={0.085,-35};

    // for (int trial = 0; trial < 600; trial++){
    // 	//load stim

    // 	//reset the neuron v, u, and I.

    // 	//
    // 	for (int t =0;t<2999;t++){
    // 		//do eulers
    // 		//if v[t]>vpeak, add alpha function
    // 		//if motor_a v[t]>vpeak, spike+1
    // 		//if spikes>30 guess = that one
    // 	}
    // }

    // return;
}
