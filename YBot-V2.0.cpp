// Yehya Awad, 2015

// BOT Description:
// This bot is a fork of of YBot-LabVersion.cpp
// Has many improvements like new functions etc. and some re-writes of same code


/****************************************************************

	       File: YBot-V2.0.cpp
	     Author: Yehya Awad
	     E-mail: yha5009@psu.edu
	   Due Date: April 27, 2015
	Description: DESCRIPTION OF PROGRAM

*****************************************************************/

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
	int moveNum = 0 ;
	while (true) {
		cerr << getNextMove(moveNum) << endl ;
		moveNum++ ;
		cerr << "^^------ Move #" << moveNum  << " ------^^" << endl;
	}
	return 0 ;
}

// returns message to cerr indicating what it did
string getNextMove(int moveNum) {
	
	int myPos = 0 ;
	int hisPos = 14 ;
	int distance = 14 ; 
	int playerNum = 1 ;
	vector<int> tiles;

	getBoardData(playerNum, myPos, hisPos, tiles) ;
	distance = hisPos-myPos ;
	cerr << "Distance before this move is: " << distance << endl ;
	
	if (moveNum == 0 && myPos == 14) 
	{ // First move in game
		
		return "First Move Completed" ;
	}
	if (distance > 8)
	{
		
	}
	if (distance <= 8 && distance > 4)
	{

	}
	// when opponent is close enough to hit me/I can hit him
	if (distance <= 4)
	{
		
	}

}

// Prints the command
// Params are: command, tile being used, how many times to repeat it
// Also works for shuffle.
void Command(string commandName, int tile, int reps) {
	if (commandName == "shuffle")
	{
		cout << "shuffle" << endl ;
		return ;
	}

	cerr << "Sending command " << commandName << " with tile: " << tile << " and reps: " << reps << endl ;
	cout << commandName << ";" ;
	for (int i = 0; i < reps; ++i)
	{
		cout << tile ;
	}
	cout << endl ;
}


// Parses and returns board data using reference.
// Converts Player 2 data to Player 1
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

// Returns the most repeated tile.
// Only returns 1 mode, but there can be 2 modes.
// Use getAlternateModeTile to get the second mode.
// Generally this is the lower mode of the two.
int getModeTile(vector <int> tiles) {

	int Mode = 0 ;
	int ModeReps = 0 ;
	for (int i = 1; i < 5; ++i)
	{
		if (reps[i] > ModeReps) {
			ModeReps = getRepsTile(tiles,i) ;
			Mode = i ;
		}
	}

	return Mode ;
}

// If there are two possible modes, then it will return the second mode
// Generally this is the higher mode of the two.
int getAlternateModeTile(vector <int> tiles) {

	int Mode = 0 ;
	int ModeReps = 0 ;
	for (int i = 4; i > 0; --i)
	{
		if (reps[i] > ModeReps) {
			ModeReps = getRepsTile(tiles,i) ;
			Mode = i ;
		}
	}

	return Mode ;
}


// Returns how many times a certain tile has been repeated.
int getRepsTile(vector <int> tiles, int tileNum) {
	int reps[5] = {0} ;
	for (int i = 0; i < tiles.size(); ++i)
	{
		reps[tiles[i]] += 1 ;
	}

	return reps[tileNum] ;
}

// Returns the Max Tile
int getMaxTile(vector <int> tiles) {
	int MaxTile = 0 ;
	for (int i = 0; i < tiles.size(); ++i)
	{
		if (tiles[i] > MaxTile) MaxTile = tiles[i] ;
	}

	return MaxTile ;
}

// Returns the Max Tile that is not the mode.
int getMaxNotModeTile(vector <int> tiles) {
	int MaxTile = getMinTile(tiles) ;
	int Mode = getModeTile(tiles) ;
	int AltMode = getAlternateModeTile(tiles);

	for (int i = 0; i < tiles.size(); ++i)
	{
		if (tiles[i] > MaxTile && tiles[i] != Mode && tiles[i] != getAlternateModeTile) MaxTile = tiles[i] ;
	}

	return MaxTile ;
}

// Returns the Min Tile
int getMinTile(vector <int> tiles) {
	int MinTile = 5 ;
	for (int i = 0; i < tiles.size(); ++i)
	{
		if (tiles[i] < MinTile) MinTile = tiles[i] ;
	}

	return MinTile ;
}

// Returns whether the tile exists in the tile set
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

// Sends best defensive command. Can be a move or retreat.
// Returns cerr description of what it did.
// Needs work.
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
	return "Last option, just retreated with max tile." ;
	// will try advancing instead of retreating later.

}

// New in YBot-Improve
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

// NEWINYBOTIMPROVE
// 1. moves forward if it can.
// 2. retreats safely if it can.
// 3. Shuffles otherwise.
string moveAnywhereSafe(int playerNum, int myPos, int hisPos, vector<int> tiles)
{
	int distance = hisPos - myPos ;
	Command("shuffle",0,0) ;
	return "Used 'shuffle' at moveAnywhereSafe" ;
}

// NEWINYBOTIMPROVE
// Saves mode tiles from being used and uses other tiles.
// Mode tiles can be used for good defence and attack.
// Just an idea.
void ReserveModeTiles()
{

}

// DOES NOT NECESSARILY NEED TO OUTPUT COMMAND
// Returns bool true if attacked, false if did not attack.
bool getSmartAttack(int playerNum, int myPos, int hisPos, vector<int> tiles) {
	int distance = hisPos - myPos ;
	int modeTile = getModeTile(tiles) ;
	int reps = getRepsTile(tiles, modeTile) ;

	cerr << "No Smart Attack available." ;
	return false ;
}