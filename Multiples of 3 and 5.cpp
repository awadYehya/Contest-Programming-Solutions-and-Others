#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// too slow for large numbers 
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
	long int T ;
	cin >> T ;
	long int N ;

	for (int countI = 0; countI < T; ++countI)
	{//
		cin >> N ;
		long long int sum = 0 ;
		for (int countK = 0; countK*3 < N; ++countK)
		{
			if (countK%5 == 0) continue ;
			//cout << "adding " << countK*3 << endl ;
			sum += countK*3 ;
		}
		
		for (int countK = 0; countK*5 < N; ++countK)
		{
			//cout << "adding " << countK*5 << endl ;
			sum += countI*5 ;
		}
		cout << sum << endl ;
	}

    return 0;
}
