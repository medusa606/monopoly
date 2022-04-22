#include "stdafx.h"
#include <iostream>
#include "TileData.h"
#include "playerClass.h"
#include <string>
using namespace std;

void TileValidation(int owner, PlayerClass *pAllPlayerClass, TileData *pTileData)
{
	//what are the site colours for group iD
	string groupColour[] = {"Brown","Purple","Blue","Pink","Orange","Red","Yellow","Green"};

	//how many sites per group, i.e. 2 for brown
		int maxSitesPerGroup[8] = {2,2,3,3,3,3,3,3};

	//array to store complete groups, 1-8 residential
		int groupCount[10] = {0}; 

	//loop through all tiles and count sites per group
		for(int i=0;i<40;i++)
		{
			if(pTileData->m_nOwned[i] == owner+1)
			{
				groupCount[pTileData->m_nGroup[i]-1]++;				
			}
		}

	//flag if all sites per group are owned by player
		for(int i=0;i<8;i++)
		{
			if(groupCount[i] == maxSitesPerGroup[i])
			{
				pAllPlayerClass[owner].m_naPropertySet[i] = 1;	//index 0 is property group 1, i.e. Brown
				cout<<"You own the "<<groupColour[i]<<" group"<<endl;									
			}
		}
}