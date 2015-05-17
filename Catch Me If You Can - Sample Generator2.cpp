#include <cmath>
#include <math.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

// Sample generator for Catch Me If You Can

int main() {

	int Width = 10 ;
	int Height = 10 ;

	int posX = 0 ;
	int posY = 0 ;

	srand(time(NULL)) ;

	int howOften = 40 ; // out of 100

	cout << 4 << endl ;

	for (int count = 0; count < 4 ; ++count)
	{	
		for (int countH = 0; countH < Width; ++countH)
		{
			for (int countW = 0; countW < Height; ++countW)
			{
				if (rand()%100 < howOften)
				{
					cout << 1 ;
				} else 
				{
					cout << 0 ;
					if (countW > Width/2 && countH > Height/2)
					{
						if (posX == 0 && posY == 0) 
						{
							posX = countW+1 ;
							posY = countH+1 ;
						}
					}
				}
			}
			cout << endl ;
		}

		cout << endl ;

		cout << posX << " " << posY << endl ;
	}
	return 0;
}