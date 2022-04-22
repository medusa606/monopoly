#include "stdafx.h"
#include <iostream>
#include "TileData.h"
#include "playerClass.h"
using namespace std;


int RentCharge(int tile, int owner, int move, TileData *pTileData){
	
	//what is the group colour?
	int group = -1;
	int maxPropertiesInGroup = -1;
	int nPropertiesInGroup = 0;
	bool allPropertiesInGroup = 0;
	int rent = 0;
	owner += 1;
	group = pTileData->m_nGroup[tile];
	cout<<"The property group is "<<group<<endl;
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
			cout<<"RENTCHARGE: The property group is unknown"<<endl;
			break;
	}
		
	for(int i=0;i<40;i++)
	{
		if((pTileData->m_nGroup[i]==group)&&(pTileData->m_nOwned[i]==owner))
		{
		nPropertiesInGroup++;
		//cout<<" i="<<i<<endl;
		//cout<<" pTileData.m_nGroup[i]="<<pTileData.m_nGroup[i]<<endl;
		//cout<<" group="<<group<<endl;
		//cout<<" pTileData.m_nOwned[i]="<<pTileData.m_nOwned[i]<<endl;
		//cout<<" owner="<<owner<<endl;
		//cout<<"Number of properties in group is "<<nPropertiesInGroup<<endl;
		}
	}
	cout<<"This landlord owns "<<nPropertiesInGroup<<"/"<<maxPropertiesInGroup<<" lot(s) in this group"<<endl;

	//does the landlord own the entire group?
		if(nPropertiesInGroup==maxPropertiesInGroup){
			allPropertiesInGroup = 1;
			cout<<"The landlord owns the group set"<<endl;}

	//is it residential/stations/utilities?
		if(group < 9)
		{
			cout<<"This is a residential property group"<<endl;
			if(allPropertiesInGroup!=1)
				rent = pTileData->m_nTileRentSite[tile];
			if((allPropertiesInGroup==1)&&(pTileData->m_nNoHouses[tile]==0))
				rent = 2 * pTileData->m_nTileRentSite[tile];
			if((allPropertiesInGroup==1)&&(pTileData->m_nNoHouses[tile]>0))
			{
				int houses = 0;
				houses = pTileData->m_nNoHouses[tile];
				switch(houses)
				{
					case 1:
						rent = pTileData->m_nTileRent1h[tile];
						break;
					case 2:
						rent = pTileData->m_nTileRent2h[tile];
						break;
					case 3:
						rent = pTileData->m_nTileRent3h[tile];
						break;
					case 4:
						rent = pTileData->m_nTileRent4h[tile];
						break;
					case 5:
						rent = pTileData->m_nTileRent5h[tile];
						break;
				}
			}
		}
		else if(group==9)
		{
			cout<<"This is a rail group"<<endl;
			switch(nPropertiesInGroup)
			{
				case 1:
					rent = 25;
					break;
				case 2:
					rent = 50;
					break;
				case 3:
					rent = 100;
					break;
				case 4:
					rent = 200;
					break;
			}
		}
		else if(group==10)
		{
			cout<<"This is a utility group"<<endl;
			if(nPropertiesInGroup == 1)
				rent = move * 4;
			if(nPropertiesInGroup == 2)
				rent = move * 10;
		}
		
		
	return rent;
	
}