# Eight Puzzle Solver

Command line eight puzzle solver. Program constructs a graph of all the nodes, and then performs a search using the algorithm specified. Time indicates the duration of the search and not the time required to construct the graph. Heuristic used for the A* and IDA* algorithms is the manhattan distance.

### Program Arguments

```
program.exe puzzle algorithm
```

Puzzle is provided as a nine digit sequence where the blank tile is represented by zero. Program does not check for unsolvable board configurations before attempting to solve. Algorithm is selected based on the following options:
- ``astar`` (A*)
- ``bfs`` (Breadth-First search)
- ``idastar`` (IDA*)
- ``iddfs`` (Iterative Deepening Depth-First Search)

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