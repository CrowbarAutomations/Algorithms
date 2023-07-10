#ifndef PRIMS_ALGORITHM_H
#define PRIMS_ALGORITHM_H

// Libraries
#include <stdio.h>
#include <stdbool.h>

// Local Files
#include "fileProcessing.h"

#define MAX_VERTICES 100

// Function prototype for Prim's Algorithm
void primsAlgorithm(FileData *data);

// Utility function to find the vertex with the minimum key value
int minKey(int key[], bool mstSet[], int numVertices);

// Utility function to print the selected edges of the minimum spanning tree
void printMST(int graph[][MAX_VERTICES], int numVertices);

// Function to find the minimum spanning tree using Prim's Algorithm
int primMST(int graph[][MAX_VERTICES], int numVertices);

#endif /* PRIMS_ALGORITHM_H */
