#ifndef diceheader_h
#define diceheader_h

	//structure to keep distribution of dice test
		struct DiceDistribution{double n1;double n2;double n3;double n4;double n5;double n6;};


	//declare structure to store dice parameters
		struct DiceParams{
			int		nFirstRoll;
			int		nSecondRoll;
			int		nDoubleRolled;
			int		nDoubleCount; 
			int		nMoveSpaces;	
			DiceDistribution s_testDistribution;};

	
			

#endif