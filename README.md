# Algorithms

The Algorithm Selector is a simple command-line program written in C that allows users to select and run algorithms. It provides a list of available algorithms and prompts the user to enter the number associated with the algorithm they want to run. The program then executes the selected algorithm and displays its name.

## Available Algorithms

1. Quick Sort: Quick Sort is a highly efficient sorting algorithm that uses a divide-and-conquer approach. It has an average and best-case time complexity of O(n log n), making it one of the fastest sorting algorithms.

2. Dijkstra's Algorithm: Dijkstra's Algorithm is used to find the shortest path in a graph from a source node to all other nodes. It has a time complexity of O(V^2) or O(E log V) with a min-priority queue, where V represents the number of vertices and E represents the number of edges in the graph.

3. Prim's Algorithm: Prim's Algorithm is used to find the minimum spanning tree of a weighted undirected graph. It has a time complexity of O(V^2) or O(E log V) with a binary heap, where V represents the number of vertices and E represents the number of edges in the graph.

4. Knapsack Problem (Dynamic Programming): The Knapsack problem is a classic optimization problem that aims to maximize the value of items packed into a knapsack, given their weights and values. It can be solved using dynamic programming techniques, with a time complexity of O(nW), where n is the number of items and W is the maximum capacity of the knapsack.

5. Fast Fourier Transform (FFT): FFT is an efficient algorithm for computing the Discrete Fourier Transform (DFT) of a sequence or its inverse. It has a time complexity of O(n log n), where n represents the number of elements in the input sequence.

## How to Use

To compile and run the program locally, follow these steps:

1. Clone the repository:

```shell
git clone https://github.com/your-username/algorithm-program.git
```

2. Compile the source code:

```shell
cd algorithm-program
make
```

3. Run the program:

```shell
./bin/algorithm_program
```

4. Follow the instructions displayed in the program to select and execute algorithms.

## Directory Structure

```lua
Algorithms/                <-- Root directory of your project
  |- .build/                <-- Build directory
  |
  |- .config/               <-- Configuration files
  |    |- ...
  |
  |- .github/               <-- GitHub-related files and workflows
  |    |- CONTRIBUTING.md   <-- Contributing guidelines
  |    |- workflows/
  |        |- build.yml
  |        |- test.yml
  |        |- ...
  |
  |- .vscode/               <-- VS Code configuration directory
  |    |- launch.json       <-- Configuration for launching the program in VS Code
  |    |- settings.json     <-- Configuration for VS Code settings
  |    |- tasks.json        <-- Configuration for tasks in VS Code
  |
  |- bin/                   <-- Directory for compiled executables
  |    |- main.exe          <-- Compiled executable file
  |
  |- doc/                   <-- Documentation folder
  |    |- ...
  |
  |- src/                   <-- Source code directory
  |    |- functionMapping.c
  |    |- main.c
  |    |- ...
  |    |- inc/              <-- Header files directory
  |        |- functionMapping.h
  |        |- ...
  |
  |- test/                  <-- Test files and resources
  |    |- ...
  |
  |- tools/                 <-- Tools and utilities
  |    |- ...
  |
  |- Makefile               <-- Makefile for building the software
  |- README.md              <-- README file with instructions
```

## Requirements

C Compiler (e.g., gcc)
Make build tool

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvement, please open an issue or submit a pull request.
