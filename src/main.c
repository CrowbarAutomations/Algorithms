#include <stdio.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1 // Maximum length of the command (algorithm name)

int main() {
    char command[MAX_COMMAND_LENGTH]; // Array to store the command (algorithm name)
  
    // Print the list of available algorithms
    printf("The following algorithms can be selected:\n",
              "Quick Sort\n",
              "Dijkstra's Algorithm\n",
              "Prim's Algorithm\n",
              "Knapsack Problem\n",
              "Fast Fourier Transform (FFT)\n"
      );
  
    printf("Enter the name of the algorithm which you want to run:");
    
    // Read the user's input (algorithm name) and store it in the 'command' variable
    fgets(command, sizeof(command), stdin);
    
    // Remove the newline character at the end of the input
    command[strcspn(command, "\n")] = '\0'; 

    // Print the selected algorithm
    printf("The following algorithm has been selected: %s\n", command);
  
    return 0;
}
