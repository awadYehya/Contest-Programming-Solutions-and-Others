
/****************************************************************

	       File: Utopian Tree.cpp
	     Author: Yehya Awad
	     E-mail: yha5009@psu.edu
	   Due Date: 1 March 2015
	Description: The Utopian Tree goes through 2 cycles of growth every year. 
	The first growth cycle occurs during the spring, when it doubles in height. 
	The second growth cycle occurs during the summer, when its height increases by 1 meter. 
	Now, a new Utopian Tree sapling is planted at the onset of spring. 
	Its height is 1 meter. Can you find the height of the tree after N growth cycles?

https://www.hackerrank.com/challenges/utopian-tree
*****************************************************************/

#include <iostream>
using namespace std;


int main() {
    int numOfTrees ;
    cin >> numOfTrees ;
    
    for (int i = 0; i < numOfTrees; ++i)
    {
    	int cycles, height = 1 ;
    	cin >> cycles ;

    	for (int k = 0; k < cycles; ++k)
    	{
    		if ((k+1)%2 == 0)
    		{
    			height = height + 1 ;
    		} else {
    			height = height*2 ;
    		}
    	}
    	cout << height << endl ;
    }
}
