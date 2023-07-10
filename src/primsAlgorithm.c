#include "inc/primsAlgorithm.h"

#define INF 9999999

int minKey(int key[], bool mstSet[], int numVertices)
{
  int min = INF, minIndex;

  // Find the vertex with the minimum key value among the vertices not yet included in the MST
  for (int v = 0; v < numVertices; v++)
  {
    if (mstSet[v] == false && key[v] < min)
    {
      min = key[v];
      minIndex = v;
    }
  }

  return minIndex;
}

int primMST(int graph[][MAX_VERTICES], int numVertices)
{
  int parent[numVertices];  // Array to store the parent of each vertex in the MST
  int key[numVertices];     // Array to store the key values of each vertex
  bool mstSet[numVertices]; // Array to track which vertices are included in the MST

  // Initialize the key values and MST set arrays
  for (int i = 0; i < numVertices; i++)
  {
    key[i] = INF;
    mstSet[i] = false;
  }

  key[0] = 0; // Start with the first vertex as the root of the MST
  parent[0] = -1;

  // Construct the MST with (numVertices - 1) edges
  for (int count = 0; count < numVertices - 1; count++)
  {
    int u = minKey(key, mstSet, numVertices); // Find the vertex with the minimum key value
    mstSet[u] = true;                         // Mark the vertex as included in the MST

    // Update the key values and parent for adjacent vertices
    for (int v = 0; v < numVertices; v++)
    {
      if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
      {
        parent[v] = u;
        key[v] = graph[u][v];
      }
    }
  }

  // Calculate the minimum cost by summing up the edge weights in the MST
  int minCost = 0;
  for (int i = 1; i < numVertices; i++)
  {
    minCost += graph[i][parent[i]];
  }

  return minCost;
}

void printMST(int graph[][MAX_VERTICES], int parent[], int numVertices)
{
  // Print the selected edges of the minimum spanning tree
  for (int i = 1; i < numVertices; i++)
  {
    printf("%d - %d\n", parent[i], i);
  }
}

void primsAlgorithm(FileData *data)
{
  // Access the data from the FileData structure
  int numValues = data->numValues;
  float *values = data->values;

  // Check if there are enough values for the algorithm
  if (numValues < 1)
  {
    printf("Insufficient values for Prim's Algorithm\n");
    return;
  }

  // Calculate the number of vertices based on the number of values
  int numVertices = (int)values[0];

  // Calculate the number of edges
  int numEdges = numValues - 1;

  // Check if the number of edges is correct
  if (numEdges != numVertices * (numVertices - 1) / 2)
  {
    printf("Invalid number of edges\n");
    return;
  }

  // Create an adjacency matrix to represent the graph
  int graph[numVertices][numVertices];

  // Fill the adjacency matrix with values from the data array
  int dataIndex = 1;
  for (int i = 0; i < numVertices; i++)
  {
    for (int j = 0; j < numVertices; j++)
    {
      graph[i][j] = (int)values[dataIndex++];
    }
  }

  // Create a parent array to store the MST
  int parent[numVertices];

  // Perform Prim's Algorithm to find the minimum spanning tree
  int minCost = primMST(graph, numVertices);

  // Print the minimum cost and the selected edges
  printf("Minimum Cost: %d\n", minCost);
  printf("Selected Edges:\n");
  printMST(graph, parent, numVertices);
}
