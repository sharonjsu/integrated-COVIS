
#include "network.h"
#include "neurons.h"
#include "bs_train_stimuli.h"
#include "bs_trans_stimuli.h"
#include "nc_trans_stimuli.h"
#include "IZK.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<random>
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
    //used in gaussian stimulation
    double g[100][100];
    int A_spikes;
    int B_spikes;
    char guess;

	default_random_engine generator;
	uniform_real_distribution<double> distribution(0.0,1.0);
	normal_distribution<double> gaus_dist(0,100.0);

	network* one_stage = new network();

	IZK* body_tail_1 = new IZK("body_tail_1");
	one_stage->setHead(body_tail_1, 1);
	
	IZK* body_tail_2 = new IZK("body_tail_2");
	one_stage->setHead(body_tail_2,2);
	
	QIF* gpi_1 = new QIF(12.1, "gpi_1");
	one_stage->addConnection(body_tail_1,gpi_1,-0.0055,-35);

	QIF* gpi_2 = new QIF(12.1,"gpi_2");
	one_stage->addConnection(body_tail_2,gpi_2, -0.0055,-35);

	QIF* VA_1 = new QIF(11.95,"VA_1");
	one_stage->addConnection(gpi_1,VA_1,-0.005,-25);

	QIF* VA_2 = new QIF(11.95,"VA_2");
	one_stage->addConnection(gpi_2,VA_2,-0.005,-25);

	vector<shared_ptr<IZK>> izklist;

	vector<shared_ptr<QIF>> qiflist;
	izklist.emplace_back(body_tail_1);
	izklist.emplace_back(body_tail_2);

	qiflist.emplace_back(gpi_1);
	qiflist.emplace_back(gpi_2);
	qiflist.emplace_back(VA_1);
	qiflist.emplace_back(VA_2);

	 // for (vector<shared_ptr<Neuron>>::iterator it = neuronlist.begin() ; it != neuronlist.end(); ++it){
	 // 	cout<< (*it)->name <<endl;
	 // }
	for(int trial=0; trial<2; trial++){
		int stimx;
		int stimy;
		char corr_ans;
		if(trial<400){
			stimx = train_stim[train_stim_order[trial]][0];
			stimy = train_stim[train_stim_order[trial]][1];
			if (train_stim[train_stim_order[trial]][2]==0){
				corr_ans='a';
			}
			else {
				corr_ans='b';
			}
		}
		else{
			stimx = trans_stim[trans_stim_order[trial-400]][0];
			stimy=trans_stim[trans_stim_order[trial-400]][1];
			if (trans_stim[trans_stim_order[trial-400]][2]==0){
				corr_ans='a';
			}
			else{
				corr_ans='b';
			}
		}
		one_stage->gaussian_stimulation(stimx,stimy,61,25.1,g);
        double a_stim=one_stage->cortex_in(g, one_stage->a_sensory_weights);
        double b_stim=one_stage->cortex_in(g, one_stage->b_sensory_weights);
		//Reset neurons
		
		for (vector<shared_ptr<IZK>>::iterator it = izklist.begin() ; it != izklist.end(); ++it){
			if((*it)->name == "body_tail_1"){
				(*it)->reset(a_stim);
			}			
			else if((*it)->name == "body_tail_2"){
				(*it)->reset(b_stim);
			}
			else{
	 			(*it)->reset();
	 		}
	 	}

		for (vector<shared_ptr<QIF>>::iterator itk = qiflist.begin() ; itk != qiflist.end(); ++itk){
			(*itk)->reset();
	 	}
		A_spikes = 0;
		B_spikes = 0;
		guess = 'u';

		//Euler steps

		for (int t=0;t<2;t++){
			cout<<"time "<<t<<endl;;
			for (vector<shared_ptr<IZK>>::iterator it = izklist.begin() ; it != izklist.end(); ++it){
				cout<< "v: "<<(*it)->euler_step_v(t,gaus_dist(generator))<<" ";
				cout<< "u: "<<(*it)->euler_step_u(t)<<endl;
				//if((*it)->v[t+1])
			}
		}
	}

	return 0;
};
