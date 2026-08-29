# Cache Simulator

- Built a configurable C++ cache simulator(direct-mapped, Set-Associative, Fully-Associative) with LRU eviction, cycle cost modeling, and hit/miss statistics

Observations:
- Cycle Counts is the same across implementations because that depends on hit/miss counts.
- Execution time is different since the access time in a unordered_map is O(1) compared to vector O(n)

Average Efficiency = 
- Full:   
- Set:     
- Direct:  

Part 1:

- Object Oriented Programming with C++
- Cache implemented as a vector
- LRU logic done with a counter
- Cycle count done with fixed miss and hit values
    - Hit = 1 cycle
    - Miss = 5 cycles
- Execution time measured with <chrono> from when the file reading starts to end
- Debugged heap corruption using Valgrind
- Claude used to understand how to set up the classes, syntax, debugging and creating the trace file
- Learned how to do git add and commit in terminal 

Part 2:

- Implemented as a unordered_map, each bucket is a vector/cacheline
- Added hash.h and hash.cpp
- main.cpp runs both implementation and prints out results





