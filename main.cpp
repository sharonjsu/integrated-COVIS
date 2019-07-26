
#include "network.h"
#include "neurons.h"
#include "IZK.h"
using namespace std;


int main(){
	network* one_stage = new network();
	IZK* body_tail_1 = new IZK();
	one_stage->setHead(body_tail_1, 1);
	
	IZK* body_tail_2 = new IZK();
	one_stage->setHead(body_tail_2,2);
	
	QIF* gpi_1 = new QIF(12.1);
	one_stage->addConnection(body_tail_1,gpi_1,-0.0055,-35);

	QIF* gpi_2 = new QIF(12.1);
	one_stage->addConnection(body_tail_2,gpi_2, -0.0055,-35);

	QIF* VA_1 = new QIF(11.95);
	one_stage->addConnection(gpi_1,VA_1,-0.005,-25);

	QIF* VA_2 = new QIF(11.95);
	one_stage->addConnection(gpi_2,VA_2,-0.005,-25);

	// for(int trial=0; trial<2; trial++){
	// 	//Load stimulus

	// 	//Reset neurons

	// 	//Euler steps
	// }

	return 0;
};
