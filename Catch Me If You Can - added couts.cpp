
/****************************************************************

           File: Catch me if you can.cpp
         Author: Yehya Awad
         E-mail: yha5009@psu.edu
       Due Date: 28th Feb 2015
    Description: 

https://www.hackerrank.com/contests/psh-qualifying-contest-spring-2015/challenges/catch-me-if-you-can
*****************************************************************/
/*

modes - taxi, airplane, ferry, train, bus

    
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef vector<vector<string>> VectorVectorString ;
typedef unordered_map<string,VectorVectorString> d_stringmap;
typedef unordered_map<string, int> stringmap;

// prototypes
void initModes (d_stringmap & UniqueRoutes, string start) ;
int getModeID (string mode) ;
bool solveProblem(string start,d_stringmap & UniqueRoutes, stringmap & result, int & numOfRoutesTaken) ;
bool takeRoute(string start, vector<string> & modesList, d_stringmap & UniqueRoutes, int modeIndex, stringmap & result, int & numOfRoutesTaken) ;
string getModeString (int modeID);
bool allCitiesPossible(d_stringmap & UniqueRoutes, stringmap & result) ;

// CAN'T FIGURE OUT A GOOD DATA TYPE
int main() {
   
   d_stringmap UniqueRoutes ; // holds cities, then mode + destination
   // each vector is for the mode, then vector holds destinations
   vector <string> UniqueLocations ; // for testing

   stringmap result ;

   int Routes;
   cin >> Routes ;
   vector<string> destinations ;
   VectorVectorString emptyVecVec ;


   /////////////////////////////////
   ///// Reading in route info /////
   /////////////////////////////////
   
   for (int i = 0; i < Routes; ++i)
   {
       string mode, start, end;
       cin >> mode >> start >> end ;
       int modeID = getModeID(mode) ; // each mode has a number for indexing purposes in the vectorvector

       // Inserting route
       if (UniqueRoutes.count(start) == 0)
       {
            UniqueRoutes.insert({start,emptyVecVec}) ;
            UniqueLocations.push_back(start) ;
            initModes(UniqueRoutes, start) ;
            UniqueRoutes[start][modeID].push_back(end) ;
       } else
       {
            UniqueRoutes[start][modeID].push_back(end) ;
       }
       if (UniqueRoutes.count(end) == 0)
      {
        UniqueRoutes.insert({end,emptyVecVec}) ;
        UniqueLocations.push_back(end) ;
        initModes(UniqueRoutes, end) ;
      }
   }

   // Outputing all of the unique routes (testing to see if it read properly)
   /*
   for (int i = 0; i < UniqueLocations.size(); ++i)
    {
        string start = UniqueLocations[i];
        string end ;

        for (int o = 0; o < 5; ++o)
        {
            for (int k = 0; k < UniqueRoutes[start][o].size(); ++k)
            {
                end = UniqueRoutes[start][o][k] ;
                cout << "Route: " << start << "\t ---> \t" << end << "\t using mode: \t" << getModeString(o) << "\t mode ID \t" << o << endl ;
            }
        }
    }
    cout << endl ; // apart of the test too
    */
    // cout << "TEST NO 1" << endl ; // TESTDEBUG


    /////////////////////////////////////
    ///// Solving provided problems /////
    /////////////////////////////////////
    

    int numOfProblems ;
    cin >> numOfProblems ;

   for (int i = 0; i < numOfProblems; ++i)
   {
        // cout << "TEST NO 2 loop, starting problem " << i << endl ; // TESTDEBUG
       string start ;
       cin >> start ;
       //cout << "Starting at " << start << " let's see if we can follow this route." << endl ;
       int numOfRoutesTaken = 0 ;
       if (solveProblem(start, UniqueRoutes, result) == false, numOfRoutesTaken) 
       {
            cout << "Impossible" << endl ;
       } else {
          vector<string> sortedCities ;
          for (stringmap::iterator it = result.begin(); it != result.end(); ++it)
          {
            sortedCities.push_back(it->first) ;
          }
          sort(sortedCities.begin(), sortedCities.end());
          //cout << "Result contains " << sortedCities.size() << " cities, they are: " << endl; // testing
          for (int o = 0; o < sortedCities.size(); ++o)
          {
            cout << sortedCities[o] << " " ;
          }
          cout << endl ;
          result.clear() ;
          sortedCities.clear();
       }
   }

    return 0;
}


///////////////////////////
///// Other functions /////
///////////////////////////


int getModeID (string mode) {
   if (mode == "taxi") {
        return 0 ;
   }
   else if (mode == "airplane") {
        return 1 ;
   }
   else if (mode == "bus") {
        return 2 ;
   }
   else if (mode == "ferry") {
        return 3 ;
   }
   else if (mode == "train") {
        return 4 ;
   }
    return 0 ;
}

string getModeString (int modeID) {
    switch (modeID) {
        case 0:
            return "taxi" ;
        case 1:
            return "airplane" ;
        case 2:
            return "bus" ;
        case 3:
            return "ferry" ;
        case 4:
            return "train" ;
    }
    return "error" ;
}

void initModes (d_stringmap & UniqueRoutes, string start) {
    vector<string> emptyVec ;
    for (int i = 0; i < 5; ++i)
    {
        // initializing empty mode vector
        UniqueRoutes[start].push_back(emptyVec) ;
    }
}

bool solveProblem(string start,d_stringmap & UniqueRoutes, stringmap & result, int & numOfRoutesTaken) {
    vector<string> modesList ;
    cout << endl << "-------------------------- Solving next problem --------------------------" << endl << endl ; // test
    for (int i = 0; i < 53; ++i)
    {
        string mode;
        cin >> mode; 
        modesList.push_back(mode) ;
        //cout << mode << endl ;
        if (mode == "stop") break ;
    }
    // cout << "TEST NO solveProblem 1" << endl ; // TESTDEBUG
    if (UniqueRoutes.count(start) == 0) return false ;
    return takeRoute(start, modesList, UniqueRoutes, 0, result, ++numOfRoutesTaken);
    return true ; // for compiler warning
}

bool takeRoute(string start, vector<string> & modesList, d_stringmap & UniqueRoutes, int modeIndex, stringmap & result, int & numOfRoutesTaken) {
    //cout << "TEST NO takeRoute" << endl ; // TESTDEBUG
    for (int k = 0; k < modeIndex ; ++k) cout << "|" ;
    cout << "At " << start << " travelled " << modeIndex << " modes by " << modesList[modeIndex] << endl;
    // at the final stop we...
    if (modesList[modeIndex] == "stop") 
    {
        if (result.count(start) == 0)
        {
          result.insert({start,0}) ;
        }
        // cout << " found!" << endl ;
        return true ;
    }
    if (allCitiesPossible(UniqueRoutes,result))
    {
      return true ;
    }
    // Part 1
    //cout << "Part 1" << endl ; // testing
    bool notImpossible = false ;
    int modeID = getModeID(modesList[modeIndex]) ;
    //cout << "Part 1.5" << endl ; // testing
    string nextStart ;
    //cout << "Part 2" << endl ; //testing
    //cout << endl << "Possible Routes at " << start << " mode " << modesList[modeIndex] << " are "; // testing
    //cout << UniqueRoutes[start][modeID].size() << endl ; // testing
    //cout << "They are: " << endl ; // testing

    if (UniqueRoutes[start][modeID].size() == 0) 
    {
        //cout << "No route found from " << start << " for " << modesList[modeIndex] << endl;
        return false;
    }
    
    // for testing, printing out all possible routes,
    // for (int i = 0; i < UniqueRoutes[start][modeID].size(); ++i)
    // {
    //   cout << UniqueRoutes[start][modeID][i] << ", " ;
    // }
    // cout << endl << endl ; // testing

    for (int i = 0; i < UniqueRoutes[start][modeID].size(); ++i)
    {
        // cout << "In this loop " << i << endl ;
        nextStart = UniqueRoutes[start][modeID][i];
        //cout << "After nextStart " << nextStart << " with modeIndex " << modeIndex << endl ;
        if (takeRoute(nextStart, modesList, UniqueRoutes, modeIndex+1, result, ++numOfRoutesTaken))
        {
            notImpossible = true ;

            //cout << notImpossible << "Setting notImpossible to true at " << start << endl ;
        }
        // cout << "Back from " << nextStart << " route. " << notImpossible << endl ;
    }
    cout << "Num of routes taken currently = " << numOfRoutesTaken << endl;
    if (notImpossible == true)
    {
        //cout << "Not Impossible, returning true." << endl ;
        return true ;
    }

    // cout << "Failed, returning false at " << start << endl ;
    return false;
}

bool allCitiesPossible(d_stringmap & UniqueRoutes, stringmap & result) {
  
  bool notFound = false ;
  for (d_stringmap::iterator kt = UniqueRoutes.begin(); kt != UniqueRoutes.end(); ++kt)
  {
    if (result.count(kt->first) == 0)
    {
      return false ;
      //cout << "ALL CITIES NOT POSSIBLE!" << endl ;
    }
  }
  
  //cout << "ALL CITIES POSSIBLE!!!" << endl ;
  return true ;
}





