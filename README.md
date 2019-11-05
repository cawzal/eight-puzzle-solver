# Eight Puzzle Solver

### Example (Building)

```
g++ -o main main.cpp Display.cpp Graph.cpp Node.cpp SearchBFS.cpp
```

### Example (Usage)

```
main.exe 130426758
```

### Example (Output)
```
Moves: 4

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