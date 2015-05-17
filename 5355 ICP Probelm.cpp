
/****************************************************************

	       File: 
	     Author: Yehya Awad
	     E-mail: yha5009@psu.edu
	   	   Date: 23 Feb 2015
	Description: 5355 ICP Problem - Baudot Data Communication Code

*****************************************************************/

#include <iostream>
#include <string>
using namespace std;

//prototypes
int binaryToDecimal(string binaryVal) ;


int main() {
	char upshift_list[33] ;
	char downshift_list[33] ;

	// setup
	cin.getline(downshift_list,33) ;	
	cin.getline(upshift_list,33) ;	
	//cout << downshift_list << endl << upshift_list ;
	string input ;
	bool isDownShift = true ; // initial setting. When false = upshift


	// everyline of bits will loop
	while(cin >> input) {
		string currentPattern ; // will hold one set of bits for use
		int decimalVals[16] ; // will hold the converted decimal values of every character

		for (int i = 0; i < input.length()/5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				string bit(1,input.at(i*5 + j)) ;
				currentPattern.append(bit) ;
			}
			//cout << currentPattern << endl ;
			//decimalVals[i] = binaryToDecimal(currentPattern) ;

			if (currentPattern == "11111")
			{
				isDownShift = false ;
			} else if (currentPattern == "11011")
			{
				isDownShift = true ;
			} else {
				if (isDownShift)
				{
					cout << downshift_list[binaryToDecimal(currentPattern)] ;
				} else {
					cout << upshift_list[binaryToDecimal(currentPattern)] ;					
				}
			}
			//cout << decimalVals[i] << endl ;
			currentPattern.clear() ;
		}
		cout << endl ;
		isDownShift = true ;
	}

}

int binaryToDecimal(string binaryVal) {
	return stoi(binaryVal,nullptr,2) ;
}



