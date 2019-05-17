#include "two_stage.h"

using namespace std;

two_stage::two_stage(){
	//initializing
	bodyandtail_1=IZK(true);
	bodyandtail_2=IZK(true);
	GPi_1=QIF();
	GPi_2=QIF();
	VA_1=QIF();
	VA_2=QIF()
	PreSMA_1=IZK();
	PreSMA_2=IZK();
	putamen_A=IZK(true);
	putamen_B=IZK(true);
	GPi_A=QIF();
	GPi_B=QIF();
	VL_A=QIF();
	VL_B=QIF();
	SMA_A=IZK();
	SMA_B=IZK();
	motor_a=QIF();
	motor_b=QIF();
	//
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

}