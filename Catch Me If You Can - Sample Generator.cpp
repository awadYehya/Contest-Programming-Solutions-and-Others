#include <cmath>
#include <math.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

// Sample generator for Catch Me If You Can

int main() {
	// string cities[7] = {"NewYork", "Miami", "Boston", "Cairo", "Jeddah", 
	// "Moscow", "London", "Orlando", "Mumbai", "LosAngel", "Seattle", "Riyadh"} ;

	int cities[500] ;

	for (int i = 0; i < 500; ++i)
	{
		cities[i] = i ;
	}

	string modes[5] = {"taxi", "bus", "train", "airplane", "ferry"} ;

	int count = 0;

	srand(time(NULL)) ;

	for (int i = 0; i < 10; ++i)
	{
		for (int k = 0; k < 100; ++k)
		{
			if (i == k)
			{
				continue ; // skips when end city = start city
			}
			for (int o = 0; o < 5; ++o)
			{
				if (int(rand())%4 == 0) // randomly removes some modes of transport
				{
					++count;
					cout << modes[o] << " " ;
					cout << "CityID-" << cities[i] << " " << "CityID-" << cities[k] << " " ;
				}
				
			}
		}
	}

	cout << count ;
	return 0;
}