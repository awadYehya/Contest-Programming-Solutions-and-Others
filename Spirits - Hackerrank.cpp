
/****************************************************************

	       File: 
	     Author: Yehya Awad
	     E-mail: yha5009@psu.edu
	   Due Date: 1 March 2015
	Description: 

	Incomplete.
*****************************************************************/

#include <cmath>
#include <math.h>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <unordered_map>
using namespace std;

typedef unordered_map<int,int> intmap;

bool sheDidIt(int maxIndex) ;

int main() {

	int casesNum, maxIndex ;

	cin >> casesNum ;

	for (int countI = 0; countI < casesNum; ++countI)
	{
		cin >> maxIndex ;
		if (sheDidIt(maxIndex)) 
		{
			cout << "She did it!" << endl ;
		}
	}
	return 0 ;
}

bool sheDidIt(int maxIndex) 
{
	vector<int> spirits;
	bool usedReversal = false ;
	int spiritPowa ;
	int girlHealth = 0 ;
	int maxNumIndex = -100000 ;
	bool badSpiritsExist = false ;
	int currentMaxNum = 0 ;
	for (int count = 0; count < maxIndex; ++count)
	{
		cin >> spiritPowa ;
		spirits.push_back(spiritPowa) ;

		if (spiritPowa < currentMaxNum) // getting the max -ve number as well.
		{
			badSpiritsExist = true ;
			currentMaxNum = spiritPowa ;
			maxNumIndex = count ;
		}

	}

	for (int countI = 0; countI < maxIndex; ++countI)
	{
		if (spirits[countI] >= 0 )
		{
			girlHealth += spirits[countI] ;
		}
		else if (spirits[countI] < 0 && maxNumIndex == countI && !usedReversal)
		{
			usedReversal = true ;
			girlHealth -= spirits[countI] ; // reverses spirits power
		} 
		else if (spirits[countI] < 0 && spirits[countI] + girlHealth < 0 && !usedReversal) 
		{
			usedReversal = true ;
			girlHealth -= spirits[countI] ;
		} 
		else if (spirits[countI] < 0 && spirits[countI] + girlHealth < 0) 
		{
			cout << countI + 1 << endl ; // she's dead.
			return false ;
		} 
		else if (spirits[countI] < 0) 
		{
			girlHealth += spirits[countI] ;
		}
	}

	return true ;
}

int FindReverseSpirit(vector<int> spirits)
{
	int girlHealth = 0 ;
	int deathPosition = 0 ;
	int worstPassedSpiritPos = -1 ;
	int worstPassedSpiritPow = -1 ;
	for (int countI = 0; countI < spirits.size(); ++countI)
	{
		if (spirits[countI] <= worstPassedSpiritPow)
		{
			worstPassedSpiritPos = countI ;
			worstPassedSpiritPow = spirits[countI] ;
		}

		girlHealth += spirits[countI] ;
		if (girlHealth < 0)
		{
			return worstPassedSpiritPos ;
		}
	}

	return -1 ; // no bad spirits. alive.
}
