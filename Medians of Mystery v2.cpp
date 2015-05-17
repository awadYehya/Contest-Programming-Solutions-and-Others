#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

/* Thinking space:
	
Sample Input:
				3 3 ? 9
				4 12 ? ? ? 
	Output:		
				12

HOW IT WORKS:
				left = 3 - [12] - right = 3

				If any side = half, then we median that shit.

Sample Input2: ? 8 8 8 ? ? ?
				4 8 8 ? ?
				3 ? 8 ?
	Output:	
				8

HOW IT WORKS:
				left =	2 repeated + 3 - [8] - right = 2 repeated + 3
				should I make a range when repeated?
				like... + or - 2 because it's repeated twice? because median 
Sample Input3: 
				4 ? 6 ? 18
				3 2 ? ?
	Output:	
				Unknown

HOW IT WORKS:
				 


*/

typedef unordered_map<int,int> intmap;
typedef vector<string> stringVector;


//////////////////////
///// Prototypes /////
//////////////////////

void PrintLeftRightVals(vector<int> rowInts, vector<int> left, vector<int> right);
vector<int> stringVecTOint(stringVector arg_stringVec);
void ref_getRestOfLeft(vector<int> & a, vector<int> b, vector<int> c, vector<int> d) ;
void ref_getRestOfRight(vector<int> & a, vector<int> b, vector<int> c, vector<int> d) ;
vector<int> ref_getInitialLeft (stringVector row)  ;
vector<int> ref_getInitialRight (stringVector row)  ;
stringVector ref_getInputData(stringVector &row1, stringVector &row2) ;


////////////////
///// Main /////
////////////////


int main() 
{
	
	long int row1Width, row2Width ;

	stringVector row1, row2, combinedRows;
	vector <int> left1, right1, left2, right2, intRow1, intRow2;
	string currentString ;
	cout << "TEST NO 1" << endl ; // TESTDEBUG
	combinedRows = ref_getInputData(row1, row2) ;
	cout << "TEST NO 2" << endl ; // TESTDEBUG
	intRow1 = stringVecTOint(row1) ;
	intRow2 = stringVecTOint(row2) ;
	cout << "TEST NO 3" << endl ; // TESTDEBUG
	row1Width = row1.size(); 
	row2Width = row2.size() ; // getting widths
	cout << "TEST NO 4" << endl ; // TESTDEBUG
	left1 = ref_getInitialLeft(row1) ;
	right1 = ref_getInitialRight(row1) ;
	left2 = ref_getInitialLeft(row2) ;
	right2 = ref_getInitialRight(row2) ;
	cout << "TEST NO 5" << endl ; // TESTDEBUG
	PrintLeftRightVals(intRow1, left1, right1) ;
	PrintLeftRightVals(intRow2, left2, right2) ;
	// for row1
	vector<int> resultLeft1 = ref_getRestOfLeft(left1, intRow1, intRow2, left2) ;
	vector<int> resultRight1 = ref_getRestOfRight(right1, intRow1, intRow2, right2) ;
	// for row2
	vector<int> resultLeft2 = ref_getRestOfLeft(left2, intRow2, intRow1, left1) ;
	vector<int> resultRight2 = ref_getRestOfRight(right2, intRow2, intRow1, right1) ;
	cout << "TEST NO 6" << endl ; // TESTDEBUG
	PrintLeftRightVals(intRow1, resultLeft1, right1) ;
	PrintLeftRightVals(intRow2, left2, right2) ;

	return 0;
}


///////////////////////////
///// Other Functions /////
///////////////////////////


void PrintLeftRightVals(vector<int> rowInts, vector<int> left, vector<int> right)
{
	for (int i = 0; i < rowInts.size(); ++i)
	{
		if (rowInts[i] == -1) continue ;
		cout << left[i] << "\t - \t" << rowInts[i] <<  "\t - \t" << right[i] << endl ;
	}
	cout << endl ;
}

vector<int> stringVecTOint(stringVector arg_stringVec)
{
	vector<int> intVector ;
	for (int i = 0; i < arg_stringVec.size(); ++i)
	{
		if (arg_stringVec[i] != "?")
		{
			intVector.push_back(stoi(arg_stringVec[i], NULL, 10));
		} else 
		{
			intVector.push_back(-1) ; // -1 , meaning ? mark
		}
	}

	return intVector ;
}

// basically extracts any remaining left values from the other row input to help in finding median
void ref_getRestOfLeft(vector<int> & first_Left, vector<int> first_intRow, vector<int> second_intRow, vector<int> second_Left) 
{
	vector<int> resultLeft ;

	// Sample Input:
	// 			3 3 ? 9
	// 			4 12 ? ? ? 
	// right row1 2 1 0
	// left row1  0 1 2
	// right row2 3  2 1 0
	// left row2  0  1 2 3

	for (int i = 0; i < first_intRow.size(); ++i)
	{
		int first_Num = first_intRow[i] ;
		if (first_Num == -1) continue ;

		for (int O = 0; O < second_intRow.size(); ++O)
		{	
			int SecondRowSize = second_intRow.size() ;
			int s_Left = second_Left[SecondRowSize-O-1] ; // number of left digits of the second number.
			int second_Num = second_intRow[SecondRowSize-O-1];
			if (second_Num == -1)
			{
				//resultLeft.push_back(first_Left[i]) ;
				continue ;
			} else if (second_Num <= first_Num)
			{
				//first_Left[i] += s_Left + 1 ; // + 1 is that number it self.
				cout << "for " << first_Num << " adding " <<  s_Left + 1 << " to left from " << second_Num << endl ;
				cout << "resultLeft at index " << i << " number " << first_Num << " is " << first_Left[i] + s_Left + 1 << endl ;
				resultLeft.push_back(first_Left[i] + s_Left + 1) ;
				break ;
			} else if (O == SecondRowSize-1)
			{
				resultLeft.push_back(first_Left[i]) ;
			}
			//cout << "TEST NO doing this shit" << endl ; // TESTDEBUG
			//resultLeft.push_back(first_Left[i]) ;
		}
	}

	first_Left = resultLeft ;
	cout << resultLeft.size() << " LEFT LIST SIZE" << endl ; 
}

// basically extracts any remaining right values from the other row input to help in finding median
void ref_getRestOfRight(vector<int> & first_Right, vector<int> first_intRow, vector<int> second_intRow, vector<int> second_Right) 
{
	vector<int> resultRight ;

	for (int i = 0; i < first_intRow.size(); ++i)
	{
		int first_Num = first_intRow[i] ;
		if (first_Num == -1) continue ;

		for (int O = 0; O < second_intRow.size(); ++O)
		{	
			int SecondRowSize = second_intRow.size() ;
			int s_Right = second_Right[O] ; // number of Right digits of the second number.
			int second_Num = second_intRow[O];
			if (second_Num == -1)
			{
				//resultRight.push_back(first_Right[i]) ;
				continue ;
			} else if (second_Num >= first_Num)
			{
				//first_Right[i] += s_Right + 1 ; // + 1 is that number it self.
				cout << "for " << first_Num << " adding " <<  s_Right + 1 << " to right from " << second_Num << endl ;
				cout << "resultRight at index " << i << " number " << first_Num << " is " << first_Right[i] + s_Right + 1 << endl ;
				resultRight.push_back(first_Right[i] + s_Right + 1) ;
				break ;
			} else if (O == SecondRowSize-1)
			{
				resultRight.push_back(first_Right[i]) ;
			}
			//cout << "TEST NO doing this other shit 2" << endl ; // TESTDEBUG
			//resultRight.push_back(first_Right[i]) ;
		}
	}

	first_Right = resultRight ;
	cout << resultRight.size() << " RIGHT LIST SIZE" << endl ;
}

vector<int> ref_getInitialLeft (stringVector row)  
{
	vector<int> leftVals;

	for (int i = 0; i < row.size(); ++i)
	{
		leftVals.push_back(i) ;
	}

	return leftVals;
}

vector<int> ref_getInitialRight (stringVector row)  
{
	vector<int> rightVals;

	for (int i = 0; i < row.size(); ++i)
	{
		rightVals.push_back(row.size() - i - 1);
	}

	return rightVals;
}

stringVector ref_getInputData(stringVector &row1, stringVector &row2)
{
	stringVector combinedRows ;

	int width ;
	cin >> width ;
	for (int i = 0; i < width; ++i)
	{
		string numba ;
		cin >> numba ;

		row1.push_back(numba) ;
		combinedRows.push_back(numba) ;
	}

	cin >> width ;
	for (int i = 0; i < width; ++i)
	{
		string numba ;
		cin >> numba ;

		row2.push_back(numba) ;
		combinedRows.push_back(numba) ;
	}

	return combinedRows ;
}