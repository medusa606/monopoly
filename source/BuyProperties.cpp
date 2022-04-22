#include "stdafx.h"
#include <iostream>
#include "TileData.h"
#include "playerClass.h"
using namespace std;


float BuyProperties(int tile, int owner, PlayerClass *pAllPlayerClass, TileData *pTileData)
{

//what is the group colour?
	int group = -1;
	int maxPropertiesInGroup = -1;
	int nPropertiesInGroup = 0;
	bool allPropertiesInGroup = 0;
	float rent = 0;
	int siteLocations[4] = {0};
	char GBP = 156;
	owner += 1;			//indexed to i in GC01
	group = pTileData->m_nGroup[tile];
	

	switch(group)
	{
		case 1: 
			cout<<"The property group is Brown"<<endl;
			maxPropertiesInGroup = 2;
			break;
		case 2: 
			cout<<"The property group is Purple"<<endl;
			maxPropertiesInGroup = 2;
			break;
		case 3: 
			cout<<"The property group is Blue"<<endl;
			maxPropertiesInGroup = 3;
			break;
		case 4: 
			cout<<"The property group is Pink"<<endl;
			maxPropertiesInGroup = 3;
			break;
		case 5: 
			cout<<"The property group is Orange"<<endl;
			maxPropertiesInGroup = 3;
			break;
		case 6: 
			cout<<"The property group is Red"<<endl;
			maxPropertiesInGroup = 3;
			break;
		case 7: 
			cout<<"The property group is Yellow"<<endl;
			maxPropertiesInGroup = 3;
			break;
		case 8: 
			cout<<"The property group is Green"<<endl;
			maxPropertiesInGroup = 3;
			break;
		case 9: 
			cout<<"The property group is Rail"<<endl;
			maxPropertiesInGroup = 4;
			break;
		case 10: 
			cout<<"The property group is Utilities"<<endl;
			maxPropertiesInGroup = 2;
			break;
		default:
			cout<<"##BuyProperties##: The property group is unknown"<<endl;
			break;
	}
		
	int count=0;
	for(int i=0;i<40;i++)
	{
		if((pTileData->m_nGroup[i]==group)&&(pTileData->m_nOwned[i]==owner))
		{
		nPropertiesInGroup++;	//number of sites available to place properties on
		siteLocations[count] = i;
		count++;
		}
	}
	
////If residential and group is complete, house/hotel purchase possible?
//	if((group<9)&&(nPropertiesInGroup==maxPropertiesInGroup))
//	{	
//		allPropertiesInGroup = 1;
//		cout<<"This is a residential property group and you own the set."<<endl;
//		
//		//add flag to say this person owns all of group 'blue' etc. to profile
//		pAllPlayerClass[owner].m_naPropertySet[group] = group;
//		cout<<"Do you wish to purchase property?"<<endl;


		//}		
		
	return 0;
	
}