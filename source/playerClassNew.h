#ifndef PLAYERCLASS_H_INCLUDED
#define PLAYERCLASS_H_INCLUDED

#pragma once

#ifndef playerClass_h
#define playerClass_h

#include <iostream>
#include "diceheader.h"
#include <string>
using namespace std;

//define player types
    enum m_playerType{hat,boot,car,dog,iron,wheelbarrow,thimble,ship};


//define player class
    class PlayerClass
    {
        public:
        string		m_strPlayerName;
        DiceParams	m_sDiceParams;
//        enum		m_playerType;
        long		m_nCash;
        int			m_nOldPosition;
        int			m_nNewPosition;
        bool		m_nInJail;
        int			m_nTurnsInJail;
        int			m_nOutJailCard;
        int			m_naPropertySet[10];	//true if entire group is owned
        int			z;


    //default constructor for player class, this will set values upon instantiating a playerclass object
        PlayerClass()
        {
            m_nCash						= 1500;
            DiceParams m_sDiceParams	= {0,0,0,0,0,{0,0,0,0,0,0}};
            m_nOldPosition				= 0;
            m_nNewPosition				= 0;
            m_nInJail					= 0;
            m_nTurnsInJail				= 0;
            m_nOutJailCard				= 0;


            for(int z=0;z<10;z++)
                m_naPropertySet[z]=0;

        }

    //use this function for moving position
        void boardMove(int totaldice)
        {
            m_nOldPosition = m_nNewPosition;
            m_nNewPosition += totaldice;

            //collect �200 if you pass GO
            if(m_nNewPosition > 39)
            {
                //m_nNewPosition = m_nNewPosition % 39;
                m_nNewPosition -= 39;
                m_nCash		+= 200;
                char		GBP = 156;
                cout<<m_strPlayerName<<" has passed GO, balance is \t"<<GBP<<m_nCash<<endl;
            }
        }


    //use this function for changing balance
        void changeBalance(int change)
        {
            char		GBP = 156;
            int balance;
            balance = m_nCash + change;
            if((balance)<0)
            {
                cout<<"You are bankrupt! This transaction cannot continue."<<endl;
                //look at mortgaging properties here...
            }
            else
            {
                m_nCash += change;
                cout<<m_strPlayerName<<" now has a balance of \t\t"<<GBP<<m_nCash<<endl;
            }
        }

    };

            //edit player class stored cards
            //edit player class properties/assets

#endif

#endif // PLAYERCLASS_H_INCLUDED