//#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <cstdio>			//for getchar()
#include <filesystem>       //PWD

#include "diceheader.h"		//header file for dice parameters and structures
#include "playerClassNew.h"
#include "tileData.h"		//header file for board information
#include "chanceCards.h"	//header for chance cards

using namespace std;


    //declare the function prototypes
        int DiceRoll();
        int RentCharge(int,int,int,TileData*);
        void TakeChanceCard(int tile, int i, PlayerClass *pAllPlayerClass, ChanceCards *pChanceCards, TileData *pTileData);
        void PrintMenu(int);
        void AddHouse(int owner, PlayerClass *pAllPlayerClass, TileData *pTileData);
        void TileValidation(int owner, PlayerClass *pAllPlayerClass, TileData *pTileData);

    //declare test function prototype
        void RandomDiceTest(DiceParams x);

    //initialise a test dice
        DiceParams s_testDice={0,0,0,0,0,{0,0,0,0,0,0}};

int main()
{


//    char working_dir[256];
//    getcwd(working_dir, 256);
//    std::cout << "Current working directory: " << working_dir << std::endl;

        //create seed value for random number generation base on clock time
        //srand(unsigned(time(0)));
        srand(0);	//create know seed for testing

    //if required perform statistical test on random dice function
        bool diceTest = 0;
        if(diceTest)
        RandomDiceTest(s_testDice);


/******************************************************************************************
*
*								define the players of the game
*
******************************************************************************************/

    //enter the number of players
        const int nMaxPlayers = 8;
        int success=0;
        int nPlayers;
        char GBP = 156;	//� sign
        while(success == 0){
            cout<<"Enter the number of players (2-8): ";
            cin>>nPlayers;
            if(nPlayers>=2 || nPlayers<=nMaxPlayers){
                cout<<"You have selected "<<nPlayers<<" players"<<endl;
                success=1;}
            if(nPlayers>nMaxPlayers)
                cout<<"You have selected more than 8, please select again"<<endl;
            if(nPlayers<2)
                cout<<"You have selected less than 2, please select again"<<endl;}

    //dynamically allocate a pointer to an array of objects
        PlayerClass *pAllPlayerClass = new PlayerClass[nPlayers];

    //create a pointer to the board information class and create instance
        TileData *pTileData = new TileData;

    //create a pointer to the chance cards information and create instance
        ChanceCards *pChanceCards = new ChanceCards;

    //enter each players name
        for (int i=0; i<nPlayers; ++i){
            cout<<"\nEnter player "<<i+1<<" name: "<<endl;
            string strPlayerName;
            cin>>strPlayerName;
            cout<<"Hello "<<strPlayerName<<" welcome to the game"<<endl;
            pAllPlayerClass[i].m_strPlayerName = strPlayerName;
            cout<<pAllPlayerClass[i].m_strPlayerName<<" has a cash balance of "<<GBP<<pAllPlayerClass[i].m_nCash<<endl;
            }

    //finished defining players
        cout << "\nInitialising players complete" << endl;

/*****************************************************************************************
*
*										start the game
*
******************************************************************************************/

    //start a conditional loop
        int endGame=0;
        int round=1;
        while(endGame!=1)
        {
        //loop through each of the players
            for(int i=0;i<nPlayers;++i)
            {
                int firstRoll, secondRoll, move;
                int doubleRoll=0;

    /*****************************************************************************************
    *
    *										player in jail
    *
    ******************************************************************************************/
                if (pAllPlayerClass[i].m_nInJail == 1)
                {
                    pAllPlayerClass[i].m_nTurnsInJail ++;		//need to change this so number restes when out of jail

                    if((pAllPlayerClass[i].m_nTurnsInJail == 1)|(pAllPlayerClass[i].m_nTurnsInJail == 2))
                    {
                        if(pAllPlayerClass[i].m_nTurnsInJail == 1)
                            cout<<pAllPlayerClass[i].m_strPlayerName<<", this is your fist go in jail."<<endl;
                        if(pAllPlayerClass[i].m_nTurnsInJail == 2)
                            cout<<pAllPlayerClass[i].m_strPlayerName<<", this is your second go in jail."<<endl;

                        cout<<"Do you wish to pay "<<GBP<<"50 to forgo your remaining term of incarceration or "
                            <<"do you wish to attempt to roll a double?"<<endl;
                        cout<<"\nAnswer 1 to pay "<<GBP<<"50?:"<<endl;
                        cout<<"\nAnswer 2 to try and roll a double?:"<<endl;

                    //if player has card can use it here:
                        if(pAllPlayerClass[i].m_nOutJailCard > 0)
                        {
                            cout<<"\nAnswer 3 Use your get out of jail card?:"<<endl;
                        }

                        int answer = -1;
                        cin>> answer;

                        if(answer==1)
                        {
                            pAllPlayerClass[i].changeBalance(-50);
                            pAllPlayerClass[i].m_nInJail = 0;
                            pAllPlayerClass[i].m_nNewPosition = 10;
                            pAllPlayerClass[i].m_nTurnsInJail = 0;
                            cout<<"You are out of jail and continue from Just Visiting"<<endl;
                            //roll dice
                            //move as normal
                        }

                        if(answer==2)
                        {
                            firstRoll = DiceRoll();
                            secondRoll = DiceRoll();
                            cout<<"You rolled a "<<firstRoll<<" and a "<<secondRoll<<endl;
                            if(firstRoll==secondRoll)
                            {
                            pAllPlayerClass[i].m_nInJail = 0;
                            pAllPlayerClass[i].m_nNewPosition = 10;
                            pAllPlayerClass[i].m_nTurnsInJail = 0;
                            cout<<"You rolled a double and are out of jail, continue from Just Visiting"<<endl;
                            }
                            else
                                cout<<"You did not roll a double, back to the slammer!"<<endl;
                        }

                        if(answer==3)
                        {
                            pAllPlayerClass[i].m_nOutJailCard--;
                            pAllPlayerClass[i].m_nInJail = 0;
                            pAllPlayerClass[i].m_nNewPosition = 10;
                            pAllPlayerClass[i].m_nTurnsInJail = 0;
                            cout<<"You will be levied "<<GBP<<"50"<<endl;
                            pAllPlayerClass[i].changeBalance(-50);
                            cout<<"You are out of jail and continue from Just Visiting"<<endl;
                            break;							//need to end turn here **********************
                        }
                    }	//end of 1 or 2 turns in jail


                    if(pAllPlayerClass[i].m_nTurnsInJail == 3)
                    {
                        cout<<pAllPlayerClass[i].m_strPlayerName<<" ,this is your third and last go in jail. Hurray!"<<endl;
                        cout<<"You may attempt to roll a double to avoid the jail tax"<<endl;

                        firstRoll = DiceRoll();
                        secondRoll = DiceRoll();
                        cout<<"You rolled a "<<firstRoll<<" and a "<<secondRoll<<endl;
                        if(firstRoll==secondRoll)
                        {
                        pAllPlayerClass[i].m_nInJail = 0;
                        pAllPlayerClass[i].m_nNewPosition = 10;
                        cout<<"You rolled a double and are out of jail, continue from Just Visiting"<<endl;
                        }
                        else
                        {
                            cout<<"You will be levied "<<GBP<<"50 and then you are free to go."<<endl;
                            pAllPlayerClass[i].changeBalance(-50);
                            pAllPlayerClass[i].m_nTurnsInJail = 0;
                            pAllPlayerClass[i].m_nInJail = 0;
                            pAllPlayerClass[i].m_nNewPosition = 10;
                        }
                    }	//end of 3 turns in jail
                }	//end of being in jail

    /*****************************************************************************************
    *
    *									player not in jail
    *
    ******************************************************************************************/
                else
                {
                    restartTurn:	//this is where the GoTo statement will jump to if player has anothe go
                    firstRoll = DiceRoll();
                    secondRoll = DiceRoll();
                    if(firstRoll==secondRoll)
                    {
                        doubleRoll++;
                        if(doubleRoll==3)
                        {
                            cout<<pAllPlayerClass[i].m_strPlayerName<<" rolled a third double, oh no... to jail you go!"<<endl;
                            pAllPlayerClass[i].m_nInJail = 1;
                        }
                    }
                    if(pAllPlayerClass[i].m_nInJail!=1)
                    {
                        move = firstRoll + secondRoll;
                        pAllPlayerClass[i].boardMove(move);
                        cout<<pAllPlayerClass[i].m_strPlayerName<<" rolled a "<<firstRoll<<" and a "<<secondRoll<<" totalling "<<move<<endl;
                            cout<<"and is now at "<<pTileData->m_sTileName[pAllPlayerClass[i].m_nNewPosition]<<endl;

                /*****************************************************************************************
                *
                *										tile interaction
                *
                ******************************************************************************************/

                        int tile = pAllPlayerClass[i].m_nNewPosition;

                            if(pTileData->m_nPenalty[tile]>=1)
                            {
                                cout<<pAllPlayerClass[i].m_strPlayerName<<" has landed on "<<
                                    pTileData->m_sTileName[tile]<<endl;
                                cout<<"You have to pay a fine of\t "<<GBP<<pTileData->m_nPenalty[tile]<<endl;
                                pAllPlayerClass[i].changeBalance(-pTileData->m_nPenalty[tile]);
                                cout<<"Your balance is now "<<GBP<<pAllPlayerClass[i].m_nCash<<endl;
                            }
                            else if(pTileData->m_bChance[tile]==1)
                            {
                                cout<<pAllPlayerClass[i].m_strPlayerName<<" has landed on "<<
                                    pTileData->m_sTileName[tile]<<", please take a card."<<endl;

                            //enter Chance card subroutine
                            TakeChanceCard(tile,i,pAllPlayerClass,pChanceCards,pTileData);

                            }
                            else if(pTileData->m_bComChest[tile]==1)
                            {
                                cout<<pAllPlayerClass[i].m_strPlayerName<<" has landed on "<<
                                    pTileData->m_sTileName[tile]<<", please take a card."<<endl;

                                //enter Community Chest card subroutine
                                //CommunityChestCard(tile,i,pAllPlayerClass,pChanceCards);

                            }
                            else if(tile==30)
                            {
                                cout<<pAllPlayerClass[i].m_strPlayerName<<" has landed on "<<
                                    pTileData->m_sTileName[tile]<<endl;
                                cout<<"Go straight to jail, do not pass go or collect "<<GBP<<"200."<<endl;
                                pAllPlayerClass[i].m_nInJail = 1;
                            }

                /*****************************************************************************************
                *
                *										purchase site
                *
                ******************************************************************************************/

                            if(pTileData->m_nOwned[tile]==0 && pAllPlayerClass[i].m_nInJail!=1)
                            {
                                cout<<"This property is for sale,"<<endl;
                                cout<<"The cost is \t\t\t"<<GBP<<pTileData->m_nTileCost[tile]<<endl;
                                cout<<"Your cash balance is \t\t"<<GBP<<pAllPlayerClass[i].m_nCash<<endl;
                                cout<<"Do you wish to buy it? 1=Y/0=N: "<<endl;
                                int answer=-1;
                                cin>>answer;
                                if(answer = 0)
                                    cout<<"You have chosen not to buy this property."<<endl;
                                if(answer = 1)
                                {
                                    cout<<"Congratulations, you now own this property. "<<endl;
                                    pAllPlayerClass[i].changeBalance(-pTileData->m_nTileCost[tile]);		//pay for it
                                    cout<<"Your balance is now \t\t"<<GBP<<pAllPlayerClass[i].m_nCash<<endl;
                                    pTileData->m_nOwned[tile] = (i+1);										//mark it as owned on the list

                                    cout<<"Press ENTER to continue: "<<endl;
                                    char EnterCharacter = getchar();
                                    if (EnterCharacter = '\n')
                                        continue;															//continue will not exit for loop

                                }
                            }

                            if((pTileData->m_nOwned[tile]>0)&&(pTileData->m_nOwned[tile]!=(i+1)))			//is tile owned by someone other than you?
                            {
                                int owner = pTileData->m_nOwned[tile] - 1;									//return the player ID from the property list
                                cout<<"This property is owned by "<<
                                    pAllPlayerClass[owner].m_strPlayerName<<endl;
                            //calculate rent
                                int rent = 0;
                                rent = RentCharge(tile,owner,move,pTileData);
                                cout<<"You owe a rent charge of\t "<<GBP<<rent<<endl;
                                pAllPlayerClass[i].changeBalance(-rent);									//debit the player
                                pAllPlayerClass[owner].changeBalance(rent);									//credit the owner

                            }



                /*****************************************************************************************
                *
                *							option to buy houses on your property
                *
                ******************************************************************************************/

                    //routine to check what property sets you own
                        TileValidation(i,pAllPlayerClass,pTileData);
                        int buyHouseFlag=0;
                        for(int z=0;z<10;z++)
                        {
                            if(pAllPlayerClass[i].m_naPropertySet[z]>0)			//if player owns a set
                                buyHouseFlag++;

                        if(buyHouseFlag>0)
                        {
                            cout<<"You can buy houses for your site"<<endl;
                            AddHouse(i, pAllPlayerClass, pTileData);
                        }


                        if(firstRoll==secondRoll)
                        {
                            cout<<pAllPlayerClass[i].m_strPlayerName<<" rolled a double ("<<doubleRoll<<"), have another turn!"<<endl;
                            goto restartTurn;
                        }


                    } //if player not in jail

                    if(pAllPlayerClass[i].m_nCash >= 10000)
                    {
                        cout<<pAllPlayerClass[i].m_strPlayerName<<" has won with a cash balance of "<<pAllPlayerClass[i].m_nCash<<endl;
                        endGame=1;
                    }

                }//not in jail


                cout<<"Press ENTER to continue: "<<endl;
                char EnterCharacter = getchar();
                if (EnterCharacter = '\n')
                {
                cout<<"\n\n************ Round "<<round<<" over ************\n\n"<<endl;
                cout<<endl;
                round++;
                }

            }//end of player loop
        }//end while endGame=0


    //delete the array of pointers to free the memory
        delete[] pAllPlayerClass;
        delete pTileData;


    int z;
    cin >> z;
    return 0;


}
}
