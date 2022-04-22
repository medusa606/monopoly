#include "stdafx.h"
#include <math.h>
#include <iostream>
#include "TileData.h"
#include "playerClass.h"
#include "chanceCards.h"
using namespace std;
char		GBP = 156;

void TakeChanceCard(int tile, int i, PlayerClass *pAllPlayerClass, ChanceCards *pChanceCards, TileData *pTileData)
{


	//set limits between 0 and 15 for random number generation
		double a=-0.5, b=15.5;										//might not like negative here?
		double randDouble;
		int card_index;


	//loop through random cards until a valid one is found
		bool valid_choice = 0;
		while (valid_choice==0)

		{
			//generate the random number and convert to an integer
				randDouble = (b-a) * (rand()/double(RAND_MAX)) + a;
				card_index = floor(randDouble+0.5);
				cout<<"randDouble is "<<randDouble<<" card_index is "<<card_index<<endl;
		
			//check if the random number is valid in the chance stack
				if(pChanceCards->m_nChanceValid[card_index] == 1)
					valid_choice = 1;
		}

	//read the name
		cout<<pAllPlayerClass[i].m_strPlayerName<<" has taken the chance card:\n";
		cout<<pChanceCards->m_sChanceName[card_index]<<endl;

	//if balance change needed
		if(pChanceCards->m_nChanceBalance[card_index]>0)
		{
			pAllPlayerClass[i].changeBalance(pChanceCards->m_nChanceBalance[card_index]);
			cout<<"Your new balance is "<<GBP<<pAllPlayerClass[i].m_nCash<<endl;
		}
		
	//if tile movement needed
		if(pChanceCards->m_nChanceMove[card_index]>0)
		{
		
			int oldPosition, newPosition;
			oldPosition = pAllPlayerClass[i].m_nOldPosition;
			newPosition = pChanceCards->m_nChanceNewLocation[card_index];
			pAllPlayerClass[i].m_nNewPosition = (newPosition);					//move the player

			//collect £200 if you pass GO
			if(newPosition < oldPosition)	//ie you go around the board 
			{
				pAllPlayerClass[i].changeBalance(200);
				cout<<pAllPlayerClass[i].m_strPlayerName<<" has passed GO, balance is \t"<<GBP<<
					pAllPlayerClass[i].m_nCash<<endl;
			}		
		}
		

		int nHouses=0, nHotels=0;
		
		switch(card_index)
		{
		case 0:			//	"Advance to Mayfair	"	
			break;

		case 1:			//	"Advance to Go	"	
			break;

		case 2:			//	"You are Assessed for Street Repairs GBP40 per House GBP115 per Hotel"	
			for(int j=0;j<40;j++)
				if (pTileData->m_nOwned[j]=i+1)					//if player owns that tile
				{
					if(pTileData->m_nNoHouses[j]>4)				//count hotels
						nHotels++;
					if(pTileData->m_nNoHouses[j]<5)				//count houses
						nHouses+=pTileData->m_nNoHouses[j];
				}
			cout<<"You have "<<nHouses<<" houses and "<<nHotels<<" hotels"<<endl;
			cout<<"You must pay "<<GBP<<((nHouses*40)+(nHotels*115))<<endl;
			pAllPlayerClass[i].changeBalance(nHouses*40+nHotels*115);
			break;

		case 3:			//	"Go to Jail. Move Directly to Jail. Do not pass Go Do not Collect GBP200"	
			pAllPlayerClass[i].m_nInJail = 1;
			break;

		case 4:			//	"Bank pays you Dividend of GBP50"	
			break;

		case 5:			//	"Go back 3 Spaces"	
			pAllPlayerClass[i].boardMove(-3);
			break;

		case 6:			//	"Pay School Fees of GBP150"	
			break;

		case 7:			//	"Make General Repairs on all of Your Houses: Houses GBP25, Hotel GBP100"
			for(int j=0;j<40;j++)
				if (pTileData->m_nOwned[j]=i+1)					//if player owns that tile
				{
					if(pTileData->m_nNoHouses[j]>4)				//count hotels
						nHotels++;
					if(pTileData->m_nNoHouses[j]<5)				//count houses
						nHouses+=pTileData->m_nNoHouses[j];
				}
			cout<<"You have "<<nHouses<<" houses and "<<nHotels<<" hotels"<<endl;
			cout<<"You must pay "<<GBP<<((nHouses*25)+(nHotels*100))<<endl;
			pAllPlayerClass[i].changeBalance(nHouses*25+nHotels*100);
			break;

		case 8:			//	"Speeding Fine GBP15"	
			break;

		case 9:			//	"You have won a Crossword Competition Collect GBP100"
			break;

		case 10:		//	"Your Building and Loan Matures Collect GBP150"	
			break;

		case 11:		//	"Get out of Jail Free"	
			pAllPlayerClass[i].m_nOutJailCard++;
			break;

		case 12:		//	"Avance to Trafalgar Square If you Pass Go Collect GBP200"	
			break;

		case 13:		//	"Take a Trip to Marylebone Station and if you Pass Go Collect GBP200"	
			break;

		case 14:		//	"Advance to Pall Mall If you Pass Go Collect GBP200"	
			break;

		case 15:		//	"Drunk in Charge of a vehicle. Fine of (only) GBP20!"	
			break;
		}
}

