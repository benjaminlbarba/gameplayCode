#include <vector>
#include <cmath>        // std::abs
#include <iostream>     // std::cout
#include <algorithm>    // std::reverse
#include <limits.h>     //INT_MAX

using namespace std;

enum operation {
    OP_INIT = -1,
    OP_DIVIDE = 0, 
    OP_SUBTRACT = 1,
    OP_MULTIPLY = 2
    };

class NumericMazeSolver{
    public:
        std::vector<int> arr;
        int current;
        int start;
        int end;
        int numOperations;
        operation prevOperation;

    NumericMazeSolver(int myStart, int myEnd):
        start(myStart),
        end(myEnd)
    {
        numOperations = 0;
        current = myEnd;
        arr.push_back(current);
    };

    int getCurrentVal(){
        return current;
    }

    /**
     * VALIDITY CHECKS
     * */
    bool invalidStartAndEnd(){
        if (start > 0 && end < 0){
            cout << "solutionPossible: false.  Start is positive [" << start << "] and end [" << end <<"] is negative.\n";
            return true;
        }

       return false;
    }

    bool multiplyOperation_isCurrentValAtLimit(){
        //if we are about to multiply
        if (getCurrentVal() >= INT_MAX / 2){
            return true;
        }

        return false;
    }

    bool subtractOperation_isCurrentValAtLimit(){
        //if we are about to multiply
        if (getCurrentVal() == INT_MAX - 2){
            return true;
        }

        return false;
    }

    /**
     * Updates current value with an operation
     * @param an operation to conduct on currentValue
     * @return true if updated properly, false if operation reaches int limit
     * */
    bool updateCurrentVal(operation op){
        prevOperation = op;
        numOperations++;

        //cout << "updateCurrentVal: prevOperation = " << prevOperation << "\n";

        int newValue = -1;
        if (op == OP_DIVIDE){
            if (multiplyOperation_isCurrentValAtLimit()){
                return false;
            }
            newValue = getCurrentVal() / 2;
        }
        else if (op == OP_SUBTRACT){
            newValue = getCurrentVal() - 2;
        }
        else if (op == OP_MULTIPLY){
            newValue = getCurrentVal() * 2;
        }

        arr.push_back(newValue);
        current = newValue;
        
        return true;
    }

    /**
     * Greedy algorithm for determining best decision at current step
     * @return true if solution found, false if could not be solved.
     * */
    bool solve(){
        if (invalidStartAndEnd()){
            return false;
        }

        //make sure end is greater than start, otherwise double until it is
        while (start > getCurrentVal()){
            updateCurrentVal(OP_MULTIPLY);
        }

        
        while (getCurrentVal() != start){
            //cout << "solve: prevOperation = " << prevOperation << "\n";

            operation newOperation;
            /** can we divide?
             * 1) Even
             * 2) Last operation was not multiply (as this would keep just reverse previous operation)
             * */
            if (getCurrentVal()%2 == 0 && (prevOperation != OP_MULTIPLY)){
                newOperation = OP_DIVIDE;
            }
            /** can we subtract?
             * 1) subtraction actually gets us closer
             * 2) Subtracting will not get us within a range of 1 of start
             * */
            else if(getCurrentVal() > start && (abs(getCurrentVal() - 2 - start) != 1)){
                newOperation = OP_SUBTRACT;
            }
            else{
                newOperation = OP_MULTIPLY;
            }

            if (!updateCurrentVal(newOperation)){
                return false;
            }
        }

        return true;
    }

    void reverseVector(){
        std::reverse(arr.begin(), arr.end());
    }

    void printSolution(){
        for (std::vector<int>::iterator it=arr.begin(); it!=arr.end(); ++it){
            std::cout << ' ' << *it;
        }
        std::cout << '\n';
        //std::cout << "numbber of operations = " << numOperations << "\n";
    }

    void run(){
        
        if (solve()){
            reverseVector();
            printSolution();
        }
        else{
            std::cout << "run: Solve returned false.\n";
        }
    }

};

int initAndRunSolver(){
    int i, j;
    cout << "Please enter a positive integer value for start: ";
    cin >> i;
    cout << "The value you entered is " << i << "\n";
    cout << "Please enter a positive integer value for end: ";
    cin >> j;
    cout << "The value you entered is " << j << "\n";
    cout << "Finding shortest path from " << i << " to " << j <<":\n";

    NumericMazeSolver solver(i, j);
    solver.run();
    
    return 0;
}

int main(){
    return initAndRunSolver();
}
