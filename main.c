#include <stdio.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1

int main() {
    char command[MAX_COMMAND_LENGTH];
  
    printf("The following algorithms can be selected:\n",
              "Quick Sort\n",
              "Dijkstra's Algorithm\n",
              "Prim's Algorithm\n",
              "Knapsack Problem\n",
              "Fast Fourier Transform (FFT)\n"
      );
  
    printf("Enter the name of the algorithm which you want to run:");
    fgets(command, sizeof(command), stdin);
    command[strcspn(command, "\n")] = '\0'; 

    printf("The following algorithm has been selected: %s\n", command);
  
    return 0;
}
