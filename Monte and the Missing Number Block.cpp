
/****************************************************************

	       File: Monte and the Missing Number Block.cpp
	     Author: Yehya Awad
	     E-mail: yha5009@psu.edu
	   Due Date: 25th May 2014
	Description: Description: You have a set of N blocks, where each block contains a 
		unique integer greater than 0 and less than or equal to N. You like to 
		line them up on the floor to create the sequence 1, 2, 3, …, (N - 1), N. 
		However your cat Monte also likes to play with these blocks and 
		randomly steals and hides one and only one block and then rearranges 
		the remaining blocks in order to hide his crime. You need to write a 
		program to determine which number is missing from the sequence.

	https://www.hackerrank.com/contests/psh-qualifying-contest-spring-2015/challenges/monte-and-the-missing-number-block
*****************************************************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio (false);  

    std::vector<int> nums;
    int M ;
    cin >> M ;

    int inputSum = 0;

    for (int i = 0; i < M; ++i)
    {
    	int currnum = 0 ;
    	cin >> currnum ;

    	inputSum += currnum ;
    }

    M++ ;
    int sum = ((M*(M+1))/2) ; // sum formuala for intergers from 1 to M

    cout << sum - inputSum ;

    return 0;
}
