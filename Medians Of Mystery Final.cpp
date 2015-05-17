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
typedef vector<int> intVecTy ;


//////////////////////
///// Prototypes /////
//////////////////////

void PrintLeftRightVals(intVecTy rowInts, intVecTy left, intVecTy right);
intVecTy stringVecTOint(stringVector arg_stringVec);
intVecTy ref_getRestOfLeft(intVecTy a, intVecTy b, intVecTy c, intVecTy d) ;
intVecTy ref_getRestOfRight(intVecTy a, intVecTy b, intVecTy c, intVecTy d) ;
intVecTy ref_getInitialLeft (stringVector row)  ;
intVecTy ref_getInitialRight (stringVector row)  ;
stringVector ref_getInputData(stringVector &row1, stringVector &row2) ;
bool PrintMysteryMedian(intVecTy intRow, intVecTy RowLeft, intVecTy RowRight, int totalSize) ;
bool isRepeatedCase(intVecTy intRow1, intVecTy intRow2) ;
stringVector correctForBlum(stringVector arg_stringVec);

////////////////
///// Main /////
////////////////


int main() 
{
	
	long int row1Width, row2Width ;

	stringVector row1, row2, combinedRows;
	vector <int> left1, right1, left2, right2, intRow1, intRow2;
	string currentString ;
	// cout << "TEST NO 1" << endl ; // TESTDEBUG
	combinedRows = ref_getInputData(row1, row2) ;
	row1 = correctForBlum(row1) ;
	row2 = correctForBlum(row2) ;
	// cout << "TEST NO 2" << endl ; // TESTDEBUG
	intRow1 = stringVecTOint(row1) ;
	intRow2 = stringVecTOint(row2) ;
	// cout << "TEST NO 3" << endl ; // TESTDEBUG
	row1Width = row1.size(); 
	row2Width = row2.size() ; // getting widths
	// cout << "TEST NO 4" << endl ; // TESTDEBUG
	left1 = ref_getInitialLeft(row1) ;
	right1 = ref_getInitialRight(row1) ;
	left2 = ref_getInitialLeft(row2) ;
	right2 = ref_getInitialRight(row2) ;
	// cout << "TEST NO 5" << endl ; // TESTDEBUG
	// PrintLeftRightVals(intRow1, left1, right1) ; // testing purposes, prints l - num - r
	// PrintLeftRightVals(intRow2, left2, right2) ; // testing purposes, prints l - num - r
	// for row1
	intVecTy resultLeft1( ref_getRestOfLeft(left1, intRow1, intRow2, left2) );
	intVecTy resultRight1( ref_getRestOfRight(right1, intRow1, intRow2, right2) );
	//resultLeft1 = ref_getRestOfLeft(resultLeft1, intRow1, intRow1, left1) ;
	//resultRight1 = ref_getRestOfRight(resultRight1, intRow1, intRow1, right1) ;
	// PrintLeftRightVals(intRow1, resultLeft1, resultRight1) ;
	// for row2
	intVecTy resultLeft2( ref_getRestOfLeft(left2, intRow2, intRow1, left1) );
	intVecTy resultRight2( ref_getRestOfRight(right2, intRow2, intRow1, right1) );
	//resultLeft2 = ref_getRestOfLeft(resultLeft2, intRow2, intRow2, left2) ;
	//resultRight2 = ref_getRestOfRight(resultRight2, intRow2, intRow2, right2) ;
	// PrintLeftRightVals(intRow2, resultLeft2, resultRight2) ;
	// cout << "TEST NO 6" << endl ; // TESTDEBUG
	 PrintLeftRightVals(intRow1, resultLeft1, resultRight1) ; // testing purposes, prints l - num - r
	 PrintLeftRightVals(intRow2, resultLeft2, resultRight2) ; // testing purposes, prints l - num - r

	if (PrintMysteryMedian(intRow1, resultLeft1, resultRight1, intRow1.size()+intRow2.size()))
	{
		exit(0) ;
	} else if (PrintMysteryMedian(intRow2, resultLeft2, resultRight2, intRow1.size()+intRow2.size()))
	{
		exit(0) ;
	}
	// Special case where a number is repeated more than half the number of digitis
	else if (isRepeatedCase(intRow1, intRow2))
	{
		exit(0) ;
	}
	cout << "Unknown" ;
	return 0;
}


///////////////////////////
///// Other Functions /////
///////////////////////////

// Blum's test case that broke my code :C // FIXING IT NOW
// 5 8 ? ? ? 8
// 4 ? ? ? ?
stringVector correctForBlum(stringVector arg_stringVec)
{
	string lastNum = "" ;
	int countsINBetween = 0 ;
	for (int countI = 0; countI < arg_stringVec.size(); ++countI)
	{
		string currentNum = arg_stringVec[countI] ;
		if (currentNum == "?")  
		{
			countsINBetween++;
			continue ;
		} else if (lastNum == currentNum)
		{
			for (int countK = 1; countK <= countsINBetween; ++countK)
			{
				arg_stringVec[countI-countK] = currentNum ;
			}
			countsINBetween = 0 ;

		} else 
		{
			countsINBetween = 0 ;
			lastNum = currentNum ;
		}
	}

	return arg_stringVec ;
}

bool isRepeatedCase(intVecTy intRow1, intVecTy intRow2)
{
	int half = (intRow1.size()+intRow2.size()) /2 ;
	for (int countI = 0; countI < intRow1.size(); ++countI)
	{
		int number = intRow1[countI] ;
		int repetitions = 0 ;
		if (number == -1) continue ;
		for (int countK = 0; countK < intRow1.size(); ++countK)
		{
			if (number == intRow1[countK]) repetitions++ ;
		}
		for (int countK = 0; countK < intRow2.size(); ++countK)
		{
			if (number == intRow2[countK]) repetitions++ ;
		}
		if (repetitions >= half ) {cout << number << endl ; return true ;}
	}

	for (int countI = 0; countI < intRow2.size(); ++countI)
	{
		int number = intRow2[countI] ;
		int repetitions = 0 ;
		if (number == -1) continue ;
		for (int countK = 0; countK < intRow1.size(); ++countK)
		{
			if (number == intRow1[countK]) repetitions++ ;
		}
		for (int countK = 0; countK < intRow2.size(); ++countK)
		{
			if (number == intRow2[countK]) repetitions++ ;
		}
		if (repetitions >= half ) {cout << number << endl ; return true ;}
	}

	return false ;
}

bool PrintMysteryMedian(intVecTy intRow, intVecTy RowLeft, intVecTy RowRight, int totalSize) 
{
    int half = totalSize/2 ;
    // changed nothing when submitted
    for (int i = 0; i < intRow.size(); ++i)
	{	
		int number = intRow[i] ;
		if (RowLeft[i] >= half && RowRight[i] >= half && RowLeft[i] <= half+1 && RowRight[i] <= half+1 )
		{
			cout << number ;
			return true ;
		}
	}

	for (int i = 0; i < intRow.size(); ++i)
	{	
		int number = intRow[i] ;
		if (RowLeft[i] >= half && RowRight[i] >= half)
		{
			cout << number ;
			return true ;
		}
	}
	return false ;
}

void PrintLeftRightVals(intVecTy rowInts, intVecTy leftVals, intVecTy rightVals)
{
	for (int i = 0; i < rowInts.size(); ++i)
	{
		if (rowInts[i] == -1) continue ;
		cout << leftVals[i] << "\t - \t" << rowInts[i] <<  "\t - \t" << rightVals[i] << endl ;
	}
	cout << endl ;
}

intVecTy stringVecTOint(stringVector arg_stringVec)
{
	intVecTy intVector ;
	for (int i = 0; i < arg_stringVec.size(); ++i)
	{
		if (arg_stringVec[i] != "?")
		{
            int convertedNum = stoi(arg_stringVec[i], NULL, 10) ;
			intVector.push_back(convertedNum);
            // Special case, when 0, then all numbers before it are also 0.
            if (convertedNum == 0)
            {
            	for (int countK = 0; countK < i; ++countK)
            	{
            		intVector[countK] = 0 ;
            	}
            }
		} else 
		{
			intVector.push_back(-1) ; // -1 , meaning ? mark
		}
	}

	return intVector ;
}

// basically extracts any remaining left values from the other row input to help in finding median
intVecTy ref_getRestOfLeft(intVecTy first_Left, intVecTy first_intRow, intVecTy second_intRow, intVecTy second_Left) 
{
	intVecTy resultLeft ;

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
		// cout << "Starting to find rest of left for: " << first_Num << endl ;
		if (first_Num == -1) 
		{
			resultLeft.push_back(-1);
			continue ;
		}
		for (int O = 0; O < second_intRow.size(); ++O)
		{	
			// cout << "In O Loop" << endl ;
			int SecondRowSize = second_intRow.size() ;
			int s_Left = second_Left[SecondRowSize-O-1] ; // number of left digits of the second number.
			int second_Num = second_intRow[SecondRowSize-O-1];
			// cout << "\t Now at: " << second_Num << endl ;
			if (second_Num == -1 && O == SecondRowSize-1)
			{
				//cout << "\t\t" << second_Num << " is a ?" << endl ;
				resultLeft.push_back(first_Left[i]) ;
				continue ;
			} else if (second_Num == -1)
			{
				continue ;
			} else if (second_Num <= first_Num)
			{
				// cout << "\t\t" << second_Num << " is the one we use." << endl ;
				//first_Left[i] += s_Left + 1 ; // + 1 is that number it self.
				// cout << "for " << first_Num << " adding " <<  s_Left + 1 << " to left from " << second_Num << endl ;
				// cout << "resultLeft at index " << i << " number " << first_Num << " is " << first_Left[i] + s_Left + 1 << endl ;
				resultLeft.push_back(first_Left[i] + s_Left + 1) ;
				break ;
			} else if (O == SecondRowSize-1) 
			{
				resultLeft.push_back(first_Left[i]) ;
			}
			//cout << "TEST NO doing this shit" << endl ; // TESTDEBUG
			//resultLeft.push_back(first_Left[i]) ;
		}

		// cout << "Got left for " << first_Num << " as: " << resultLeft[i] << endl ;
	}

	// cout << "Printing Results of RestOfLeft: " ;
	// for (int i = 0; i < resultLeft.size(); ++i)
	// {
	// 	cout << resultLeft[i] << ", " ;
	// }
	// cout << endl ;

	return resultLeft ;
	// cout << resultLeft.size() << " LEFT LIST SIZE" << endl ; 
}

// basically extracts any remaining right values from the other row input to help in finding median
intVecTy ref_getRestOfRight(intVecTy first_Right, intVecTy first_intRow, intVecTy second_intRow, intVecTy second_Right) 
{
	intVecTy resultRight ;

	for (int i = 0; i < first_intRow.size(); ++i)
	{
		int first_Num = first_intRow[i] ;
		if (first_Num == -1) 
		{
			resultRight.push_back(-1);
			continue ;
		}
		for (int O = 0; O < second_intRow.size(); ++O)
		{	
			int SecondRowSize = second_intRow.size() ;
			int s_Right = second_Right[O] ; // number of Right digits of the second number.
			int second_Num = second_intRow[O];
			if (second_Num == -1 && O == SecondRowSize-1)
			{
				resultRight.push_back(first_Right[i]) ;
				continue ;
			} else if ( second_Num == -1 )
			{
				continue ;
			}
			else if (second_Num >= first_Num)
			{
				//first_Right[i] += s_Right + 1 ; // + 1 is that number it self.
				// cout << "for " << first_Num << " adding " <<  s_Right + 1 << " to right from " << second_Num << endl ;
				// cout << "resultRight at index " << i << " number " << first_Num << " is " << first_Right[i] + s_Right + 1 << endl ;
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

	return resultRight ;
	// cout << resultRight.size() << " RIGHT LIST SIZE" << endl ;
}

intVecTy ref_getInitialLeft (stringVector row)  
{
	intVecTy leftVals;

	for (int i = 0; i < row.size(); ++i)
	{
		leftVals.push_back(i) ;
	}

	return leftVals;
}

intVecTy ref_getInitialRight (stringVector row)  
{
	intVecTy rightVals;

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