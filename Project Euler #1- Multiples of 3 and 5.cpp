
/****************************************************************

	       File: Project Euler #1- Multiples of 3 and 5
	     Author: Yehya Awad
	     E-mail: yha5009@psu.edu
	   Due Date: March 16th 2015
	Description: If we list all the natural numbers below 10 that are 
	multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below N.

https://www.hackerrank.com/contests/projecteuler/challenges/euler001
*****************************************************************/



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
	long int T ;
	cin >> T ;
	long int N ;
	// 3(3+9)/2
	// 2(0+15)/2
	// 0(0+5)/2

	// 100%3 = 1
	// 100 - 1 = 99
	// 99/3 = 33
	// 33(3+99)/2 = 198
	// For fives
	// 100%5 = 0
	// 100 - 0 = 100
	// 100/5 = 20 
	// 20(5+100)/2 = 1050
	// For fifteen


	for (int countI = 0; countI < T; ++countI)
	{
		cin >> N ;
		long long int sum3 = 0 ;
		long long int sum15 = 0 ;
		long long int sum5 = 0 ;

		int Zemod3 = N - N%3 ;
        // cout << "Zemod3 is " << Zemod3 << endl ;
		int Zemod15 = N - N%15 ;
        // cout << "Zemod15 is " << Zemod15 << endl ;
		int Zemod5 = N - N%5 ;
        // cout << "Zemod5 is " << Zemod5 << endl ;

		long int N3 = (N)/3 ;
		// cout << "N3 is " << N3 << endl ;
		long int N15 = (N)/15 ;
		// cout << "N15 is " << N15 << endl ;
		long int N5 = (N)/5 ;
		// cout << "N5 is " << N5 << endl ;

		sum3 = (N3*(3+Zemod3))/2 ;
        // cout << "sum3 is " << sum3 << endl ;
		sum15 = (N15*(15+Zemod15))/2 ;
        // cout << "sum15 is " << sum15 << endl ;
		sum5 = (N5*(5 + Zemod5))/2 ;
        // cout << "sum5 is " << sum5 << endl ;

		long long int sum = sum3-sum15+sum5 ;

		cout << sum << endl ;

		// cout << "NNNEEEEEEEEEEEEEEEEEEEEXT <<<" << endl ;
		
	}
//
    return 0;
}
