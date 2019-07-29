
#include "network.h"
#include "neurons.h"
#include "bs_train_stimuli.h"
#include "bs_trans_stimuli.h"
#include "nc_trans_stimuli.h"
#include "IZK.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void randomize ( int arr[], int n )
{
    // Use a different seed value so that we don't get same
    // result each time we run this program
    srand ( time(NULL) );
 
    // Start from the last element and swap one by one. We don't
    // need to run for the first element that's why i > 0
    for (int i = n-1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i+1);
 
        // Swap arr[i] with the element at random index
        swap(&arr[i], &arr[j]);
    }
}

//for good ol' debugging
void printArray (int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<endl;
}

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

	//transfer stimuli
	int trans_stim[200][3];
	memcpy(trans_stim, bs_trans_stim, sizeof(trans_stim));

	//sets the randomized order for trans stim
	int train_stim_order[400];
    for (int i=0; i<400; i++){
        train_stim_order[i]=i;
    }
    int trans_stim_order[200];
    for (int i=0; i<200; i++){
        trans_stim_order[i]=i;
    }
    randomize(train_stim_order, sizeof(train_stim_order)/sizeof(train_stim_order[0]));
    randomize(trans_stim_order, sizeof(trans_stim_order)/sizeof(trans_stim_order[0]));


	// for(int trial=0; trial<2; trial++){

	// 	//Reset neurons

	// 	//Euler steps
	// }

	return 0;
};
