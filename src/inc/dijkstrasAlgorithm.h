#ifndef DIJKSTRAS_ALGORITHM_H
#define DIJKSTRAS_ALGORITHM_H

// Libraries
#include <stdio.h>
#include <limits.h>

// Local Files
#include "fileProcessing.h"

#define MAX_VERTICES 100 // Maximum number of vertices in the graph

// Function to create the adjacency matrix from the data array
void createAdjacencyMatrix(float values[], int numVertices, int adjacencyMatrix[][MAX_VERTICES]);

// Function to apply Dijkstra's Algorithm
void applyDijkstra(int adjacencyMatrix[][MAX_VERTICES], int numVertices, int sourceVertex, int distances[], int visited[]);

// Function to print the shortest path distances from the source vertex
void printShortestPathDistances(int distances[], int numVertices, int sourceVertex);

// Dijkstra's Algorithm function
void dijkstrasAlgorithm(FileData *data);

#endif /* DIJKSTRAS_ALGORITHM_H */
