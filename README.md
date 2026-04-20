# Programming languages and tools

This is an introductory course to the world of programming.  
The topics covered include programming and the tools that can be used for work and projects.

## Used:

Language: **C++**.  
Tools and topics: 
- Compiler 
- Debugger
- CMake
- Unit tests.

## Contents:
- [lab1 - introdution](#lab1---introdution)
- [lab2 - cmake](#lab2---cmake)
- [lab3 - algorithms](#lab3---algorithms)
- [lab4 - strings](#lab4---strings)
- [lab5 - pointers](#lab5---pointers)
- [lab6 - classes and objects](#lab6---classes-and-objects)

## Division into laboratory sessions:

### [lab1 - introdution](./lab1)

Introdution to C++.  
Basics of programming and demonstration how to test, debug and compile code.  
The main task is to apply the [Monte Carlo](https://en.wikipedia.org/wiki/Monte_Carlo_method) algorithm.  

**Useful commands:**

- Compilation:
```bash
g++ program.cpp -o program
```
- Run program:
```bash
./program
```
- Compilation with additional info for debugging:
```bash
g++ program.cpp -std=c++20 -ggdb -o program
```
- Debugging:
```bash
gdb program
```
- Other debugging command:
```
break, run, continue, next, print, display
```


### [lab2 - cmake](./lab2)

Introdution to Cmake.  
Lab includes tasks with static arrays and introduce Cmake / Make topic. Step-by-step instructions for launching a project using CMake tools.

**Quick facts:**  
You have to prepare project structure and *CMakeLists.txt* file that includes paths to all file sources you use. Then you can run commands from the section below.

**Useful commands:**
- Project structure:
```bash
mkdir -p example/src example/include example/tests
cd example
```
- Makefile generate:
```bash
cmake .
```
- Compile program:
```bash
make
```
- Run program:
```bash
./main
```
- Clean compiled program files:
```bash
make clean
```
- Run unit tests:
```bash
make test
```

**Troubleshooting (on a university computer):**  
#### GTest:  
There are two ways of implementing tests in *CMakeLists.txt* in the project. If you do not have GTest installed (and do not want to) you can uncomment commented section instead of existing GTest settings lines.  
#### Project quota excedeed:
If you are having problems with program compilation you can run these commands before building project:
- Clear existing build and cache:
```bash
rm -rf build/*
rm -rf ~/.cache/*
```
- Prepare tmp folder for project build:
```bash
mkdir -p /tmp/$USER/project_build
cd /tmp/$USER/project_build
```
- Build your project and run commands here:
```bash
cmake ~/Desktop/JiNP/laby/project
```


### [lab3 - algorithms](./lab3)

This lab cover algorithms in C++. They focus on the concepts of trees, queues and stacks, and discuss heap sort and multi-pass sorting in detail.

**Quick facts:**  
### Tree:
A tree is a structure of nodes connected like a **hierarchy** (like a family tree).  
One node is the root, and others branch out as children.  
Each node can have multiple children.
### Queue:
A queue works like a line of people.  
Rule: **FIFO** (First In, First Out)
→ first element added is the first removed.
### Stack:
A stack works like a pile of books.  
Rule: **LIFO** (Last In, First Out)
→ last element added is the first removed.

### Heap sort:
Heap sort is a sorting algorithm that uses a heap (special tree structure).  
Usually uses a max-heap (largest element on top).  
**How it works:**  
Build a heap from the array.  
Take the largest element (root) and move it to the end.  
Repeat for the remaining elements.  
**Key points:**  
Time: O(n log n)  
Works in-place (no extra memory)  
Not stable (order of equal elements may change)  
### Multi-phase sorting:
Multiphase sort is used for very large data that doesn’t fit in memory.  
It’s an external sorting method (uses disk/files).  
**How it works (simple idea):**  
Split data into smaller chunks.  
Sort each chunk separately.  
Merge them in multiple phases until fully sorted.  
**Key points:**  
Used in databases / big data  
Efficient for huge files  
Based on merge sort idea  


### [lab4 - strings](./lab4)

Exercises and tasks on text processing – focusing on the `string` type.   
Implementing your own Linux functions (tail, sort, grep). 

**Quick facts:**  
Running program requires knowledge about CMake / Make from **lab2**.  
*Sample data for the programme in the file test_data.txt*

**Commands:**
```bash
cmake .
```
```bash
make
```
```bash
./main
```
```bash
make test
```


### [lab5 - pointers](./lab5)

Exercises involving pointer operations in C++.  
An introduction to simple exercises on the topic of cybersecurity.  

**Quick facts:**  
Before compilation uncomment selected function in [main.cpp](./lab5/src/main.cpp).  

**Commands:**
```bash
cmake .
```
```bash
make
```
```bash
./main
```
```bash
make test
```

- Prepare input file:
```bash
echo "This is a top-secret message – do not read!" > secret_data.txt
```
- Run script:
```bash
./main --input=secret_data.txt --output=encrypted_result.bin
```
```bash
./main --input=secret_data.txt --output=hacked.txt ----vulnerability
```
- Show files:
```bash
cat encrypted_result.bin
```
```bash
cat hacked.txt
```


### [lab6 - classes and objects](./lab6)

An object-oriented C++ project. It covers 2D vector logic using classes and objects.

**Quick facts:**  
Prepare your settings in [main.cpp](./lab6/src/main.cpp) file:
- set map size
- place the cars on the map
- run command with selected options (f-forward, b-back, r-right, l-left)

**Commands:**
- Run simulation exmaple (after succesful compilation):
```bash
./main f b r l f f
```
- Useful commands:
```bash
cmake .
```
```bash
make
```
```bash
make test
```