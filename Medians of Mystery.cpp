
/****************************************************************

	       File: 
	     Author: Yehya Awad
	     E-mail: yha5009@psu.edu
	       Date: 28th Feb 2015
	Description: DESCRIPTION OF PROGRAM

*****************************************************************/

// row1: 1 2 3 ? ? ? 9 ?
// row2: ? ? 8 9 10 11 ? ?

// final: 1 2 3 ? ? ? 9 ?

// row1: 3 - 3 ? 9
// row2: 4 - 12 ? ? ?

// final: 3 ? 9 12 ? ? ?
//		  0 1 2 3  4 5 6

// ex 2
//		4 ? 6 ? 18
//		3 2 ? ?
// Fin. 
// 2 - 6 - 2
// 4 - 18 - 2
//
// ex 3
//		 8 8 ? ?
//		 ? 8 ?
//		? 8 8 8 ? ? ?
// fin. 1 - 4 - 6
//		0 - 3 - 8
//		3 - 8 - 3
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef unordered_map<int,int> intmap;

int main() {
	
	long int coll1Size, coll2Size ;

	vector <string> collection1, collection2, allStrings;
	vector <int>	left, right;
	string currentString ;

	intmap repeatedInts ;

	cin >> coll1Size;

	//cout << "testdebug: 1" << endl ;
	for (int i = 0; i < coll1Size; ++i)
	{
		cin >> currentString;
		collection1.push_back(currentString) ;
		allStrings.push_back(currentString) ;
		left.push_back(i) ;
		right.push_back(coll1Size-i-1) ;
	}
	//cout << "testdebug: 2" << endl ;

	// canceling repeated numbers ex. 8 8 8
	/*
	for (int i = 0; i < coll1Size; ++i)
	{
		for (int j = 0; j < coll1Size; ++j)
		{
			if (i == j)
			{
				continue ;
			} else if (j < i) // right of number
			{
				if (collection1.at(i) == collection1.at(j))
				{
					left.at(i) -= 1 ;
				}
			} else if (j > i)
			{
				if (collection1.at(i) == collection1.at(j))
				{
					right.at(i) -= 1 ;
				}
			}
		}
	}
	*/

	cin >> coll2Size ;

	for (int k = 0; k < coll2Size; ++k)
	{
		cin >> currentString;
		collection2.push_back(currentString) ;
		allStrings.push_back(currentString) ;
		right.push_back(coll2Size - k - 1) ;
		left.push_back(k) ;
	}

	for (int i = 0; i < coll2Size; ++i)
	{
		for (int j = 0; j < coll2Size; ++j)
		{
			if (i == j)
			{
				continue ;
			} else if (j < i) // right of number
			{
				if (collection2.at(i) == collection2.at(j))
				{
					left.at(i+coll1Size) -= 1 ;
				}
			} else if (j > i)
			{
				if (collection2.at(i) == collection2.at(j))
				{
					right.at(i+coll1Size) -= 1 ;
				}
			}
		}
	}	

	 //Outputs left and right for each after the first step
	/*
	for (int i = 0; i < coll1Size+coll2Size; ++i)
	{
		cout << left.at(i) << "-" << allStrings.at(i) << "-" << right.at(i) << endl;
	}
	

	vector <int> allInts ; // not sorted, in order of coll1 then coll2

	for (int o = 0; o < allStrings.size(); ++o)
	{
		if (allStrings.at(o) != "?")
		{
			int localInt = stoi(allStrings.at(o),NULL,10) ;
			allInts.push_back(localInt) ;
		} else 
		{
			allInts.push_back(-1) ;// -1 for ? but in int form
		}
	}
	*/
	// final repeated number fix.

	for (int i = 0; i < allInts.size(); ++i)
	{
		int localInt = allInts.at(i) ; // int we are counting
		if (localInt == -1) continue ;

		if (repeatedInts.count(localInt) == 0) // if does not exist, create counter
		{
			repeatedInts.insert({localInt,0}) ;
		} else  // add 1 to counter if already exists
		{
			repeatedInts[localInt] += 1 ;
		}
	}
	
	// after counting we try to find a solution from the info we have

	for (int i = 0; i < allInts.size(); ++i)
	{
		int localInt = allInts.at(i) ;
		if (localInt == -1) continue ;

		if (i < coll1Size)
		{
			for (int o = 0; o < coll2Size; ++o)
			{
				int locallocalInt = allInts.at(o) ;
				if (localInt < localInt)
				{
					/* code */
				}
			}
		} else {

		}
	}

	//cout << "testdebug: 3" << endl ;
	///Didn't work (FOR OBVIOUS REASONS)
	int half = left.size()/2 ; // if 3.5 goes to 3 etc...
	vector<string> result ;
	for (int l = 0; l < coll1Size+coll2Size-1; ++l)
	{
		if (right[l] == half || left[l] == half)
		{
			if (l >= coll1Size)
			{
				
					//cout << collection2[l-coll1Size] ;
					result.push_back(collection2[l-coll1Size]) ;

			} else 
			{
				
					//cout << collection1[l] ;
					result.push_back(collection1[l]) ;
				
			}
		}
	}

	if (result.size() == 1)
	{
		if (result[0] == "?")
		{
			cout << "Unknown" ;
		}
		cout << result[0] ;
	}
	
	return 0;
}
