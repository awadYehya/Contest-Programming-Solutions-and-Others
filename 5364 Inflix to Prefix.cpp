
/****************************************************************

	       File: 5364 Inflix to Prefix.cpp
	     Author: Yehya Awad
	     E-mail: yha5009@psu.edu
	   Due Date: 26th May 2014
	Description: Inflix to Postfix
	
	Example: Convert any inflix string to it's postfix string version
				Input 			Output
				A+B*C -------->	ABC*+ 
*****************************************************************/


#include <iostream>
#include <math.h>

using namespace std;

// Prototypes
string InflixToPrefix(string inflix) ;
bool PushOrPop(char input, char stackTop) ;

int main() 
{
	int numTestCases = 0 ;

	cin >> numTestCases ; //------------------ Getting first number of test cases
	cin.get() ; //---------------------------- skip 1 line
	for (int p = 0; p < numTestCases; ++p)
	{
		string input ;
		for (int k = 0; k < 50; ++k)
		{
			input.append(const cin.get()) ;
			if ( input.at(k) == '\n')
			{
				break ;
			}
		}
		InflixToPrefix(input) ;
		input.clear() ;
	}
	return 0;
}

string InflixToPrefix(string inflix) 
{
	stack <char> operators ; // will be used to handle placement of operators
	string result ;

	for (int i = 0; i < 50; ++i)
	{
		char currentChar = inflix.at(i);
		switch (currentChar)
		{
			case '/':
			case '*':
			case '+':
			case '-':
				// if true, we push, if false, we pop
				if (operators.empty() || PushOrPop(currentChar,operators.top()))
				{
					operators.push(currentChar) ;

				} else // pop what's in the stack, and push current char.
				{
					result.append(operators.pop());
					operators.push(currentChar) ;
				}
				break ;
			default:
				result.append(currentChar) ;

		}
	}
}

bool PushOrPop(char input, char stackTop) {
	
	int inputPower = 0 ;
	int StackTopPower = 0 ;
	// checking which char is more prescedent
	switch (input) 
	{
		case '(':
			return true ; // aka push
		case ')':
			return false ; // aka pop
		case '/':
		case '*':
			inputPower = 2 ;
			break ;
		case '+':
		case '-':
			inputPower = 1 ;
			break ;
	}

	switch (stackTop) 
	{
		case '(':
			return true ; // aka push
		case ')':
			return false ; // aka pop
		case '(':
		case '/':
		case '*':
			StackTopPower = 2 ;
			break ;
		case '+':
		case '-':
			StackTopPower = 1 ;
			break ;
	}


}


