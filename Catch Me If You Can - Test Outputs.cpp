
/****************************************************************

	       File: 
	     Author: Yehya Awad
	     E-mail: yha5009@psu.edu
	   Due Date: 28th Feb 2015
	Description: Samples

*****************************************************************/


////////////////////////////////////////////////////////////
///// SAMPLE TEST INPUTS/OUTPUTS - CATCH ME IF YOU CAN /////
////////////////////////////////////////////////////////////


/////////////////
///// INPUT /////
/////////////////

13
taxi Carlisle Harrisburg
airplane Harrisburg Baltimore
bus Harrisburg York
ferry Harrisburg Millersburg
taxi Harrisburg Carlisle
taxi Harrisburg York
train Harrisburg Lancaster
bus York Baltimore
bus York Harrisburg
airplane Baltimore Harrisburg
bus Baltimore York
ferry Millersburg Harrisburg
train Lancaster Harrisburg
4
Carlisle taxi ferry ferry airplane bus stop
Carlisle taxi bus bus stop
Harrisburg stop
Lancaster ferry bus stop
 

//////////////////
///// OUTPUT /////
//////////////////

// With the debug outputs on

Route: Carlisle	 ---> 	Harrisburg using modeID 0
Route: Harrisburg	 ---> 	Carlisle using modeID 0
Route: Harrisburg	 ---> 	York using modeID 0
Route: Harrisburg	 ---> 	Baltimore using modeID 1
Route: Harrisburg	 ---> 	York using modeID 2
Route: Harrisburg	 ---> 	Millersburg using modeID 3
Route: Harrisburg	 ---> 	Lancaster using modeID 4
Route: York	 ---> 	Baltimore using modeID 2
Route: York	 ---> 	Harrisburg using modeID 2
Route: Baltimore	 ---> 	Harrisburg using modeID 1
Route: Baltimore	 ---> 	York using modeID 2
Route: Millersburg	 ---> 	Harrisburg using modeID 3
Route: Lancaster	 ---> 	Harrisburg using modeID 4
TEST NO 1
TEST NO 2 loop, starting problem 0
TEST NO solveProblem 1
At Carlisle travelled, 0 times by taxi
At Harrisburg travelled, 1 times by ferry
At Millersburg travelled, 2 times by ferry
At Harrisburg travelled, 3 times by airplane
At Baltimore travelled, 4 times by bus
At York travelled, 5 times by stop
York  found!
Back from York route. 1
Back from Baltimore route. 1
Back from Harrisburg route. 1
Back from Millersburg route. 1
Back from Harrisburg route. 1

TEST NO 2 loop, starting problem 1
TEST NO solveProblem 1
At Carlisle travelled, 0 times by taxi
At Harrisburg travelled, 1 times by bus
At York travelled, 2 times by bus
At Baltimore travelled, 3 times by stop
Baltimore  found!
Back from Baltimore route. 1



/////////////////
///// FINAL /////
/////////////////


/////////////////
///// INPUT /////
/////////////////

Same as above

//////////////////
///// OUTPUT /////
//////////////////

Route: Carlisle	 ---> 	Harrisburg using modeID 0
Route: Harrisburg	 ---> 	Carlisle using modeID 0
Route: Harrisburg	 ---> 	York using modeID 0
Route: Harrisburg	 ---> 	Baltimore using modeID 1
Route: Harrisburg	 ---> 	York using modeID 2
Route: Harrisburg	 ---> 	Millersburg using modeID 3
Route: Harrisburg	 ---> 	Lancaster using modeID 4
Route: York	 ---> 	Baltimore using modeID 2
Route: York	 ---> 	Harrisburg using modeID 2
Route: Baltimore	 ---> 	Harrisburg using modeID 1
Route: Baltimore	 ---> 	York using modeID 2
Route: Millersburg	 ---> 	Harrisburg using modeID 3
Route: Lancaster	 ---> 	Harrisburg using modeID 4
TEST NO 1
TEST NO 2 loop, starting problem 0
TEST NO solveProblem 1
At Carlisle travelled, 0 times by taxi
Possible Routes at Carlisle mode taxi are 1
In this loop 0
After nextStart Harrisburg with modeIndex 0
At Harrisburg travelled, 1 times by ferry
Possible Routes at Harrisburg mode ferry are 1
In this loop 0
After nextStart Millersburg with modeIndex 1
At Millersburg travelled, 2 times by ferry
Possible Routes at Millersburg mode ferry are 1
In this loop 0
After nextStart Harrisburg with modeIndex 2
At Harrisburg travelled, 3 times by airplane
Possible Routes at Harrisburg mode airplane are 1
In this loop 0
After nextStart Baltimore with modeIndex 3
At Baltimore travelled, 4 times by bus
Possible Routes at Baltimore mode bus are 1
In this loop 0
After nextStart York with modeIndex 4
At York travelled, 5 times by stop
York  found!
Back from York route. 1
Back from Baltimore route. 1
Back from Harrisburg route. 1
Back from Millersburg route. 1
Back from Harrisburg route. 1

TEST NO 2 loop, starting problem 1
TEST NO solveProblem 1
At Carlisle travelled, 0 times by taxi
Possible Routes at Carlisle mode taxi are 1
In this loop 0
After nextStart Harrisburg with modeIndex 0
At Harrisburg travelled, 1 times by bus
Possible Routes at Harrisburg mode bus are 1
In this loop 0
After nextStart York with modeIndex 1
At York travelled, 2 times by bus
Possible Routes at York mode bus are 2
In this loop 0
After nextStart Baltimore with modeIndex 2
At Baltimore travelled, 3 times by stop
Baltimore  found!
Back from Baltimore route. 1
In this loop 1
After nextStart Harrisburg with modeIndex 2
At Harrisburg travelled, 3 times by stop
Harrisburg  found!
Back from Harrisburg route. 1
Back from York route. 1
Back from Harrisburg route. 1

TEST NO 2 loop, starting problem 2
TEST NO solveProblem 1
At Harrisburg travelled, 0 times by stop
Harrisburg  found!

TEST NO 2 loop, starting problem 3
TEST NO solveProblem 1
At Lancaster travelled, 0 times by ferry
No route found from Lancaster for ferry
Impossible



//////////////////////////////////
///// GENERATED SAMPLE INPUT /////
//////////////////////////////////

66
bus NewYork Harrisburg
ferry NewYork Harrisburg
bus NewYork LosAngeles
train NewYork LosAngeles
airplane NewYork LosAngeles
bus NewYork Cairo
train NewYork Jeddah
ferry NewYork Jeddah
bus NewYork Moscow
bus NewYork London
airplane NewYork London
ferry NewYork London
ferry Harrisburg NewYork
taxi Harrisburg LosAngeles
bus Harrisburg LosAngeles
airplane Harrisburg LosAngeles
train Harrisburg Jeddah
airplane Harrisburg Jeddah
train Harrisburg Moscow
taxi Harrisburg London
taxi LosAngeles NewYork
bus LosAngeles NewYork
ferry LosAngeles NewYork
taxi LosAngeles Harrisburg
bus LosAngeles Cairo
train LosAngeles Jeddah
taxi LosAngeles Moscow
ferry LosAngeles Moscow
train Cairo NewYork
airplane Cairo Harrisburg
airplane Cairo LosAngeles
ferry Cairo Jeddah
ferry Cairo Moscow
taxi Jeddah NewYork
train Jeddah NewYork
bus Jeddah Harrisburg
airplane Jeddah Harrisburg
taxi Jeddah LosAngeles
train Jeddah LosAngeles
ferry Jeddah LosAngeles
taxi Jeddah Cairo
bus Jeddah Cairo
train Jeddah Cairo
train Jeddah Moscow
airplane Jeddah Moscow
ferry Jeddah Moscow
bus Jeddah London
taxi Moscow NewYork
airplane Moscow NewYork
ferry Moscow NewYork
train Moscow LosAngeles
taxi Moscow Cairo
taxi Moscow Jeddah
taxi Moscow London
taxi London NewYork
ferry London NewYork
bus London Harrisburg
train London LosAngeles
airplane London LosAngeles
taxi London Cairo
bus London Cairo
ferry London Cairo
taxi London Jeddah
taxi London Moscow
train London Moscow
airplane London Moscow
5
London taxi taxi bus bus stop
Cairo taxi bus airplane stop
London airplane bus taxi stop
Moscow taxi stop
Jeddah bus taxi ferry stop


//////////////////////////
///// SAMPLE INPUT 2 /////
//////////////////////////

33
airplane NewYork Miami
train NewYork Boston
ferry NewYork Boston
airplane NewYork Cairo
taxi NewYork Jeddah
train NewYork Jeddah
bus NewYork Moscow
taxi Miami NewYork
taxi Miami Boston
ferry Miami Cairo
bus Miami London
airplane Miami London
airplane Boston Miami
train Boston London
train Cairo NewYork
ferry Cairo NewYork
train Cairo Jeddah
ferry Cairo London
taxi Jeddah NewYork
train Jeddah NewYork
taxi Jeddah Miami
bus Jeddah Miami
train Jeddah Miami
ferry Jeddah Cairo
taxi Moscow Boston
ferry Moscow London
bus London Miami
airplane London Miami
bus London Boston
ferry London Boston
airplane London Jeddah
airplane London Moscow
ferry London Moscow
6
NewYork ferry stop
Jeddah taxi bus stop
Cairo train ferry bus stop
London bus airplane taxi stop
Moscow ferry bus stop
Cairo taxi taxi stop
