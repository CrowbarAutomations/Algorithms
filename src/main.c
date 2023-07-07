#include "inc/main.h"

int main()
{
  // Local Variable declaration
  int userInput;
  int fileOpenStatus; // File open status

  // Initialize the function table
  initializeFunctionTable();

  // Print the list of available algorithms
  printf("The following algorithms can be selected:\n"
         "1. Quick Sort\n"
         "2. Dijkstra's Algorithm\n"
         "3. Prim's Algorithm\n"
         "4. Knapsack Problem\n"
         "5. Fast Fourier Transform (FFT)\n\n");

  printf("Enter the number associated with the algorithm which you want to run:");

  // Read the user's input
  scanf("%d", &userInput);

  // Get the name of the selected algorithm based on user input
  const char *functionName = getFunctionName(userInput);

  // Print the selected algorithm
  printf("The following algorithm has been selected: %s\n", functionName);

  // Create a FileData structure
  FileData *fileData = NULL;

  // Process the file based on the selected algorithm and populate the structure
  processFile(userInput, &fileData, &fileOpenStatus);

  // Check if the file was opened successfully
  if (fileOpenStatus == 1)
  {
    // File opened successfully, continue processing
    // ...

    // Access the data in the structure
    printf("File Data:\n");
    printf("Value 1: %d\n", fileData->value1);
    printf("Value 2: %.2f\n", fileData->value2);
    printf("Number of Values: %d\n", fileData->numValues);
    printf("Values:\n");
    for (int i = 0; i < fileData->numValues; i++)
    {
      printf("%.2f ", fileData->values[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory for the file data
    free(fileData);
  }
  else
  {
    // File failed to open, handle the error condition
    printf("Error opening file.\n");
  }

  return 0;
}
