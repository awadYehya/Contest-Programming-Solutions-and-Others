
/****************************************************************
Project Euler #2: Even Fibonacci numbers

	       File: 
	     Author: Yehya Awad
	     E-mail: yha5009@psu.edu
	   Due Date: March 22, 2015
	Description: Each new term in the Fibonacci sequence is generated
	 by adding the previous two terms. By starting with 1 and 2, the 
	 first 10 terms will be:

	1,2,3,5,8,13,21,34,55,89, ...

	By considering the terms in the Fibonacci sequence whose values do not 
	exceed N, find the sum of the even-valued terms.

https://www.hackerrank.com/contests/projecteuler/challenges/euler002
*****************************************************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define Phi golden_ratio  

int main() 
{
	const double golden_ratio = 1.6180339887498948482; // Phi
	//cout << Phi << endl ;
	long long int T, N ;

	cin >> T ;
	for (int countI = 0; countI < T; ++countI)
	{
		long double sum = 0 ;
		cin >> N ;
		// long int k = floor((log(N*sqrt(5)))/(log(Phi)) + 1/2) ;
		long int k = floor((log(N*sqrt(5) + 1/2))/(log(Phi))) ;
		// double PhiTO3 = pow(Phi,3) ;
		// double PhiTOn3 = pow(Phi,-3) ;
		// double PhiTO3TOK = pow(PhiTO3,k) ;
		// double PhiTOn3TOK = pow(-PhiTOn3,k) ;
		// sum = (PhiTO3*((1- PhiTO3TOK)/(1- PhiTO3))) ;
		// sum = sum + (PhiTOn3*((1- PhiTOn3TOK)/(1 + PhiTOn3))) ;
		// sum = (1/sqrt(5))*sum ;

		for (int countK = 0; countK <= k; countK += 3)
		{
			long double PhiPowCount = pow(Phi,countK) ;
			long double invPhiPowCount = pow(-1/Phi,countK) ;
			long long int val = round((PhiPowCount- invPhiPowCount)/(sqrt(5))) ;
			sum += val ;
			//cout << val << endl ;
		}

		cout << sum << endl ;
		// Now finding using Formula.
		//sum = (1/sqrt(5))*((Phi)*((1-pow(pow(Phi,3),N))))
	}

    return 0;
}
