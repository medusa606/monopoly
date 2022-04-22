#include "stdafx.h"
#include <iostream>
#include "TileData.h"
#include "playerClass.h"
using namespace std;

void PrintMenu(int x)
{
	switch (x)
	{
		case 1: 
			cout<<"\t1: Brown"<<endl;
			break;
		case 2: 
			cout<<"\t2: Purple"<<endl;
			break;
		case 3: 
			cout<<"\t3: Blue"<<endl;
			break;
		case 4: 
			cout<<"\t4: Pink"<<endl;
			break;
		case 5: 
			cout<<"\t5: Orange"<<endl;
			break;
		case 6: 
			cout<<"\t6: Red"<<endl;
			break;
		case 7: 
			cout<<"\t7: Yellow"<<endl;
			break;
		case 8: 
			cout<<"\t8: Green"<<endl;
			break;
		case 9: 
			cout<<"\t9: Rail"<<endl;
			break;
		case 10: 
			cout<<"\t10: Utilities"<<endl;
			break;		
	}
}