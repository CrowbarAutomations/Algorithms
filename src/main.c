#include "inc/functionMapping.h"
#include <stdio.h>

int main() {
  // Local Variable decleration 
  int userInput;

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
  
  scanf("%d", &userInput);

  const char* functionName = getFunctionName(userInput);
  
  // Print the selected algorithm
  printf("The following algorithm has been selected: %s\n", functionName);

  executeFunction(userInput);
  
  return 0;
}