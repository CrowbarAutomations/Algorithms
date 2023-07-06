#include "inc/functionMapping.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Local Variable declaration
  int userInput;

  // Initialize the function table
  initializeFunctionTable();

  // Print the list of available algorithms
  printf("The following algorithms can be selected:\n"
          "1. Quick Sort\n"
          "2. Dijkstra's Algorithm\n"
          "3. Prim's Algorithm\n"
          "4. Knapsack Problem\n"
          "5. Fast Fourier Transform (FFT)\n\n"
  );
  
  printf("Enter the number associated with the algorithm which you want to run:");
  
  // Read the user's input
  scanf("%d", &userInput);

  // Get the name of the selected algorithm based on user input
  const char* functionName = getFunctionName(userInput);
  
  // Print the selected algorithm
  printf("The following algorithm has been selected: %s\n", functionName);

  // Execute the selected algorithm
  executeFunction(userInput);
  
  return 0;
}