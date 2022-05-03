#ifndef chancecards_h
#define chancecards_h

#include "stdafx.h"
#include <iostream>
#include "tileData.h"
#include "playerClass.h"
using namespace std;


//define a tile class to store information about the board
	class ChanceCards{

	public:
		string	m_sChanceName[16];
		int		m_nChanceAction[16];
		int		m_nChanceBalance[16];
		int		m_nChanceMove[16];
		int		m_nChanceSpecial[16];
		int		m_nChanceValid[16];
		int		m_nChanceNewLocation[16];


	//use a default constructor to fill in the data
		ChanceCards()
		{

		//card names
			m_sChanceName[	0	]	=	"Advance to Mayfair	"	;
			m_sChanceName[	1	]	=	"Advance to Go	"	;
			m_sChanceName[	2	]	=	"You are Assessed for�Street Repairs�GBP40 per House GBP115 per Hotel	"	;
			m_sChanceName[	3	]	=	"Go to Jail. Move Directly to Jail. Do not pass Go Do not Collect GBP200	"	;
			m_sChanceName[	4	]	=	"Bank pays you Dividend of GBP50	"	;
			m_sChanceName[	5	]	=	"Go back 3 Spaces	"	;
			m_sChanceName[	6	]	=	"Pay School Fees of GBP150	"	;
			m_sChanceName[	7	]	=	"Make General Repairs on all of Your Houses: Houses GBP25, Hotel GBP100	"	;
			m_sChanceName[	8	]	=	"Speeding Fine GBP15	"	;
			m_sChanceName[	9	]	=	"You have won a Crossword Competition Collect GBP100	"	;
			m_sChanceName[	10	]	=	"Your Building and Loan Matures Collect GBP150	"	;
			m_sChanceName[	11	]	=	"Get out of Jail Free	"	;
			m_sChanceName[	12	]	=	"Avance to�Trafalgar Square�If you Pass Go Collect GBP200	"	;
			m_sChanceName[	13	]	=	"Take a Trip to Marylebone Station and if you Pass Go Collect GBP200	"	;
			m_sChanceName[	14	]	=	"Advance to Pall Mall If you Pass Go Collect GBP200	"	;
			m_sChanceName[	15	]	=	"Drunk in Charge of a vehicle. Fine of (only) GBP20!	"	;
			
		// change to balance
			m_nChanceBalance[	0	]	=	0	;
			m_nChanceBalance[	1	]	=	200	;
			m_nChanceBalance[	2	]	=	0	;
			m_nChanceBalance[	3	]	=	0	;
			m_nChanceBalance[	4	]	=	50	;
			m_nChanceBalance[	5	]	=	0	;
			m_nChanceBalance[	6	]	=	-150;
			m_nChanceBalance[	7	]	=	0	;
			m_nChanceBalance[	8	]	=	-15	;
			m_nChanceBalance[	9	]	=	100	;
			m_nChanceBalance[	10	]	=	150	;
			m_nChanceBalance[	11	]	=	0	;
			m_nChanceBalance[	12	]	=	0	;
			m_nChanceBalance[	13	]	=	0	;
			m_nChanceBalance[	14	]	=	0	;
			m_nChanceBalance[	15	]	=	-20	;

		//movement action
			m_nChanceMove[	0	]	=	1	;
			m_nChanceMove[	1	]	=	1	;
			m_nChanceMove[	2	]	=	0	;
			m_nChanceMove[	3	]	=	0	;
			m_nChanceMove[	4	]	=	0	;
			m_nChanceMove[	5	]	=	0	;	//treat as special movement
			m_nChanceMove[	6	]	=	0	;
			m_nChanceMove[	7	]	=	0	;
			m_nChanceMove[	8	]	=	0	;
			m_nChanceMove[	9	]	=	0	;
			m_nChanceMove[	10	]	=	0	;
			m_nChanceMove[	11	]	=	0	;
			m_nChanceMove[	12	]	=	1	;
			m_nChanceMove[	13	]	=	1	;
			m_nChanceMove[	14	]	=	1	;
			m_nChanceMove[	15	]	=	0	;

		//new tile location action
			m_nChanceNewLocation[	0	]	=	39	;
			m_nChanceNewLocation[	1	]	=	0	;
			m_nChanceNewLocation[	2	]	=	-1	;
			m_nChanceNewLocation[	3	]	=	-1	;
			m_nChanceNewLocation[	4	]	=	-1	;
			m_nChanceNewLocation[	5	]	=	-1	;	//special - go back 3 spaces
			m_nChanceNewLocation[	6	]	=	-1	;
			m_nChanceNewLocation[	7	]	=	-1	;
			m_nChanceNewLocation[	8	]	=	-1	;
			m_nChanceNewLocation[	9	]	=	-1	;
			m_nChanceNewLocation[	10	]	=	-1	;
			m_nChanceNewLocation[	11	]	=	-1	;
			m_nChanceNewLocation[	12	]	=	24	;
			m_nChanceNewLocation[	13	]	=	15	;
			m_nChanceNewLocation[	14	]	=	11	;
			m_nChanceNewLocation[	15	]	=	-1	;

		//special actions
			m_nChanceSpecial[	0	]	=	0	;
			m_nChanceSpecial[	1	]	=	0	;
			m_nChanceSpecial[	2	]	=	1	;
			m_nChanceSpecial[	3	]	=	1	;
			m_nChanceSpecial[	4	]	=	0	;
			m_nChanceSpecial[	5	]	=	0	;
			m_nChanceSpecial[	6	]	=	0	;
			m_nChanceSpecial[	7	]	=	1	;
			m_nChanceSpecial[	8	]	=	0	;
			m_nChanceSpecial[	9	]	=	0	;
			m_nChanceSpecial[	10	]	=	0	;
			m_nChanceSpecial[	11	]	=	1	;
			m_nChanceSpecial[	12	]	=	0	;
			m_nChanceSpecial[	13	]	=	0	;
			m_nChanceSpecial[	14	]	=	0	;
			m_nChanceSpecial[	15	]	=	0	;

		//set this to 1 for valid, i.e. not taken out of ciculation or held by a player
			m_nChanceValid[	0	]	=	1	;
			m_nChanceValid[	1	]	=	1	;
			m_nChanceValid[	2	]	=	1	;
			m_nChanceValid[	3	]	=	1	;
			m_nChanceValid[	4	]	=	1	;
			m_nChanceValid[	5	]	=	1	;
			m_nChanceValid[	6	]	=	1	;
			m_nChanceValid[	7	]	=	1	;
			m_nChanceValid[	8	]	=	1	;
			m_nChanceValid[	9	]	=	1	;
			m_nChanceValid[	10	]	=	1	;
			m_nChanceValid[	11	]	=	1	;
			m_nChanceValid[	12	]	=	1	;
			m_nChanceValid[	13	]	=	1	;
			m_nChanceValid[	14	]	=	1	;
			m_nChanceValid[	15	]	=	1	;

		}
	};

#endif