#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int doubleRoll()
{

//create seed value for random number generation base on clock time
	//void seed();
	//srand(unsigned(time(0)));

//initialise the limits of the random number sequence
	double a=0.5, b=6.5;

//declare variables
	double randDouble;
	int firstRoll, secondRoll;
	int rolledDouble,i;

//generate the random number and convert to an integer
	for (i=1; i<2; ++i){
	randDouble = (b-a) * (rand()/double(RAND_MAX)) + a;
	firstRoll = floor(randDouble+0.5);
	randDouble = (b-a) * (rand()/double(RAND_MAX)) + a;
	secondRoll = floor(randDouble+0.5);
	}

//check if a double was rolled
	if(firstRoll == secondRoll, rolledDouble=1)

	return firstRoll, secondRoll, rolledDouble;

}