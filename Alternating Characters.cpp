
/****************************************************************

	       File: 
	     Author: Yehya Awad
	     E-mail: yha5009@psu.edu
	   Due Date: 1 March 2015
	Description: Shashank likes strings in which consecutive characters are different. 
	For example, he likes ABABA, while he doesn't like ABAA. Given a string containing 
	characters A and B only, he wants to change it into a string he likes. To do this, 
	he is allowed to delete the characters in the string.

	Your task is to find the minimum number of required deletions.

https://www.hackerrank.com/challenges/alternating-characters
*****************************************************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Prototype
int getMinDeletions() ;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T ;
    cin >> T ;
    
    for (int i = 0; i < T; ++i)
    {
    	cout << getMinDeletions() << endl ;
    }
    return 0;
}

int getMinDeletions() {
	string ABs ;
	cin >> ABs ;
	int counter = 0;

	for (int i = 0; i < ABs.size()-1; ++i)
	{
		if (ABs.at(i) == ABs.at(i+1))
		{
			//cout << ABs.at(i) << " and " << ABs.at(i+1) << endl ;
			++counter;
		}
	}
	//cout << counter << endl ;
	return counter ;
}