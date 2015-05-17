
/****************************************************************

	       File: Power Grid.cpp
	     Author: Yehya Awad
	     E-mail: yha5009@psu.edu
	       Date: 3 March 2015
	Description: Power Grid

https://www.hackerrank.com/contests/psh-qualifying-contest-spring-2015/challenges/power-grid
*****************************************************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


//////////////////////////
///// type shortcuts /////
//////////////////////////

typedef vector<string> grid; // grid.size() = height // grid[0].size() = width
typedef unordered_map<long int , bool> intmap; // first number holds pointID, second holds if it's a house or not

//////////////////////
///// PROTOTYPES /////
//////////////////////

grid getGrid() ;
grid getConductorsGrid(grid arg_Grid) ;
grid getPoweredHousesGrid(grid arg_Grid) ;
void printGrid(grid arg_Grid) ;
void createAllConnections(grid arg_Grid, long int pointID, intmap & usedPowerPlants, intmap & connectionBatch) ;
void recur_nextConnection(grid a, long int b, intmap & c, intmap & d) ;
void connectGridPoint(grid arg_Grid, intmap & arg_ConnectedCords, long int pointID) ;
long int getPointID(grid arg_Grid, long int y, long int x) ;
void ref_getXYCoords(grid arg_Grid, long int pointID, long int & y, long int & x) ;
bool isHouse(grid arg_Grid, long int pointID) ;
bool isConducting(grid arg_Grid, long int pointID) ;
bool isPowerPlant(grid arg_Grid, long int pointID) ;
long int getPowerPlantNum(grid arg_Grid) ;
long int findNextPowerPlant(grid arg_Grid, intmap usedPowerPlants);
long int getHousesNum(grid arg_Grid);

////////////////
///// MAIN /////
////////////////

int main() {

	grid originalGrid, conductorsGrid, poweredHousesGrid ;
	originalGrid = getGrid() ; // loads Grid
	//conductorsGrid = getConductorsGrid(originalGrid) ;

	// printGrid(originalGrid); // test // works :D
	// printGrid(conductorsGrid); // test // works :D

	long int numOfPowerPlants = getPowerPlantNum(originalGrid) ;
	// cout << "Number of PowerPlants here is: " << numOfPowerPlants << endl ; // TESTING PURPOSES

	poweredHousesGrid = getPoweredHousesGrid(originalGrid) ; // also prints number of houses powered.

	printGrid(poweredHousesGrid) ; // This should be the solution for the grid print.

	return 0;
}

/////////////////////////////
///// FUNCTIONS FOR USE /////
/////////////////////////////

// Gets provided grid in std input
grid getGrid() 
{
	// cout << "TEST NO getGrid" << endl ; // TESTDEBUG
	grid Grid ;
	long int height, width;
	cin >> height ;
	cin >> width ; // getting width, but useless so not using
	// cout << "TEST NO getGrid loop" << endl ; // TESTDEBUG

	for (long int i = 0; i < height; ++i)
	{
		string line ;
		cin >> line ;
		Grid.push_back(line) ;
	}
	return Grid ;
}

// converts main grid to one that has all CONDUCTABLE points to #
// points like A-Z, |, +, -, NOT HOUSES. Houses stay H.
grid getConductorsGrid(grid arg_Grid) 
{
	// cout << "TEST NO getConductorsGrid" << endl ; // TESTDEBUG // TESTING PURPOSES
	grid conductorsGrid ;
	long int height = arg_Grid.size() ;
	long int width = arg_Grid[0].size() ;

	// x,y are location of character in Grid
	for (long int y = 0; y < height; ++y)
	{
		conductorsGrid.push_back("");
		for (long int x = 0; x < width; ++x)
		{
			char gridPoint = arg_Grid[y][x] ;
			// using switch // faster
			switch (gridPoint) 
			{
				case 'P':
					conductorsGrid[y].push_back('P') ;
					break ;
				case 'H':
					conductorsGrid[y].push_back('H') ;
					break ;
				case '|':
				case '+':
				case '-':
					conductorsGrid[y].push_back('*') ;
					break ;
				default:
					if (gridPoint >= 65 && gridPoint <= 90)
					{
						conductorsGrid[y].push_back('*') ;
					} else {
						conductorsGrid[y].push_back(gridPoint) ;
					}
			}
		}
	}
	return conductorsGrid ;
}

// converts main grid to one that has all powered connections converted to *
// Houses only so that we can count them later for the answer.
// incomplete
grid getPoweredHousesGrid(grid arg_Grid)
{
	// cout << "TEST NO getPoweredHousesGrid" << endl ; // TESTDEBUG // TESTING PURPOSES
	grid poweredHousesGrid(arg_Grid) ; // starting with original.
	long int height = arg_Grid.size() ;
	long int width 	= arg_Grid[0].size() ;
	long int totalPoweredHouses = 0 ;

	// now we somehow find out which ones are powered, and which are not.
	// I'm clueless on how to do it right now. March 6, 2015

	intmap usedPowerPlants;
	intmap connectionBatch;
	long int numOfPowerPlants = getPowerPlantNum(arg_Grid) ;
	
	for (long int i = 0; i < numOfPowerPlants; ++i)
	{
		long int numOfPoweredHouses = 0; // in the batch
		long int pointID = findNextPowerPlant(arg_Grid, usedPowerPlants);
		if (pointID == -1) continue ; // no more powerplants
		if (usedPowerPlants.count(pointID) == 0)
		{
			long int now_usedPPlants = usedPowerPlants.size(); // will subtract later to see change after
			usedPowerPlants.insert({pointID,false}); // false, doesn't really matter if false or true for second arg.
			recur_nextConnection(arg_Grid, pointID, usedPowerPlants, connectionBatch);
			
			// after connections created
			long int PowerPlantsInBatch = usedPowerPlants.size() - now_usedPPlants ; // getting 
			long int maxPowerableHouses = PowerPlantsInBatch*30 ; // max capacity of houses to power

			// counting houses
			for (intmap::iterator kt = connectionBatch.begin(); kt != connectionBatch.end(); ++kt)
			{
				long int x, y;
			    ref_getXYCoords(arg_Grid, kt->first, y, x); // getting x and y to access
				poweredHousesGrid[y][x] = '*' ;
				bool bool_isHouse = isHouse(arg_Grid, kt->first) ;
			    if (bool_isHouse && numOfPoweredHouses < maxPowerableHouses) // is a house
			    {
			    	++numOfPoweredHouses; // power up!
			    }
			}
		}
		totalPoweredHouses += numOfPoweredHouses ;
		connectionBatch.clear() ;
	}

	//cout << totalPoweredHouses << endl ;
	// 0 of 18 homes are without power.
	cout << getHousesNum(arg_Grid) - totalPoweredHouses << " of " << getHousesNum(arg_Grid) << " homes are without power." << endl ;
	return poweredHousesGrid ;
}

// Gets all connections in one batch of connected houses etc.
// incomplete
// Useless?
/*
void createAllConnections(grid arg_Grid, long int pointID, intmap & usedPowerPlants, intmap & connectionBatch)
{
	recur_nextConnection(arg_Grid, pointID, usedPowerPlants, connectionBatch) ;
	// after all connections created then...
}
*/

// incomplete
void recur_nextConnection(grid arg_Grid, long int pointID, intmap & usedPowerPlants, intmap & connectionBatch)
{
	// cout << "Next connection being created..." << endl ; // TESTING PURPOSES
	if (connectionBatch.count(pointID) != 0) return ; // if already in connectionBatch
	// cout << "Passed this one.." << endl ; // TESTING PURPOSES
	if (isConducting(arg_Grid, pointID) == false) return ; // if not conductor
	// cout << "Passed this one.." << endl ; // TESTING PURPOSES
	if (isPowerPlant(arg_Grid, pointID)) // if apart of batch, then used
	{
		if (usedPowerPlants.count(pointID) == 0)
		{
			usedPowerPlants.insert({pointID,false}) ;
		}
	}

	bool house = isHouse(arg_Grid,pointID) ;
	connectionBatch.insert({pointID,house}) ;
	// cout << "Adding point " << pointID << " to connectionBatch, isHouse = " << house << endl ; // TESTING PURPOSES
	long int x, y;
	ref_getXYCoords(arg_Grid, pointID, y, x);

	long int height = arg_Grid.size() ;
	long int width = arg_Grid[0].size() ;	

	// Starting next recursion

	long int nextPointID ;
	if (x > 0)
	{
		nextPointID = getPointID(arg_Grid, y, x-1);
		recur_nextConnection(arg_Grid, nextPointID, usedPowerPlants, connectionBatch);
	} 
	if (x < width-1)
	{
		nextPointID = getPointID(arg_Grid, y, x+1);
		recur_nextConnection(arg_Grid, nextPointID, usedPowerPlants, connectionBatch);
	}
	if (y > 0)
	{
		nextPointID = getPointID(arg_Grid, y-1, x);
		recur_nextConnection(arg_Grid, nextPointID, usedPowerPlants, connectionBatch);
	} 
	if (y < height-1)
	{
		nextPointID = getPointID(arg_Grid, y+1, x);
		recur_nextConnection(arg_Grid, nextPointID, usedPowerPlants, connectionBatch);
	}
}

// connects grid point to a current batch of houses until all houses connected.
// not used as of now.
void connectGridPoint(grid arg_Grid, intmap & arg_ConnectedCords, long long int pointID) 
{
	if (arg_ConnectedCords.count(pointID) == 0)
	{
		arg_ConnectedCords.insert({pointID,false}) ;
	}
}

// Gets the ID of an X,Y point for use with the Unordered Map
// Completed
long int getPointID(grid arg_Grid, long int y, long int x) 
{
	long int width = arg_Grid[0].size() ;

	return y*width + x ; //
}

// Reverse of getPointID
// Completed
void ref_getXYCoords(grid arg_Grid, long int pointID, long int & y, long int & x)
{
	long int height = arg_Grid.size() ;
	long int width = arg_Grid[0].size() ;

	x = pointID%width ;
	y = (pointID-x)/width ;
}

// returns if a house is at the pointID at the grid 
// Completed
bool isHouse(grid arg_Grid, long int pointID) 
{
	long int x, y;
	ref_getXYCoords(arg_Grid, pointID, y, x); // get's x and y
	if (arg_Grid[y][x] == 'H') return true;
	return false;
}

// Completed
bool isConducting(grid arg_Grid, long int pointID) 
{
	long int x, y;
	ref_getXYCoords(arg_Grid, pointID, y, x); // get's x and y

	// cout << "Is " << arg_Grid[y][x] << " conductive?  Let's see... " ; // TESTING PURPOSES

	if (arg_Grid[y][x] >= 'A' && arg_Grid[y][x] <= 'Z') return true ;

	switch (arg_Grid[y][x]) 
	{
		//case '*': // messed up test case #7
		case '+':
		case 'H':
		case '-':
		case '|':
		case 'P':
			// cout << "Yes!" << endl ;  // TESTING PURPOSES
			return true ;
		default: 
			// cout << "No.." << endl ; // TESTING PURPOSES
			return false ;
	}

	return false;
}

// Completed
bool isPowerPlant(grid arg_Grid, long int pointID) 
{
	long int x, y;
	ref_getXYCoords(arg_Grid, pointID, y, x); // get's x and y

	switch (arg_Grid[y][x]) 
	{
		case 'P':
			return true ;
		default:
			return false ;
	}

	return false;
}

// Gets number of P's in a grid
// Completed
long int getPowerPlantNum(grid arg_Grid) 
{
	long int height = arg_Grid.size() ;
	long int width = arg_Grid[0].size() ;

	long int num = 0 ;

	// x,y are location of character in Grid
	for (long int y = 0; y < height; ++y)
	{
		for (long int x = 0; x < width; ++x)
		{
			char gridPoint = arg_Grid[y][x] ;
			// using switch // faster
			switch (gridPoint) 
			{
				case 'P':
					++num;	
			}
		}
	}

	return num;
}

// finds next powerplant and returns it's pointID
// Completed
long int findNextPowerPlant(grid arg_Grid, intmap usedPowerPlants)
{
	long int height = arg_Grid.size() ;
	long int width = arg_Grid[0].size() ;

	// Going through grid
	for (long int y = 0; y < height; ++y)
	{
		for (long int x = 0; x < width; ++x)
		{
			char gridPoint = arg_Grid[y][x] ;
			if (gridPoint == 'P')
			{
				long int pointID = getPointID(arg_Grid, y, x);
				if (usedPowerPlants.count(pointID) == 0)
				{
					// cout << "UNused PowerPlant found at: x: " << x << " | y: " << y << endl ; // TESTING PURPOSES
					return pointID ;
				}
				// cout << "USED PowerPlant found at: x: " << x << " | y: " << y << endl ; // TESTING PURPOSES
				// cout << "Finding next PowerPlant..." << endl ; // TESTING PURPOSES
			}
		}
	}
	// cout << "All PowerPlants used." << endl ; // TESTING PURPOSES
	return -1 ; // No Unused Powerplants found.
}

// Prints any grid
// Completed
void printGrid(grid arg_Grid) 
{
	// cout << "TEST NO printGrid" << endl ; // TESTDEBUG
	long int height = arg_Grid.size() ;
	long int width = arg_Grid[0].size() ;

	for (long int y = 0; y < height; ++y)
	{
		for (long int x = 0; x < width; ++x)
		{
			char gridPoint = arg_Grid[y][x] ;
			// using switch // faster
			cout << gridPoint ;
		}
		cout << endl ;
	}
	cout << endl ;
}

// Gets number of all houses
// Completed
long int getHousesNum(grid arg_Grid)
{
	long int height = arg_Grid.size() ;
	long int width = arg_Grid[0].size() ;

	long int num = 0 ;

	// x,y are location of character in Grid
	for (long int y = 0; y < height; ++y)
	{
		for (long int x = 0; x < width; ++x)
		{
			char gridPoint = arg_Grid[y][x] ;
			// using switch // faster, I think...
			switch (gridPoint) 
			{
				case 'H':
					++num;	
			}
		}
	}

	return num;
}

