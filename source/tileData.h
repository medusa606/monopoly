#ifndef tileData_h
#define tileData_h

#include <string>	
#include <fstream>
using namespace std;

//define a tile class to store information about the board
	class TileData
	{

	public:
		string	m_sTileName[40];			//Name of each tile
		int		m_nTileCost[40];			//Cost of purchasable site
		int		m_nTileMort[40];			//Mortgage of purchasable site
		int		m_nTileRentSite[40];		//Rent of site only 
		int		m_nTileRent1h[40];			//Rent with 1 house
		int		m_nTileRent2h[40];			//Rent with 2 houses
		int		m_nTileRent3h[40];			//Rent with 3 houses
		int		m_nTileRent4h[40];			//Rent with 4 houses
		int		m_nTileRent5h[40];			//Rent with 1 hotel
		int		m_nHouseCost[40];			//cost of one house
		int		m_nOwned[40];				//is this tile owned
		int		m_nPenalty[40];				//fixed penalty tiles
		bool	m_bChance[40];				//valid chance tiles
		bool	m_bComChest[40];			//valid community chest tiles
		int		m_nGroup[40];				//group identifier
		int		m_nNoHouses[40];			//number of houses on this site


	//use a default constructor to fill in the data
		TileData()
		{

		

//Name of each tile
m_sTileName[	0	]	=	"GO"	;
m_sTileName[	1	]	=	"Old Kent Road"	;
m_sTileName[	2	]	=	"Community Chest"	;
m_sTileName[	3	]	=	"Whitechaple Road"	;
m_sTileName[	4	]	=	"Income Tax"	;
m_sTileName[	5	]	=	"Kings Cross Station"	;
m_sTileName[	6	]	=	"The Angel Islington"	;
m_sTileName[	7	]	=	"Chance"	;
m_sTileName[	8	]	=	"Euston Road"	;
m_sTileName[	9	]	=	"Pentonville Road"	;
m_sTileName[	10	]	=	"Just Visiting Jail"	;
m_sTileName[	11	]	=	"Pall Mall"	;
m_sTileName[	12	]	=	"Electric Company"	;
m_sTileName[	13	]	=	"Whitehall"	;
m_sTileName[	14	]	=	"Northumberland Avenue"	;
m_sTileName[	15	]	=	"Marlybone Station"	;
m_sTileName[	16	]	=	"Bow Street"	;
m_sTileName[	17	]	=	"Community Chest"	;
m_sTileName[	18	]	=	"Marlborough Street"	;
m_sTileName[	19	]	=	"Vine Street"	;
m_sTileName[	20	]	=	"Free Parking"	;
m_sTileName[	21	]	=	"Strand"	;
m_sTileName[	22	]	=	"Chance"	;
m_sTileName[	23	]	=	"Fleet Street"	;
m_sTileName[	24	]	=	"Trafalgar Square"	;
m_sTileName[	25	]	=	"Fenchurch Street Station"	;
m_sTileName[	26	]	=	"Leicester Square"	;
m_sTileName[	27	]	=	"Coventry Street"	;
m_sTileName[	28	]	=	"Water Works"	;
m_sTileName[	29	]	=	"Piccadilly"	;
m_sTileName[	30	]	=	"GO TO JAIL"	;
m_sTileName[	31	]	=	"Regent Street"	;
m_sTileName[	32	]	=	"Oxford Street"	;
m_sTileName[	33	]	=	"Community Chest"	;
m_sTileName[	34	]	=	"Bond Street"	;
m_sTileName[	35	]	=	"Liverpool Street Station"	;
m_sTileName[	36	]	=	"Chance"	;
m_sTileName[	37	]	=	"Park Lane"	;
m_sTileName[	38	]	=	"Super Tax"	;
m_sTileName[	39	]	=	"Mayfair"	;			

//Cost of purchasable property
m_nTileCost[	0	]	=	0	;
m_nTileCost[	1	]	=	60	;
m_nTileCost[	2	]	=	0	;
m_nTileCost[	3	]	=	60	;
m_nTileCost[	4	]	=	0	;
m_nTileCost[	5	]	=	200	;
m_nTileCost[	6	]	=	100	;
m_nTileCost[	7	]	=	0	;
m_nTileCost[	8	]	=	100	;
m_nTileCost[	9	]	=	120	;
m_nTileCost[	10	]	=	0	;
m_nTileCost[	11	]	=	140	;
m_nTileCost[	12	]	=	150	;
m_nTileCost[	13	]	=	140	;
m_nTileCost[	14	]	=	160	;
m_nTileCost[	15	]	=	200	;
m_nTileCost[	16	]	=	180	;
m_nTileCost[	17	]	=	0	;
m_nTileCost[	18	]	=	180	;
m_nTileCost[	19	]	=	200	;
m_nTileCost[	20	]	=	0	;
m_nTileCost[	21	]	=	220	;
m_nTileCost[	22	]	=	0	;
m_nTileCost[	23	]	=	220	;
m_nTileCost[	24	]	=	240	;
m_nTileCost[	25	]	=	200	;
m_nTileCost[	26	]	=	260	;
m_nTileCost[	27	]	=	260	;
m_nTileCost[	28	]	=	150	;
m_nTileCost[	29	]	=	280	;
m_nTileCost[	30	]	=	0	;
m_nTileCost[	31	]	=	300	;
m_nTileCost[	32	]	=	300	;
m_nTileCost[	33	]	=	0	;
m_nTileCost[	34	]	=	320	;
m_nTileCost[	35	]	=	200	;
m_nTileCost[	36	]	=	0	;
m_nTileCost[	37	]	=	350	;
m_nTileCost[	38	]	=	0	;
m_nTileCost[	39	]	=	400	;

//Mortgage of purchasable property
m_nTileMort[	0	]	=	0	;
m_nTileMort[	1	]	=	30	;
m_nTileMort[	2	]	=	0	;
m_nTileMort[	3	]	=	30	;
m_nTileMort[	4	]	=	0	;
m_nTileMort[	5	]	=	100	;
m_nTileMort[	6	]	=	50	;
m_nTileMort[	7	]	=	0	;
m_nTileMort[	8	]	=	50	;
m_nTileMort[	9	]	=	60	;
m_nTileMort[	10	]	=	0	;
m_nTileMort[	11	]	=	70	;
m_nTileMort[	12	]	=	75	;
m_nTileMort[	13	]	=	70	;
m_nTileMort[	14	]	=	80	;
m_nTileMort[	15	]	=	100	;
m_nTileMort[	16	]	=	90	;
m_nTileMort[	17	]	=	0	;
m_nTileMort[	18	]	=	90	;
m_nTileMort[	19	]	=	100	;
m_nTileMort[	20	]	=	0	;
m_nTileMort[	21	]	=	110	;
m_nTileMort[	22	]	=	0	;
m_nTileMort[	23	]	=	110	;
m_nTileMort[	24	]	=	120	;
m_nTileMort[	25	]	=	100	;
m_nTileMort[	26	]	=	130	;
m_nTileMort[	27	]	=	130	;
m_nTileMort[	28	]	=	75	;
m_nTileMort[	29	]	=	140	;
m_nTileMort[	30	]	=	0	;
m_nTileMort[	31	]	=	150	;
m_nTileMort[	32	]	=	150	;
m_nTileMort[	33	]	=	0	;
m_nTileMort[	34	]	=	160	;
m_nTileMort[	35	]	=	100	;
m_nTileMort[	36	]	=	0	;
m_nTileMort[	37	]	=	175	;
m_nTileMort[	38	]	=	0	;
m_nTileMort[	39	]	=	200	;

//Site only rent of purchasable property
m_nTileRentSite[	0	]	=	0	;
m_nTileRentSite[	1	]	=	2	;
m_nTileRentSite[	2	]	=	0	;
m_nTileRentSite[	3	]	=	4	;
m_nTileRentSite[	4	]	=	0	;
m_nTileRentSite[	5	]	=	0	;
m_nTileRentSite[	6	]	=	6	;
m_nTileRentSite[	7	]	=	0	;
m_nTileRentSite[	8	]	=	6	;
m_nTileRentSite[	9	]	=	8	;
m_nTileRentSite[	10	]	=	0	;
m_nTileRentSite[	11	]	=	10	;
m_nTileRentSite[	12	]	=	0	;
m_nTileRentSite[	13	]	=	10	;
m_nTileRentSite[	14	]	=	12	;
m_nTileRentSite[	15	]	=	0	;
m_nTileRentSite[	16	]	=	14	;
m_nTileRentSite[	17	]	=	0	;
m_nTileRentSite[	18	]	=	14	;
m_nTileRentSite[	19	]	=	16	;
m_nTileRentSite[	20	]	=	0	;
m_nTileRentSite[	21	]	=	18	;
m_nTileRentSite[	22	]	=	0	;
m_nTileRentSite[	23	]	=	18	;
m_nTileRentSite[	24	]	=	20	;
m_nTileRentSite[	25	]	=	0	;
m_nTileRentSite[	26	]	=	22	;
m_nTileRentSite[	27	]	=	22	;
m_nTileRentSite[	28	]	=	0	;
m_nTileRentSite[	29	]	=	24	;
m_nTileRentSite[	30	]	=	0	;
m_nTileRentSite[	31	]	=	26	;
m_nTileRentSite[	32	]	=	26	;
m_nTileRentSite[	33	]	=	0	;
m_nTileRentSite[	34	]	=	28	;
m_nTileRentSite[	35	]	=	0	;
m_nTileRentSite[	36	]	=	0	;
m_nTileRentSite[	37	]	=	35	;
m_nTileRentSite[	38	]	=	0	;
m_nTileRentSite[	39	]	=	50	;

//Rent with 1 house
m_nTileRent1h[	0	]	=	0	;
m_nTileRent1h[	1	]	=	10	;
m_nTileRent1h[	2	]	=	0	;
m_nTileRent1h[	3	]	=	20	;
m_nTileRent1h[	4	]	=	0	;
m_nTileRent1h[	5	]	=	0	;
m_nTileRent1h[	6	]	=	30	;
m_nTileRent1h[	7	]	=	0	;
m_nTileRent1h[	8	]	=	30	;
m_nTileRent1h[	9	]	=	40	;
m_nTileRent1h[	10	]	=	0	;
m_nTileRent1h[	11	]	=	50	;
m_nTileRent1h[	12	]	=	0	;
m_nTileRent1h[	13	]	=	50	;
m_nTileRent1h[	14	]	=	60	;
m_nTileRent1h[	15	]	=	0	;
m_nTileRent1h[	16	]	=	70	;
m_nTileRent1h[	17	]	=	0	;
m_nTileRent1h[	18	]	=	70	;
m_nTileRent1h[	19	]	=	80	;
m_nTileRent1h[	20	]	=	0	;
m_nTileRent1h[	21	]	=	90	;
m_nTileRent1h[	22	]	=	0	;
m_nTileRent1h[	23	]	=	90	;
m_nTileRent1h[	24	]	=	100	;
m_nTileRent1h[	25	]	=	0	;
m_nTileRent1h[	26	]	=	110	;
m_nTileRent1h[	27	]	=	110	;
m_nTileRent1h[	28	]	=	0	;
m_nTileRent1h[	29	]	=	120	;
m_nTileRent1h[	30	]	=	0	;
m_nTileRent1h[	31	]	=	130	;
m_nTileRent1h[	32	]	=	130	;
m_nTileRent1h[	33	]	=	0	;
m_nTileRent1h[	34	]	=	150	;
m_nTileRent1h[	35	]	=	0	;
m_nTileRent1h[	36	]	=	0	;
m_nTileRent1h[	37	]	=	175	;
m_nTileRent1h[	38	]	=	0	;
m_nTileRent1h[	39	]	=	200	;

//Rent with 2 houses
m_nTileRent2h[	0	]	=	0	;
m_nTileRent2h[	1	]	=	30	;
m_nTileRent2h[	2	]	=	0	;
m_nTileRent2h[	3	]	=	60	;
m_nTileRent2h[	4	]	=	0	;
m_nTileRent2h[	5	]	=	0	;
m_nTileRent2h[	6	]	=	90	;
m_nTileRent2h[	7	]	=	0	;
m_nTileRent2h[	8	]	=	90	;
m_nTileRent2h[	9	]	=	100	;
m_nTileRent2h[	10	]	=	0	;
m_nTileRent2h[	11	]	=	150	;
m_nTileRent2h[	12	]	=	0	;
m_nTileRent2h[	13	]	=	150	;
m_nTileRent2h[	14	]	=	180	;
m_nTileRent2h[	15	]	=	0	;
m_nTileRent2h[	16	]	=	200	;
m_nTileRent2h[	17	]	=	0	;
m_nTileRent2h[	18	]	=	200	;
m_nTileRent2h[	19	]	=	220	;
m_nTileRent2h[	20	]	=	0	;
m_nTileRent2h[	21	]	=	250	;
m_nTileRent2h[	22	]	=	0	;
m_nTileRent2h[	23	]	=	250	;
m_nTileRent2h[	24	]	=	300	;
m_nTileRent2h[	25	]	=	0	;
m_nTileRent2h[	26	]	=	330	;
m_nTileRent2h[	27	]	=	330	;
m_nTileRent2h[	28	]	=	0	;
m_nTileRent2h[	29	]	=	360	;
m_nTileRent2h[	30	]	=	0	;
m_nTileRent2h[	31	]	=	390	;
m_nTileRent2h[	32	]	=	390	;
m_nTileRent2h[	33	]	=	0	;
m_nTileRent2h[	34	]	=	450	;
m_nTileRent2h[	35	]	=	0	;
m_nTileRent2h[	36	]	=	0	;
m_nTileRent2h[	37	]	=	500	;
m_nTileRent2h[	38	]	=	0	;
m_nTileRent2h[	39	]	=	600	;

//Rent with 3 houses
m_nTileRent3h[	0	]	=	0	;
m_nTileRent3h[	1	]	=	90	;
m_nTileRent3h[	2	]	=	0	;
m_nTileRent3h[	3	]	=	180	;
m_nTileRent3h[	4	]	=	0	;
m_nTileRent3h[	5	]	=	0	;
m_nTileRent3h[	6	]	=	270	;
m_nTileRent3h[	7	]	=	0	;
m_nTileRent3h[	8	]	=	270	;
m_nTileRent3h[	9	]	=	300	;
m_nTileRent3h[	10	]	=	0	;
m_nTileRent3h[	11	]	=	450	;
m_nTileRent3h[	12	]	=	0	;
m_nTileRent3h[	13	]	=	450	;
m_nTileRent3h[	14	]	=	500	;
m_nTileRent3h[	15	]	=	0	;
m_nTileRent3h[	16	]	=	550	;
m_nTileRent3h[	17	]	=	0	;
m_nTileRent3h[	18	]	=	550	;
m_nTileRent3h[	19	]	=	600	;
m_nTileRent3h[	20	]	=	0	;
m_nTileRent3h[	21	]	=	700	;
m_nTileRent3h[	22	]	=	0	;
m_nTileRent3h[	23	]	=	700	;
m_nTileRent3h[	24	]	=	750	;
m_nTileRent3h[	25	]	=	0	;
m_nTileRent3h[	26	]	=	800	;
m_nTileRent3h[	27	]	=	800	;
m_nTileRent3h[	28	]	=	0	;
m_nTileRent3h[	29	]	=	850	;
m_nTileRent3h[	30	]	=	0	;
m_nTileRent3h[	31	]	=	900	;
m_nTileRent3h[	32	]	=	900	;
m_nTileRent3h[	33	]	=	0	;
m_nTileRent3h[	34	]	=	1000	;
m_nTileRent3h[	35	]	=	0	;
m_nTileRent3h[	36	]	=	0	;
m_nTileRent3h[	37	]	=	1100	;
m_nTileRent3h[	38	]	=	0	;
m_nTileRent3h[	39	]	=	1400	;

//Rent with 4 houses
m_nTileRent4h[	0	]	=	0	;
m_nTileRent4h[	1	]	=	160	;
m_nTileRent4h[	2	]	=	0	;
m_nTileRent4h[	3	]	=	320	;
m_nTileRent4h[	4	]	=	0	;
m_nTileRent4h[	5	]	=	0	;
m_nTileRent4h[	6	]	=	400	;
m_nTileRent4h[	7	]	=	0	;
m_nTileRent4h[	8	]	=	400	;
m_nTileRent4h[	9	]	=	450	;
m_nTileRent4h[	10	]	=	0	;
m_nTileRent4h[	11	]	=	625	;
m_nTileRent4h[	12	]	=	0	;
m_nTileRent4h[	13	]	=	625	;
m_nTileRent4h[	14	]	=	700	;
m_nTileRent4h[	15	]	=	0	;
m_nTileRent4h[	16	]	=	750	;
m_nTileRent4h[	17	]	=	0	;
m_nTileRent4h[	18	]	=	750	;
m_nTileRent4h[	19	]	=	800	;
m_nTileRent4h[	20	]	=	0	;
m_nTileRent4h[	21	]	=	875	;
m_nTileRent4h[	22	]	=	0	;
m_nTileRent4h[	23	]	=	875	;
m_nTileRent4h[	24	]	=	925	;
m_nTileRent4h[	25	]	=	0	;
m_nTileRent4h[	26	]	=	975	;
m_nTileRent4h[	27	]	=	975	;
m_nTileRent4h[	28	]	=	0	;
m_nTileRent4h[	29	]	=	1025	;
m_nTileRent4h[	30	]	=	0	;
m_nTileRent4h[	31	]	=	1100	;
m_nTileRent4h[	32	]	=	1100	;
m_nTileRent4h[	33	]	=	0	;
m_nTileRent4h[	34	]	=	1200	;
m_nTileRent4h[	35	]	=	0	;
m_nTileRent4h[	36	]	=	0	;
m_nTileRent4h[	37	]	=	1300	;
m_nTileRent4h[	38	]	=	0	;
m_nTileRent4h[	39	]	=	1700	;

//Rent with a hotel
m_nTileRent5h[	0	]	=	0	;
m_nTileRent5h[	1	]	=	250	;
m_nTileRent5h[	2	]	=	0	;
m_nTileRent5h[	3	]	=	450	;
m_nTileRent5h[	4	]	=	0	;
m_nTileRent5h[	5	]	=	0	;
m_nTileRent5h[	6	]	=	550	;
m_nTileRent5h[	7	]	=	0	;
m_nTileRent5h[	8	]	=	550	;
m_nTileRent5h[	9	]	=	600	;
m_nTileRent5h[	10	]	=	0	;
m_nTileRent5h[	11	]	=	750	;
m_nTileRent5h[	12	]	=	0	;
m_nTileRent5h[	13	]	=	750	;
m_nTileRent5h[	14	]	=	900	;
m_nTileRent5h[	15	]	=	0	;
m_nTileRent5h[	16	]	=	950	;
m_nTileRent5h[	17	]	=	0	;
m_nTileRent5h[	18	]	=	950	;
m_nTileRent5h[	19	]	=	1000	;
m_nTileRent5h[	20	]	=	0	;
m_nTileRent5h[	21	]	=	1050	;
m_nTileRent5h[	22	]	=	0	;
m_nTileRent5h[	23	]	=	1050	;
m_nTileRent5h[	24	]	=	1100	;
m_nTileRent5h[	25	]	=	0	;
m_nTileRent5h[	26	]	=	1150	;
m_nTileRent5h[	27	]	=	1150	;
m_nTileRent5h[	28	]	=	0	;
m_nTileRent5h[	29	]	=	1200	;
m_nTileRent5h[	30	]	=	0	;
m_nTileRent5h[	31	]	=	1275	;
m_nTileRent5h[	32	]	=	1275	;
m_nTileRent5h[	33	]	=	0	;
m_nTileRent5h[	34	]	=	1400	;
m_nTileRent5h[	35	]	=	0	;
m_nTileRent5h[	36	]	=	0	;
m_nTileRent5h[	37	]	=	1500	;
m_nTileRent5h[	38	]	=	0	;
m_nTileRent5h[	39	]	=	2000	;

//Cost to purchase a single house
m_nHouseCost[	0	]	=	0	;
m_nHouseCost[	1	]	=	50	;
m_nHouseCost[	2	]	=	0	;
m_nHouseCost[	3	]	=	50	;
m_nHouseCost[	4	]	=	0	;
m_nHouseCost[	5	]	=	0	;
m_nHouseCost[	6	]	=	50	;
m_nHouseCost[	7	]	=	0	;
m_nHouseCost[	8	]	=	50	;
m_nHouseCost[	9	]	=	50	;
m_nHouseCost[	10	]	=	0	;
m_nHouseCost[	11	]	=	100	;
m_nHouseCost[	12	]	=	0	;
m_nHouseCost[	13	]	=	100	;
m_nHouseCost[	14	]	=	100	;
m_nHouseCost[	15	]	=	0	;
m_nHouseCost[	16	]	=	100	;
m_nHouseCost[	17	]	=	0	;
m_nHouseCost[	18	]	=	100	;
m_nHouseCost[	19	]	=	100	;
m_nHouseCost[	20	]	=	0	;
m_nHouseCost[	21	]	=	150	;
m_nHouseCost[	22	]	=	0	;
m_nHouseCost[	23	]	=	150	;
m_nHouseCost[	24	]	=	150	;
m_nHouseCost[	25	]	=	0	;
m_nHouseCost[	26	]	=	150	;
m_nHouseCost[	27	]	=	150	;
m_nHouseCost[	28	]	=	0	;
m_nHouseCost[	29	]	=	150	;
m_nHouseCost[	30	]	=	0	;
m_nHouseCost[	31	]	=	200	;
m_nHouseCost[	32	]	=	200	;
m_nHouseCost[	33	]	=	0	;
m_nHouseCost[	34	]	=	200	;
m_nHouseCost[	35	]	=	0	;
m_nHouseCost[	36	]	=	0	;
m_nHouseCost[	37	]	=	200	;
m_nHouseCost[	38	]	=	0	;
m_nHouseCost[	39	]	=	200	;

//Index of purchasable property: 
// -1=not purchasable
//	0=not currently owned
//	1=owned by player 1, 2=player 2 etc.
//m_nOwned[	0	]	=	-1	;
//m_nOwned[	1	]	=	0	;
//m_nOwned[	2	]	=	-1	;
//m_nOwned[	3	]	=	0	;
//m_nOwned[	4	]	=	-1	;
//m_nOwned[	5	]	=	0	;
//m_nOwned[	6	]	=	0	;
//m_nOwned[	7	]	=	-1	;
//m_nOwned[	8	]	=	0	;
//m_nOwned[	9	]	=	0	;
//m_nOwned[	10	]	=	-1	;
//m_nOwned[	11	]	=	0	;
//m_nOwned[	12	]	=	0	;
//m_nOwned[	13	]	=	0	;
//m_nOwned[	14	]	=	0	;
//m_nOwned[	15	]	=	0	;
//m_nOwned[	16	]	=	0	;
//m_nOwned[	17	]	=	-1	;
//m_nOwned[	18	]	=	0	;
//m_nOwned[	19	]	=	0	;
//m_nOwned[	20	]	=	-1	;
//m_nOwned[	21	]	=	0	;
//m_nOwned[	22	]	=	-1	;
//m_nOwned[	23	]	=	0	;
//m_nOwned[	24	]	=	0	;
//m_nOwned[	25	]	=	0	;
//m_nOwned[	26	]	=	0	;
//m_nOwned[	27	]	=	0	;
//m_nOwned[	28	]	=	0	;
//m_nOwned[	29	]	=	0	;
//m_nOwned[	30	]	=	-1	;
//m_nOwned[	31	]	=	0	;
//m_nOwned[	32	]	=	0	;
//m_nOwned[	33	]	=	-1	;
//m_nOwned[	34	]	=	0	;
//m_nOwned[	35	]	=	0	;
//m_nOwned[	36	]	=	-1	;
//m_nOwned[	37	]	=	0	;
//m_nOwned[	38	]	=	-1	;
//m_nOwned[	39	]	=	0	;

//sandbox code for p1 owns all property
m_nOwned[	0	]	=	-1	;
m_nOwned[	1	]	=	1	;
m_nOwned[	2	]	=	-1	;
m_nOwned[	3	]	=	1	;
m_nOwned[	4	]	=	-1	;
m_nOwned[	5	]	=	1	;
m_nOwned[	6	]	=	1	;
m_nOwned[	7	]	=	-1	;
m_nOwned[	8	]	=	1	;
m_nOwned[	9	]	=	1	;
m_nOwned[	10	]	=	-1	;
m_nOwned[	11	]	=	1	;
m_nOwned[	12	]	=	1	;
m_nOwned[	13	]	=	1	;
m_nOwned[	14	]	=	1	;
m_nOwned[	15	]	=	1	;
m_nOwned[	16	]	=	1	;
m_nOwned[	17	]	=	-1	;
m_nOwned[	18	]	=	1	;
m_nOwned[	19	]	=	1	;
m_nOwned[	20	]	=	-1	;
m_nOwned[	21	]	=	1	;
m_nOwned[	22	]	=	-1	;
m_nOwned[	23	]	=	1	;
m_nOwned[	24	]	=	1	;
m_nOwned[	25	]	=	1	;
m_nOwned[	26	]	=	1	;
m_nOwned[	27	]	=	1	;
m_nOwned[	28	]	=	1	;
m_nOwned[	29	]	=	1	;
m_nOwned[	30	]	=	-1	;
m_nOwned[	31	]	=	1	;
m_nOwned[	32	]	=	1	;
m_nOwned[	33	]	=	-1	;
m_nOwned[	34	]	=	1	;
m_nOwned[	35	]	=	1	;
m_nOwned[	36	]	=	-1	;
m_nOwned[	37	]	=	1	;
m_nOwned[	38	]	=	-1	;
m_nOwned[	39	]	=	1	;

//Tiles with fixed penalties
m_nPenalty[	0	]	=	0	;
m_nPenalty[	1	]	=	0	;
m_nPenalty[	2	]	=	0	;
m_nPenalty[	3	]	=	0	;
m_nPenalty[	4	]	=	100	;
m_nPenalty[	5	]	=	0	;
m_nPenalty[	6	]	=	0	;
m_nPenalty[	7	]	=	0	;
m_nPenalty[	8	]	=	0	;
m_nPenalty[	9	]	=	0	;
m_nPenalty[	10	]	=	0	;
m_nPenalty[	11	]	=	0	;
m_nPenalty[	12	]	=	0	;
m_nPenalty[	13	]	=	0	;
m_nPenalty[	14	]	=	0	;
m_nPenalty[	15	]	=	0	;
m_nPenalty[	16	]	=	0	;
m_nPenalty[	17	]	=	0	;
m_nPenalty[	18	]	=	0	;
m_nPenalty[	19	]	=	0	;
m_nPenalty[	20	]	=	0	;
m_nPenalty[	21	]	=	0	;
m_nPenalty[	22	]	=	0	;
m_nPenalty[	23	]	=	0	;
m_nPenalty[	24	]	=	0	;
m_nPenalty[	25	]	=	0	;
m_nPenalty[	26	]	=	0	;
m_nPenalty[	27	]	=	0	;
m_nPenalty[	28	]	=	0	;
m_nPenalty[	29	]	=	0	;
m_nPenalty[	30	]	=	0	;
m_nPenalty[	31	]	=	0	;
m_nPenalty[	32	]	=	0	;
m_nPenalty[	33	]	=	0	;
m_nPenalty[	34	]	=	0	;
m_nPenalty[	35	]	=	0	;
m_nPenalty[	36	]	=	0	;
m_nPenalty[	37	]	=	0	;
m_nPenalty[	38	]	=	200	;
m_nPenalty[	39	]	=	0	;

//Tiles with Chance Card
m_bChance[	0	]	=	0	;
m_bChance[	1	]	=	0	;
m_bChance[	2	]	=	0	;
m_bChance[	3	]	=	0	;
m_bChance[	4	]	=	0	;
m_bChance[	5	]	=	0	;
m_bChance[	6	]	=	0	;
m_bChance[	7	]	=	1	;
m_bChance[	8	]	=	0	;
m_bChance[	9	]	=	0	;
m_bChance[	10	]	=	0	;
m_bChance[	11	]	=	0	;
m_bChance[	12	]	=	0	;
m_bChance[	13	]	=	0	;
m_bChance[	14	]	=	0	;
m_bChance[	15	]	=	0	;
m_bChance[	16	]	=	0	;
m_bChance[	17	]	=	0	;
m_bChance[	18	]	=	0	;
m_bChance[	19	]	=	0	;
m_bChance[	20	]	=	0	;
m_bChance[	21	]	=	0	;
m_bChance[	22	]	=	1	;
m_bChance[	23	]	=	0	;
m_bChance[	24	]	=	0	;
m_bChance[	25	]	=	0	;
m_bChance[	26	]	=	0	;
m_bChance[	27	]	=	0	;
m_bChance[	28	]	=	0	;
m_bChance[	29	]	=	0	;
m_bChance[	30	]	=	0	;
m_bChance[	31	]	=	0	;
m_bChance[	32	]	=	0	;
m_bChance[	33	]	=	0	;
m_bChance[	34	]	=	0	;
m_bChance[	35	]	=	0	;
m_bChance[	36	]	=	1	;
m_bChance[	37	]	=	0	;
m_bChance[	38	]	=	0	;
m_bChance[	39	]	=	0	;

//Tiles with Community Chest Card
m_bComChest[	0	]	=	0	;
m_bComChest[	1	]	=	0	;
m_bComChest[	2	]	=	1	;
m_bComChest[	3	]	=	0	;
m_bComChest[	4	]	=	0	;
m_bComChest[	5	]	=	0	;
m_bComChest[	6	]	=	0	;
m_bComChest[	7	]	=	0	;
m_bComChest[	8	]	=	0	;
m_bComChest[	9	]	=	0	;
m_bComChest[	10	]	=	0	;
m_bComChest[	11	]	=	0	;
m_bComChest[	12	]	=	0	;
m_bComChest[	13	]	=	0	;
m_bComChest[	14	]	=	0	;
m_bComChest[	15	]	=	0	;
m_bComChest[	16	]	=	0	;
m_bComChest[	17	]	=	1	;
m_bComChest[	18	]	=	0	;
m_bComChest[	19	]	=	0	;
m_bComChest[	20	]	=	0	;
m_bComChest[	21	]	=	0	;
m_bComChest[	22	]	=	0	;
m_bComChest[	23	]	=	0	;
m_bComChest[	24	]	=	0	;
m_bComChest[	25	]	=	0	;
m_bComChest[	26	]	=	0	;
m_bComChest[	27	]	=	0	;
m_bComChest[	28	]	=	0	;
m_bComChest[	29	]	=	0	;
m_bComChest[	30	]	=	0	;
m_bComChest[	31	]	=	0	;
m_bComChest[	32	]	=	0	;
m_bComChest[	33	]	=	1	;
m_bComChest[	34	]	=	0	;
m_bComChest[	35	]	=	0	;
m_bComChest[	36	]	=	0	;
m_bComChest[	37	]	=	0	;
m_bComChest[	38	]	=	0	;
m_bComChest[	39	]	=	0	;

//tiles of the same group or colour
m_nGroup[	0	]	=	0	;
m_nGroup[	1	]	=	1	;
m_nGroup[	2	]	=	0	;
m_nGroup[	3	]	=	1	;
m_nGroup[	4	]	=	0	;
m_nGroup[	5	]	=	9	;
m_nGroup[	6	]	=	3	;
m_nGroup[	7	]	=	0	;
m_nGroup[	8	]	=	3	;
m_nGroup[	9	]	=	3	;
m_nGroup[	10	]	=	0	;
m_nGroup[	11	]	=	4	;
m_nGroup[	12	]	=	10	;
m_nGroup[	13	]	=	4	;
m_nGroup[	14	]	=	4	;
m_nGroup[	15	]	=	9	;
m_nGroup[	16	]	=	5	;
m_nGroup[	17	]	=	0	;
m_nGroup[	18	]	=	5	;
m_nGroup[	19	]	=	5	;
m_nGroup[	20	]	=	0	;
m_nGroup[	21	]	=	6	;
m_nGroup[	22	]	=	0	;
m_nGroup[	23	]	=	6	;
m_nGroup[	24	]	=	6	;
m_nGroup[	25	]	=	9	;
m_nGroup[	26	]	=	7	;
m_nGroup[	27	]	=	7	;
m_nGroup[	28	]	=	10	;
m_nGroup[	29	]	=	7	;
m_nGroup[	30	]	=	0	;
m_nGroup[	31	]	=	8	;
m_nGroup[	32	]	=	8	;
m_nGroup[	33	]	=	0	;
m_nGroup[	34	]	=	8	;
m_nGroup[	35	]	=	9	;
m_nGroup[	36	]	=	0	;
m_nGroup[	37	]	=	2	;
m_nGroup[	38	]	=	0	;
m_nGroup[	39	]	=	2	;

//number of houses on each tile
m_nNoHouses[	0	]	=	0	;
m_nNoHouses[	1	]	=	0	;
m_nNoHouses[	2	]	=	0	;
m_nNoHouses[	3	]	=	0	;
m_nNoHouses[	4	]	=	0	;
m_nNoHouses[	5	]	=	0	;
m_nNoHouses[	6	]	=	0	;
m_nNoHouses[	7	]	=	0	;
m_nNoHouses[	8	]	=	0	;
m_nNoHouses[	9	]	=	0	;
m_nNoHouses[	10	]	=	0	;
m_nNoHouses[	11	]	=	0	;
m_nNoHouses[	12	]	=	0	;
m_nNoHouses[	13	]	=	0	;
m_nNoHouses[	14	]	=	0	;
m_nNoHouses[	15	]	=	0	;
m_nNoHouses[	16	]	=	0	;
m_nNoHouses[	17	]	=	0	;
m_nNoHouses[	18	]	=	0	;
m_nNoHouses[	19	]	=	0	;
m_nNoHouses[	20	]	=	0	;
m_nNoHouses[	21	]	=	0	;
m_nNoHouses[	22	]	=	0	;
m_nNoHouses[	23	]	=	0	;
m_nNoHouses[	24	]	=	0	;
m_nNoHouses[	25	]	=	0	;
m_nNoHouses[	26	]	=	0	;
m_nNoHouses[	27	]	=	0	;
m_nNoHouses[	28	]	=	0	;
m_nNoHouses[	29	]	=	0	;
m_nNoHouses[	30	]	=	0	;
m_nNoHouses[	31	]	=	0	;
m_nNoHouses[	32	]	=	0	;
m_nNoHouses[	33	]	=	0	;
m_nNoHouses[	34	]	=	0	;
m_nNoHouses[	35	]	=	0	;
m_nNoHouses[	36	]	=	0	;
m_nNoHouses[	37	]	=	0	;
m_nNoHouses[	38	]	=	0	;
m_nNoHouses[	39	]	=	0	;


		}



	};

#endif