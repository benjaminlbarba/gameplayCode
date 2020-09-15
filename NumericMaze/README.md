# Numeric Maze

## Two Approaches Implemented:

1) numericMazeRecursive
2) numericMazeGreedy

## Important Note:
The recursive algorithm is the more accurate of the two approaches but only works for short paths.
The greedy algorithm (an algorithm that attempts to make the best decision at each step given set rules) should be able to calculate longer paths though they will not always be the shortest path.  This is because the problem lacks optimal substructure and thus cannot be properly solved greedily.

The code for the recursive approach is relatively messy because I experimented with that one the most.

## How to run:

To compile and run in Terminal:
1) Open up the folder of desired algorithm.
2) make all
3) ./NumericMazeSolver

# Approaches to solving the problem:

## 1. Dynamic Programming - numericMazeRecursive (Implemented)
#### Correct Solution, Inefficient
#### uses dynamic programming 
The main drawback with this algorithm is that each recursion is independent and recursions at each level are not run in parallel (contrast with BFS method below).  That is, if we start on a recursion that is inefficient we will have to follow it all the way down.  To counteract this, a recursive depth was set.  For instance, the first recursion will be explored to a depth of 10.  If no solution is found we will explore the final level reached to another depth of 10.  Complexity increases exponentially at each level so the process can be repeated endlessly logically, but there is a limit to memory and user wait times.

#### Possible improvements:

##### Improvement 1: use int array
A string is used to keep track of the solution, though an int list would certainly prove more flexible long-term.

##### Improvement 2: memoization
Implement memoization: improve runtime at cost of memory. 


## 2. Greedy Algorithm - numericMazeGreedy (Implemented)
#### Works on longer paths. Path is not always the shortest.
Prioritized which solution gets us from start to end fastest (multiply is greater than).
Start and end are arbitrary so switched them around.

#### Notes on Error Checking:
Checks inputs are valid and solution is possible.
Checks whether would fit within int type (int type was chosen for simplicity and allows for handling of valid negative pairings whereas unsigned would not).

#### Possible improvements:

#### Improvement 1: redundancy removal
The output path has several redundancies in which numbers repeat.  The entire range of numbers between any two repeated numbers can be removed.  Given the solution would still be incorrect, this optimization was not implemented.

#### Improvement 2: multiple strategies 
We can add another stragy to the algorithm, namely, keep track of the difference between the current and end.  If they are both even (a common condition) we can calculate how many steps it will take to add our way from current to end.  If the number of steps is shorter than the steps we are currently at we can return to that point (as long as we implement some bookkeeping) and apply this addition strategy at that point.

We can apply other strategies in this manner.


## 3. Not Implemented: Brute Force Breadth-First-Search (BFS) modification
#### Correct Solution, Inefficient
Similar to recursive algorithm in its exhaustiveness.

Create two graphs.  The start and end are the root of each graph.  Then, build each graph using BFS, meaning neighbors are created for the current level.  Then neighbors for each of those neighbors are created.  This allows us to work in parallel.

Correct, but this is costly as requires cubed operations for each level of each graph.  The advantage to this one is that each one works in parallel.