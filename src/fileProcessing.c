#include "fileProcessing.h"

void processFile(int algorithm, FileData **data, int *fileOpenStatus)
{
  // Get the name of the selected algorithm based on the algorithm number
  const char *functionName = getFunctionName(algorithm);

  // Construct the file name based on the selected algorithm
  char fileName[100];
  sprintf(fileName, "%s.txt", functionName);
  printf("Processing file: %s\n", fileName);

  // Open the file
  FILE *file = fopen(fileName, "r");
  if (file == NULL)
  {
    printf("Error opening file: %s\n", fileName);
    *fileOpenStatus = 0; // Set file open status to indicate failure
    return;
  }

  *fileOpenStatus = 1; // Set file open status to indicate success

  // Read the file contents
  int numValues;
  fscanf(file, "%d", &numValues);

  // Allocate memory for the FileData structure
  *data = malloc(sizeof(FileData) + numValues * sizeof(float));
  if (*data == NULL)
  {
    printf("Error allocating memory\n");
    fclose(file);
    *fileOpenStatus = 0; // Set file open status to indicate failure
    return;
  }

  // Assign the number of values
  (*data)->numValues = numValues;

  // Assign the file data to the structure
  fscanf(file, "%d %f", &((*data)->value1), &((*data)->value2));
  for (int i = 0; i < numValues; i++)
  {
    fscanf(file, "%f", &((*data)->values[i]));
  }

  // Close the file
  fclose(file);
}
