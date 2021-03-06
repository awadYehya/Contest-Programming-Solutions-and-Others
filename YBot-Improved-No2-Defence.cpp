// New bot with defence prefference FIRST!
// Let's see if it's stronger!
// Copyright Yehya Awad, 2015

// SO VERY WEAK!
// DEFENCE IS A BAD STRATEGY.
// YBot-Improved-No2.cpp is much stronger!


/****************************************************************

	       File: YBot-Improved-No2.cpp
	     Author: Yehya Awad
	     E-mail: yha5009@psu.edu
	   Due Date: April 20, 2015
	Description: Creating a bot for something in CMPSC 465

*****************************************************************/

// Differences from last bot: //
// moveAnywhereSafe
// ReserveModeTiles

// Ideas to include for next bot: //
// Save tiles of 4: this is because a block moves back
// the attacker to a distance of 4
// so you can instantly attack after any block.
// this means I should use defence positions
// that do not use the 4 tiles (unless I have to)
// and that I should not move 4 tiles (unless I have to)

#include <string>
#include <iostream>
#include <vector>
using namespace std;

// Bot battle.

string getNextMove(int moveNum) ;
void Command(string commandName, int tile, int reps) ;
void getBoardData (int & playerNum, int & myPos, int & hisPos, vector<int> & tiles) ;
int getModeTile(vector <int> tiles) ;
int getRepsTile(vector <int> tiles, int tileNum) ;
int getMaxTile(vector <int> tiles) ;
int getMaxNotModeTile(vector <int> tiles) ;
int getMinTile(vector <int> tiles) ;
bool DoesTileExist(vector<int> tiles, int tileNum) ;
string getSmartDefend(int playerNum, int myPos, int hisPos, vector<int> tiles) ;
bool getSmartAttack(int playerNum, int myPos, int hisPos, vector<int> tiles) ;
string moveAnywhereSafe(int playerNum, int myPos, int hisPos, vector<int> tiles) ;
bool canDefendWithTile(vector<int> tiles, int tileNum, int targetTile) ;

int main() {
	int shuffles = 0 ; // unused currently.
	int moveNum = 0 ;
	while (true) {
		cerr << getNextMove(moveNum) << endl ;
		moveNum++ ;
		cerr << "^^------ Move #" << moveNum  << " ------^^" << endl;
	}
	return 0 ;
}


string getNextMove(int moveNum) {
	// Get board input
	// if bot 1 //****************************
	// let's code bot 1 first // *************

	// VARS //// VARS //// VARS //// VARS //
	// myPos
	int myPos = 0 ;
	int hisPos = 14 ;
	int distance = 14 ; // when game begins
	int playerNum = 1 ;
	vector<int> tiles;

	getBoardData(playerNum, myPos, hisPos, tiles) ;
	distance = hisPos-myPos ;
	cerr << "Distance before this move is: " << distance << endl ;
	// hisPos
	// Distance between us
	// tile array

	// now if statements for priority
	// when game starts
	if (moveNum == 0) 
	{
		// move farthest distance I got
		// get farthest distance
		// move farthest distance
		int farthest = getMaxNotModeTile(tiles) ;
		int modeTile = getModeTile(tiles) ;
		// NEWINYBOTIMPROVE
		// I want to save the mode tile for later attacks.
		if (farthest == modeTile)
		{
			// moveAnywhereSafe(playerNum, myPos, hisPos, tiles)
		}
		Command("move",farthest,1) ;
		return "First Move Completed" ;
		// another option here would be to use something that is not the mode
		// the mode is useful for attacks and defence
	}
	if (distance > 8)
	{
		int tile = getMaxNotModeTile(tiles) ;
		cerr << "Distance > 8 move." << endl ;
		Command("move",tile,1) ;
		return "Moved Max not mode because distance is high." ;
	}
	if (distance <= 8 && distance > 4)
	{ // when I can set up a 4 tile defence etc.
		int minTile = getMinTile(tiles) ;
		return getSmartDefend(playerNum, myPos, hisPos, tiles) ;
	}
	// when opponent is close enough to hit me/I can hit him
	if (distance <= 4)
	{
		string defence = getSmartDefend(playerNum, myPos, hisPos, tiles);
		if (defence != "")
		{
			return defence ;
		}
		// what is the number I have most of? (maybe more than 1)
		int mode = getModeTile(tiles) ;
		int attacked = getSmartAttack(playerNum, myPos, hisPos, tiles) ;

		return "Used getSmartAttack" ;
		// if I have more than 2 tiles in a number, can I move to that tile?
		// 
	}

	// Last case scenario...
	int minTile = getMinTile(tiles) ;
	return getSmartDefend(playerNum, myPos, hisPos, tiles) ;

	// if bot 2 then invert ********************
	// if bot 2 then we do this ****************

}

// Prints the command
void Command(string commandName, int tile, int reps) {
	cerr << "Sending command " << commandName << " with tile: " << tile << " and reps: " << reps << endl ;
	cout << commandName << ";" ;
	for (int i = 0; i < reps; ++i)
	{
		cout << tile ;
	}
	cout << endl ;
}

void getBoardData (int & playerNum, int & myPos, int & hisPos, vector<int> & tiles) {
	// right now only works for player 1.
	string board ;
	while (true) {
		cin >> board ;
		if (board != "") break ;
	}
	// reading done, now I have to organize it
	playerNum = board[0] - 48 ;

	// GETS TILES
	tiles.clear() ;
	for (int countI = 2; countI < 7; ++countI)
	{
		tiles.push_back(board[countI] - 48) ; // gets tiles
	}

	// GETS MYPOS and HISPOS
	for (int countK = 0; countK < 15; ++countK)
	{
		if (board[8+countK] - 48 == 1) {
			myPos = countK ;
		}
		if (board[8+countK] - 48 == 2) {
			hisPos = countK ;
			break ;
		}
	}
	cerr << "Got Board Data at pos: " << myPos << endl ;
	cerr << "Board: " << board << endl ;
	cerr << "I am Player: " << playerNum << endl ;

	// Converting board data to Player 1 info, if we are Player 2
	// Because my code is only for Player 1 data.
	if (playerNum == 2) {
		cerr << "My Pos " << hisPos ;
		int tempPos = hisPos ;
		hisPos = 14 - myPos ; // should probably work...
		myPos = 14 - tempPos ;
		cerr << " --> " << myPos << endl ;
	}
}

int getModeTile(vector <int> tiles) {
	int reps[5] = {0} ;
	for (int i = 0; i < tiles.size(); ++i)
	{
		reps[tiles[i]] += 1 ;
	}

	int Mode = 0 ;
	int ModeReps = 0 ;
	for (int i = 1; i < 5; ++i)
	{
		if (reps[i] > ModeReps) {
			ModeReps = reps[i] ;
			Mode = i ;
		}
	}

	return Mode ;
}

int getRepsTile(vector <int> tiles, int tileNum) {
	int reps[5] = {0} ;
	for (int i = 0; i < tiles.size(); ++i)
	{
		reps[tiles[i]] += 1 ;
	}

	return reps[tileNum] ;
}

int getMaxTile(vector <int> tiles) {
	int MaxTile = 0 ;
	for (int i = 0; i < tiles.size(); ++i)
	{
		if (tiles[i] > MaxTile) MaxTile = tiles[i] ;
	}

	return MaxTile ;
}

int getMaxNotModeTile(vector <int> tiles) {
	int MaxTile = getMinTile(tiles) ;
	int Mode = getModeTile(tiles) ;

	for (int i = 0; i < tiles.size(); ++i)
	{
		if (tiles[i] > MaxTile && tiles[i] != Mode) MaxTile = tiles[i] ;
	}

	return MaxTile ;
}

int getMinTile(vector <int> tiles) {
	int MinTile = 5 ;
	for (int i = 0; i < tiles.size(); ++i)
	{
		if (tiles[i] < MinTile) MinTile = tiles[i] ;
	}

	return MinTile ;
}

bool DoesTileExist(vector<int> tiles, int tileNum) {
	for (int i = 0; i < tiles.size(); ++i)
	{
		if (tileNum == tiles[i])
		{
			cerr << "Yes, tile: " << tileNum << " does exist." << endl ;
			return true ;
		}
	}
	return false ;
}

// MUST ALWAYS OUTPUT COMMAND
string getSmartDefend(int playerNum, int myPos, int hisPos, vector<int> tiles) 
{
	// So here I want to check first if I can move to a place where my mode can DEFEND
	// cout << "TEST NO SmartDefend" << endl ; // TESTDEBUG
	int distance = hisPos - myPos ;
	// cout << "TEST NO distance: " << distance << endl ; // TESTDEBUG
	int modeTile = getModeTile(tiles) ;
	// cout << "TEST NO modeTile: " << modeTile << endl ; // TESTDEBUG
	int targetTile = 0 ; // tile I need to move to defensive position.
	// cout << "TEST NO targetTile: " << targetTile << endl ; // TESTDEBUG
	string moveOrRetreat = "move" ;

	if (distance > modeTile)
	{
		targetTile = distance - modeTile ;
		// cout << "TEST NO targetTile: " << targetTile << endl ; // TESTDEBUG
		moveOrRetreat = "move" ;
	} else if (distance < modeTile)
	{
		targetTile = modeTile - distance ;
		// cout << "TEST NO targetTile: " << targetTile << endl ; // TESTDEBUG
		moveOrRetreat = "retreat" ;
	}

	if (DoesTileExist(tiles, targetTile) && (targetTile <= myPos || moveOrRetreat == "move")) 
	{
		// if the target tile exists then we use it.
		cerr << "Mode tile is: " << modeTile << endl ;
		Command(moveOrRetreat,targetTile,1) ;
		return "Used Smart Defend with Mode " ;
	}

	// If target tile does not exist we look for another option...
	else 
	{
		for (int countK = 0; countK < tiles.size(); ++countK)
		{
			if (distance > tiles[countK])
			{
				targetTile = tiles[countK] - distance ;
				moveOrRetreat = "retreat" ;
			} else if (distance > tiles[countK])
			{
				targetTile = distance - tiles[countK] ;
				moveOrRetreat = "move" ;
			}

			// New in YBot-Improve
			if (canDefendWithTile(tiles,tiles[countK],targetTile)) {
				// if the target tile exists then we use it.
				cerr << "Sending Smart Defend without mode Command." << endl ;
				Command(moveOrRetreat,targetTile,getRepsTile(tiles, targetTile)) ;
				return "Used Smart Defend without! Mode " ;
			}
		}
	}

	cerr << "At 'Move Infront' options! " << endl ;

	if (DoesTileExist(tiles, distance-1))
	{
		Command("move",distance-1,1) ;
		return "Moving infront of the enemy bot. Dist 1 " ;
	}

	if (DoesTileExist(tiles, distance-2))
	{
		Command("move",distance-2,1) ;
		return "Moving infront of the enemy bot. Dist 2 " ;
	}

	if (DoesTileExist(tiles, distance-3)) 
	{
		Command("move",distance-3,1) ;
		return "Moving infront of the enemy bot. Dist 3 " ;
	}

	if (DoesTileExist(tiles, distance-4))
	{
		Command("move",distance-4,1) ;
		return "Moving infront of the enemy bot. Dist 4 " ;
	}
	// cout << "shuffle" << endl ;
	// return "Shuffled the tiles. " ;

	// no command here...
	return "" ;
}

// NEWINYBOTIMPROVE
bool canDefendWithTile(vector<int> tiles, int tileNum, int targetTile)
{
	if (DoesTileExist(tiles, targetTile))
	{
		if (getRepsTile(tiles, targetTile) >= 2 || tileNum != targetTile)
		{
			return true;
		}
	}
	return false;
}

// NEWINYBOTIMPROVE-2
// 1. moves forward if it can.
// 2. retreats safely if it can.
// 3. Shuffles otherwise.
string moveAnywhereSafe(int playerNum, int myPos, int hisPos, vector<int> tiles)
{
	int distance = hisPos - myPos ;

	// forward first...
	// moves farthest possible.

	// First tries to move not the mode..
	int someTile = getMaxNotModeTile(tiles);
	if (someTile < distance)
	{
		Command("move",someTile,1) ;
		return "Used 'move' at moveAnywhereSafe" ;
	}

	// then checks any other possible moves...

	for (int countK = 0; countK < tiles.size(); ++countK)
	{
		for (int someTile = 4; someTile > 0; --someTile)
		{
			if (DoesTileExist(tiles, someTile) && someTile < distance)
			{
				Command("move",someTile,1) ;
				return "Used 'move' at moveAnywhereSafe" ;
			}
		}
	}

	// then retreat options...
	// retreats most distance possible first.


	if (someTile <= myPos)
	{
		Command("retreat",someTile,1) ;
		return "Used 'retreat' at moveAnywhereSafe" ;
	}

	for (int countK = 0; countK < tiles.size(); ++countK)
	{
		for (int someTile = 4; someTile > 0; --someTile)
		{
			if (DoesTileExist(tiles, someTile) && someTile <= myPos)
			{
				Command("retreat",someTile,1) ;
				return "Used 'retreat' at moveAnywhereSafe" ;
			}
		}
	}

	// if all else fails.
	cout << "shuffle" << endl ; // THIS IS A COMMAND!
	return "Used 'shuffle' at moveAnywhereSafe" ;
}

// NEWINYBOTIMPROVE
// Saves mode tiles from being used and uses other tiles
// instead when moving etc.
// Mode tiles can be used for good defence and attack.
// Just an idea.
void ReserveModeTiles()
{

}

// DOES NOT NECESSARILY NEED TO OUTPUT COMMAND
bool getSmartAttack(int playerNum, int myPos, int hisPos, vector<int> tiles) {
	int distance = hisPos - myPos ;
	int modeTile = getModeTile(tiles) ;
	int reps = getRepsTile(tiles, modeTile) ;

	if (modeTile == distance)
	{
		Command("attack",modeTile,reps) ;
		cerr << "Used Smart Attack." << endl ;
		return true ;
	}

	if (DoesTileExist(tiles, distance))
	{
		Command("attack",distance,getRepsTile(tiles,distance)) ;
		cerr << "Used Smart Attack 2. " << endl ;
		return true ;
	}

	cerr << "No Smart Attack available." ;

	moveAnywhereSafe(playerNum, myPos, hisPos, tiles) ;

	return false ;
}