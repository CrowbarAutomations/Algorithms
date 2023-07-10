#include "inc/dijkstrasAlgorithm.h"

// Function to create the adjacency matrix from the data array
void createAdjacencyMatrix(float values[], int numVertices, int adjacencyMatrix[][MAX_VERTICES])
{
  int currentIndex = 0;

  for (int i = 0; i < numVertices; i++)
  {
    for (int j = 0; j < numVertices; j++)
    {
      if (i == j)
      {
        adjacencyMatrix[i][j] = 0; // Set diagonal elements to 0
      }
      else
      {
        adjacencyMatrix[i][j] = (int)values[currentIndex]; // Assign values from the data array
        currentIndex++;
      }
    }
  }
}

// Function to apply Dijkstra's Algorithm
void applyDijkstra(int adjacencyMatrix[][MAX_VERTICES], int numVertices, int sourceVertex, int distances[], int visited[])
{
  // Initialize the distances and visited arrays
  for (int i = 0; i < numVertices; i++)
  {
    distances[i] = INT_MAX; // Set initial distances to infinity
    visited[i] = 0;         // Set all vertices as unvisited
  }

  // Set the distance of the source vertex to 0
  distances[sourceVertex] = 0;

  // Apply Dijkstra's Algorithm
  for (int count = 0; count < numVertices - 1; count++)
  {
    // Find the vertex with the minimum distance value
    int minDistance = INT_MAX;
    int minVertex;

    for (int v = 0; v < numVertices; v++)
    {
      if (visited[v] == 0 && distances[v] <= minDistance)
      {
        minDistance = distances[v];
        minVertex = v;
      }
    }

    // Mark the selected vertex as visited
    visited[minVertex] = 1;

    // Update the distance values of the adjacent vertices
    for (int v = 0; v < numVertices; v++)
    {
      if (visited[v] == 0 && adjacencyMatrix[minVertex][v] && distances[minVertex] != INT_MAX &&
          distances[minVertex] + adjacencyMatrix[minVertex][v] < distances[v])
      {
        distances[v] = distances[minVertex] + adjacencyMatrix[minVertex][v];
      }
    }
  }
}

// Function to print the shortest path distances from the source vertex
void printShortestPathDistances(int distances[], int numVertices, int sourceVertex)
{
  printf("Shortest Path Distances from Source Vertex %d:\n", sourceVertex);
  for (int i = 0; i < numVertices; i++)
  {
    printf("Vertex %d: ", i);
    if (distances[i] == INT_MAX)
    {
      printf("Not Reachable\n");
    }
    else
    {
      printf("%d\n", distances[i]);
    }
  }
}

// Dijkstra's Algorithm function
void dijkstrasAlgorithm(FileData *data)
{
  // Access the data from the FileData structure
  int numValues = data->numValues;
  float *values = data->values;

  // Check if there are enough values for the algorithm
  if (numValues < 3)
  {
    printf("Insufficient values for Dijkstra's Algorithm\n");
    return;
  }

  // Extract the number of vertices from the data array
  int numVertices = (int)values[0];

  // Check if the number of vertices is within the allowed range
  if (numVertices > MAX_VERTICES)
  {
    printf("Number of vertices exceeds the maximum limit\n");
    return;
  }

  // Extract the adjacency matrix and source vertex from the data array
  int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
  createAdjacencyMatrix(values + 1, numVertices, adjacencyMatrix);
  int sourceVertex = (int)values[numVertices * numVertices + 1];

  // Create arrays to store distances and visited vertices
  int distances[MAX_VERTICES];
  int visited[MAX_VERTICES];

  // Apply Dijkstra's Algorithm
  applyDijkstra(adjacencyMatrix, numVertices, sourceVertex, distances, visited);

  // Print the shortest path distances
  printShortestPathDistances(distances, numVertices, sourceVertex);
}
