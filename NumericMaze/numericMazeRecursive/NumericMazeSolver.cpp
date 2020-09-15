/*
  OVERVIEW:
  This is a recursive algorithm.  It explores all possibilities. 
  This exhaustive search can consume more memory than available for the program
  In order to avoid such a situation, this program only returns a solution if a solution 
  can be calculated efficiently.
  
  EXPLORING TO LIMITED DEPTH:
  An efficient solution is defined as follows:
  The shortest path takes at most RECURSIVE_DEPTH recursions.
  A RECURSIVE_DEPTH of 10 is recommended.
  This means it will explore each possibility 10 levels deep.
  (So most shortest paths generated will be at most a length of ten - see below for exceptions)  
  Each level can have up to cubed more possilities so complexity increases exponentially.

  RETURNING TO SAVED RECURSION STATES:
  If no solution is found after exploring every recursion to a depth of 10, 
  then the program will explore any savedStates to a max of MAX_SAVED_STATES
  A savedState is a recursion which was cut off at a depth of 10.
  That is, after all recursions are explored to a depth of 10, 
  we will resume exploration of a previous recursion that goes beyond 10 to another depth of 10
  This process repeats but the exponential increase in complexity really limits it.
  
  CONCLUSION:
  In this manner, it allows possibilities to be explored deeply and broadly,
  rather than simply following a single recursion to its final depth before exploring another recursion.
*/

#include <utility>
#include <algorithm>
#include <iostream> 
#include <list> 

using namespace std;

/**
 * It is necessary to set a recursive depth because we may end up following 
 * a recursive path that is very inefficient as recursions work one at a time not in parallel
 * **/
static const int RECURSIVE_DEPTH = 10;
static const int MAX_SAVED_STATES = 100;
static const int LONGER_PATH_PENALTY = 2;

//static is not necessary here, but would be good to limit scope from other potential files
static int counter;
static int minSolutionLength;
static bool solutionFound;
static string bestSolution;
static int numStatesSavedSoFar;

/**
 * The data necessary to recreate a given point in the recursion of findMindDist
 * */
struct recursiveState{
    pair<int, int> pairing;
    string solution;
};

list <recursiveState> savedStates;

void printStringReversed(string x){
    string printX(x);
    reverse(printX.begin(), printX.end());
    cout << printX + "\n";
}

void printSolutionString(string solution){
    string printSol(solution);
    reverse(printSol.begin(), printSol.end());
    cout << printSol + "\n";
}

void setSolutionFound(string x, string solution){
    if (solution.length()  < minSolutionLength){
        minSolutionLength = solution.length();
        bestSolution = solution;
    }
}

/**
 * Saves the data for current state in order to be able to continue running
 * this point in the recursion later
 * */
void saveCurrentState(int i, int j, string solution){
    if (numStatesSavedSoFar < MAX_SAVED_STATES){
        recursiveState stateToSave;
        stateToSave.pairing = make_pair(i, j);
        stateToSave.solution = solution;
        savedStates.push_back(stateToSave);
        numStatesSavedSoFar++;
    }  
}

/**
 * Recurses on input to a depth of RECURSIVE_DEPTH
 * */
int findMinDist(int i, int j, string x, string solution, int myCounter){
    if (solution.length() > minSolutionLength){
        return LONGER_PATH_PENALTY;
    }

    //hit recursive depth, switch no other recursion, return to this if necessary
    if (myCounter > RECURSIVE_DEPTH){
        saveCurrentState(i, j, solution);
        return LONGER_PATH_PENALTY;
    }

    //prepare new entry (must be reversed due to it being a string)
    string newEntry = to_string(j);
    reverse(newEntry.begin(), newEntry.end());
    newEntry = " " + newEntry;

    //solution found
    if (i == j){
        setSolutionFound(x, solution + newEntry);
        return 1;
    }

    myCounter++;

    //determine what actions are possible at current step
    if ((j%2 == 0) && (j - 2 >= i)){
        return 1 +  min(findMinDist(i, j * 2, "a" + x, solution + newEntry, myCounter), 
                    min(findMinDist(i, j / 2, "b" +  x, solution + newEntry, myCounter), 
                    findMinDist(i, j - 2, "c" +  x, solution + newEntry, myCounter)));
    }
    else if(j%2 == 0){
        return 1 +  min(findMinDist(i, j * 2, "a" + x, solution + newEntry, myCounter), 
                    findMinDist(i, j / 2, "b" +  x, solution + newEntry, myCounter));
    }
    else if (j - 2 >= i){
        return 1 +  min(findMinDist(i, j * 2, "a" + x, solution + newEntry, myCounter), 
                    findMinDist(i, j - 2, "c" +  x, solution + newEntry, myCounter));
    }
    else{
        return 1 +  findMinDist(i, j * 2, "a" + x, solution + newEntry, myCounter); 
    }
}


void recurseOnSavedStates(){
    while (savedStates.size() > 0 && !solutionFound){
        //cout << "savedStatesToCheck... " << savedStates.size() << "\n";
        recursiveState state = savedStates.front();
        savedStates.pop_front();
        int newCounter = 0;
        findMinDist(state.pairing.first, state.pairing.second, "x", state.solution, newCounter);
    }
}

void messageUserSolution(){
    if (!solutionFound){
        cout << "Solution could not be computed efficiently.  Try the Greedy algorithm! :)\n";
    }
    
    cout << "Shortest path found:\n";
    printSolutionString(bestSolution);
}

void init(){
    minSolutionLength = INT_MAX;
    solutionFound = false;
}

int run(){
    int i, j;
    cout << "Please enter a positive integer value for start: ";
    cin >> i;
    cout << "The value you entered is " << i << "\n";
    cout << "Please enter a positive integer value for end: ";
    cin >> j;
    cout << "The value you entered is " << j << "\n";
    cout << "Finding shortest path from " << i << " to " << j <<":\n";
    init();

    findMinDist(i, j, "x", "", 0);;

    recurseOnSavedStates();

    messageUserSolution();
    
    return 0;
}

int main(){
    return run();
}