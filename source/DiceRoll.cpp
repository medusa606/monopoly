#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int DiceRoll()
{

//create seed value for random number generation base on clock time
	//void seed();
	//srand(unsigned(time(0)));

//initialise the limits of the random number sequence
	double a=0.5, b=6.5;

//declare variables
	double randDouble;
	int nRoll;

//generate the random number and convert to an integer
	randDouble = (b-a) * (rand()/double(RAND_MAX)) + a;
	//nRoll = static_cast<int>floor(randDouble+0.5);
	nRoll = floor(randDouble+0.5);

	return nRoll;

}