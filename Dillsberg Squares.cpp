
/****************************************************************

	       File: Dillsberg Squares.cpp
	     Author: Yehya Awad
	     E-mail: yha5009@psu.edu
	   Due Date: 28th Feb 2015
	Description: 	The town of Dillsburg, PA has decided to sell all of its 
		community properties. Since all of the properties are perfect squares,
		the Dillsburg town council decided to simply break each square into 
		multiple lots, were each lot is also a square. For example, there is 
		one community property called Dill1 that has been divided into 16 
		square lots as follows:

		Linda and Tim want to buy multiple lots, but Dillsburg has mandated 
		that all purchases must also be squares. They decide to buy 9 lots in 
		Dill1, but now realize they have 4 choices in how they buy their 9 lots:
		You are to write a program that will calculate the number of choices 
		that Tim and Linda have, given they want to buy L lots on 
		a parcel of land of size N lots.

	https://www.hackerrank.com/contests/psh-qualifying-contest-spring-2015/challenges/dillsberg-squares
*****************************************************************/

#include <cmath>
#include <math.h>
#include <cstdio>
#include <iostream>
using namespace std;

// So...
// land 16 - sqrt 4
// lots 1 - sqrt 1 - result 16
// lots 4 - sqrt 2 - result 9
// lots 9 - sqrt 3 - result 4
// lots 16 - sqr 4 - result 1

int main() {

    int land ;
    cin >> land ;
	int lots;
    cin >> lots ;

    int sqrtOfLand = int(sqrt(double(land)));
    int sqrtOfLots = int(sqrt(double(lots)));

    int result = pow(sqrtOfLand + 1 - sqrtOfLots,2) ;

    cout << result ;
    return 0;
}
