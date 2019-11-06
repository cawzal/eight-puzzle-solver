# Eight Puzzle Solver

Command line eight puzzle solver. The program constructs a graph of all the nodes, and then performs a search using the algorithm specified. The time indicates the duration of the search and not the time required to construct the graph. The heuristic used for the A* and IDA* algorithms in the manhattan distance.

### Program Arguments

```
program.exe puzzle algorithm
```
The puzzle is provided as a nine digit sequence. The program does not  check for unsolvable board configurations before attempting to solve.
The algorithm is selected based on the following options:
- ``astar`` (A*)
- ``bfs`` (breadth-first search)
- ``idastar`` (IDA*),
- ``iddfs`` (iterative deepening depth-first search)

### Example (Usage)

```
main.exe 130426758 idastar
```

### Example (Output)
```
Algorithm: IDA*
Time: 0.00000s
Nodes examined: 5
Moves required: 4

Move: 1
 1 [3] 0
 4  2  6
 7  5  8

Move: 2
 1  0  3
 4 [2] 6
 7  5  8

Move: 3
 1  2  3
 4  0  6
 7 [5] 8

Move: 4
 1  2  3
 4  5  6
 7  0 [8]

Completed
 1  2  3
 4  5  6
 7  8  0
 ```