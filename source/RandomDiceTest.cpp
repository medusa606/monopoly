//Test to calculate distribution of the numbers rolled on a six sided die

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include "diceheader.h"
using namespace std;

	//function prototype
		int DiceRoll();

void RandomDiceTest(DiceParams x){

	
	//set the number of random loops
		int nRandLoops = 6000000,i,rolledNumber;


	//generate a sequence to confirm randomness
	for (i=0; i<nRandLoops; ++i){
		rolledNumber = DiceRoll();
		/*randDouble = (b-a) * (rand()/double(RAND_MAX)) + a;
		diceRoll = floor(randDouble+0.5);*/
		if (rolledNumber == 1)
			x.s_testDistribution.n1++;
		if (rolledNumber == 2)
			x.s_testDistribution.n2++;
		if (rolledNumber == 3)
			x.s_testDistribution.n3++;
		if (rolledNumber == 4)
			x.s_testDistribution.n4++;
		if (rolledNumber == 5)
			x.s_testDistribution.n5++;
		if (rolledNumber == 6)
			x.s_testDistribution.n6++;		
		}

	cout << "Number of 1,2,3,4,5,&6 "	<< x.s_testDistribution.n1 << 
									"," << x.s_testDistribution.n2 << 
									"," << x.s_testDistribution.n3 << 
									"," << x.s_testDistribution.n4 << 
									"," << x.s_testDistribution.n5 << 
									"," << x.s_testDistribution.n6;

	cout	<< "\nError in even distribution is: \n" 
			<< "n1 = " << x.s_testDistribution.n1/(6*nRandLoops) << " \n "
			<< "n2 = " << x.s_testDistribution.n2/(6*nRandLoops) << " \n "
			<< "n3 = " << x.s_testDistribution.n3/(6*nRandLoops) << " \n "
			<< "n4 = " << x.s_testDistribution.n4/(6*nRandLoops) << " \n "
			<< "n5 = " << x.s_testDistribution.n5/(6*nRandLoops) << " \n "
			<< "n6 = " << x.s_testDistribution.n6/(6*nRandLoops) << endl;

	//if statement to check randomness?

}