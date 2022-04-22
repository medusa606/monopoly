#include "stdafx.h"
#include <iostream>
#include "TileData.h"
#include "playerClass.h"
#include "math.h"
using namespace std;

void PrintMenu(int x);	//function prototype

//******************************************
//
//	Add a house or hotel to the property
//
//******************************************

void AddHouse(int owner, PlayerClass *pAllPlayerClass, TileData *pTileData)
{
	char GBP = 156;	//£ sign

	//determine number of groups valid for purchase & identify group code
	int nGroupsAvailable = 0;
	int nSetRegister[9] = {0};
	int siteLocations[4] = {0};
	for(int i=0;i<9;i++)
	{
		if(pAllPlayerClass[owner].m_naPropertySet[i] == 1)
		{	
			nSetRegister[nGroupsAvailable] = i+1; //pAllPlayerClass[owner].m_naPropertySet[i];		//fills register with group colour
			nGroupsAvailable++;
		}
	}

	//open a menu for chosing which set, keep open until all purchasing complete
	int nPurchasingComplete = 0;
	do
	{
		cout<<"Groups available for purchase are:\n"<<endl;
		//loop through avail groups and print
		for(int i=0;i<nGroupsAvailable;i++)
		{
			PrintMenu(nSetRegister[i]);
		}
		cout<<"\n\t11: EXIT"<<endl;
		cout<<"\n\nPlease make a selection:"<<endl;
		

		//read in choice or return re-select
		int choice = 0;
		cin>>choice;

		//close down if all complete
		if(choice == 11)
		{	nPurchasingComplete = 1;
		break;}
		
	
		//loop through all sites and validate against group, then count houses
			int count=0, nPropertiesInGroup=0;
			for(int i=0;i<40;i++)
			{
				if(pTileData->m_nGroup[i]==choice)
				{
				nPropertiesInGroup++;	//number of sites available to place properties on
				siteLocations[count] = i;
				count++;
				//cout<<"count in site validation loop is: "<<count<<endl;
				}
			}


		//how many houses available for the group (max 5 per site)
			int maxHousesForPurchase = 0;
			for(int k=0;k<count;k++)
			{
				cout<<"Property: "<<pTileData->m_sTileName[siteLocations[k]]<<endl;
				cout<<"\tNumber of houses: "<<pTileData->m_nNoHouses[siteLocations[k]]<<endl;
				int spareSites = 5-pTileData->m_nNoHouses[siteLocations[k]];
				cout<<"\tMax houses available to purchase: "<<spareSites<<endl;
				maxHousesForPurchase += spareSites;
			}
			cout<<endl;
			cout<<"\tThe maximum properties you can buy is: "<<maxHousesForPurchase<<endl;
			int houseCost;
			houseCost = pTileData->m_nHouseCost[siteLocations[0]];
			cout<<"\tThe cost of one house is: "<<GBP<<houseCost;



		//ask player how many houses they would like to purchase
			int nHousesSelected = 0;
			int total=-1, balance=-1, maxHousesPlayerCanBuy=-1;
			balance = pAllPlayerClass[owner].m_nCash;
			cout<<"\nYour balance is "<<GBP<<balance<<endl;
			maxHousesPlayerCanBuy = floor(balance/houseCost);
			cout<<"\nYou can afford up to "<<maxHousesPlayerCanBuy<<" houses";
			cout<<"\nHow many do you want to buy?";
			do
			{
				cout<<"\nPlease enter "<<maxHousesForPurchase<<" or less: "<<endl;
				nHousesSelected = -1;
				cin>>nHousesSelected;
				//validate transaction				
				total = nHousesSelected * houseCost;
				if(total>=balance)
					cout<<"You do not have enough money, please select again"<<endl;
				if(nHousesSelected>maxHousesForPurchase)
					cout<<"Not enough sites available, please select again"<<endl;
				cout<<"total="<<total<<", balance="<<balance;
				cout<<"nHousesSelected="<<nHousesSelected<<", maxHousesForPurchase="<<maxHousesForPurchase;

			}while (nHousesSelected>maxHousesForPurchase && total<=balance);		
			
	
			//confirm transaction
			cout<<"You wish to buy "<<nHousesSelected<<" houses for "<<GBP<<total<<". Is that correct?"<<endl;
			cout<<"Press 1 to continue or 0 to exit: "<<endl;
			int EnterCharacter=-1;
			cin>>EnterCharacter;

			if (EnterCharacter = 1)
				{
					//pay for houses
					pAllPlayerClass[owner].changeBalance(-nHousesSelected*houseCost);

					//distribute the houses evenly then sort any remainders
					int propertyModulo = -1;
					propertyModulo = nHousesSelected % nPropertiesInGroup;
					cout<<"propertyModulo="<<propertyModulo<<endl;
					int m=0;
					for(int n=0;n<(nHousesSelected-propertyModulo);n++)
					{						
						pTileData->m_nNoHouses[siteLocations[m]]++; //add house to each site
						m++;										//go to next site
						if(m>(nPropertiesInGroup-1))				//return to first site after last in group
							m=0;
					}
		
					if(propertyModulo==0)
					{
						cout<<"The number of houses factors evenly into the number of sites"<<endl;
					}

					if(propertyModulo==1)
					{
						//check if there is a site with less houses than the rest
						cout<<"You have an odd house to place.\n"<<
							"Where would you like to site it"<<endl;

						//print each site name
						for(int k=0;k<nPropertiesInGroup;k++)
						{
							cout<<"Press "<<k+1<<" for :"<<pTileData->m_sTileName[siteLocations[k]]<<endl;
						}
						int moduloSite;
						cout<<"Please make your selection:"<<endl;
						cin>>moduloSite;
						pTileData->m_nNoHouses[siteLocations[moduloSite-1]]++;

					}

					if(propertyModulo==2)
					{
		
					}
					

					//report number of houses on each property
					cout<<"You have :"<<endl;
					for(int m=0;m<(count);m++)
					{
					cout<<pTileData->m_nNoHouses[siteLocations[m]]<<" houses on "<<pTileData->m_sTileName[siteLocations[m]]<<endl;
					}

					//update tile data
					cout<<"You have completed the transaction"<<endl;


				}//end of Press ENTER to continue or X to exit:
				else if (EnterCharacter = 0)
					cout<<"You have chosen to cancel this transaction"<<endl;
						


					
				cout<<"Do you wish to make another purchase? YES=1 or NO=0:"<<endl;
					int answer=-1;
					cin>>answer;
					if (answer = 1)
						nPurchasingComplete = 0;
					if (answer = 0)
						nPurchasingComplete = 1;
									
	}while (nPurchasingComplete == 0); //purchasing complete

}	//end of AddHouse