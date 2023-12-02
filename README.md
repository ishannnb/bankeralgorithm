# Banker_Algorithm
The Banker's Algorithm functions as a deadlock avoidance strategy. This algorithm ensures that the allocated resources and the maximum resources required by a process are consistently kept below the total available resources.


## Note: C++ compiler is inbuilt in the Unix/Linux
To run in program in Windows, you need to have C++ compiler installed and add the compiler path to the system variables.
## Importing the file locally
Clone the repository
```console
foo@bar % git clone https://github.com/ishannnb/bankeralgorithm.git
```
## Executing the program
In the Shell or Command Line Interface (CLI):
```console
foo@bar % g++ banker.cpp -o banker -std=c++11
foo@bar % ./banker

```

## Output
The output will look similar to this:

```console
Allocating P0
Allocating P1
Allocating P2
Allocating P3
Allocating P4
Allocation: 
0 1 0 
2 0 0 
3 0 2 
2 1 1 
0 0 2 
Max: 
7 5 3 
3 2 2 
9 0 2 
2 2 2 
4 3 3 
Need: 
7 4 3 
1 2 2 
6 0 0 
0 1 1 
4 3 1 
Available: 3 3 2 
Need: 
7 4 3 
1 2 2 
6 0 0 
0 1 1 
4 3 1 
Is this sequence safe?
The system is in safe state
Safe Sequence: P1 P3 P4 P0 P2 

```
