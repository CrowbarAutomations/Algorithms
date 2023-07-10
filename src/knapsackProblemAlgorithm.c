#include "inc/knapsackProblemAlgorithm.h"

int max(int a, int b)
{
  return (a > b) ? a : b;
}

void knapsackProblemAlgorithm(FileData *data)
{
  // Access the data from the FileData structure
  int numValues = data->numValues;
  float *values = data->values;

  // Check if there are enough values for the algorithm
  if (numValues < 3)
  {
    printf("Insufficient values for Knapsack Problem Algorithm\n");
    return;
  }

  // Extract the capacity of the knapsack and the number of items from the data array
  int capacity = (int)values[0];
  int numItems = (int)values[1];

  // Check if the number of items is equal to the actual number of values
  if (numValues != 2 + numItems * 2)
  {
    printf("Invalid number of items or values\n");
    return;
  }

  // Create arrays to store the values and weights of the items
  int itemValues[numItems];
  int itemWeights[numItems];

  // Extract the item values and weights from the data array
  int dataIndex = 2;
  for (int i = 0; i < numItems; i++)
  {
    itemValues[i] = (int)values[dataIndex++];
    itemWeights[i] = (int)values[dataIndex++];
  }

  // Create a 2D array to store the dynamic programming table
  int dpTable[numItems + 1][capacity + 1];

  // Fill the dynamic programming table
  for (int i = 0; i <= numItems; i++)
  {
    for (int w = 0; w <= capacity; w++)
    {
      if (i == 0 || w == 0)
      {
        dpTable[i][w] = 0;
      }
      else if (itemWeights[i - 1] <= w)
      {
        dpTable[i][w] = max(itemValues[i - 1] + dpTable[i - 1][w - itemWeights[i - 1]], dpTable[i - 1][w]);
      }
      else
      {
        dpTable[i][w] = dpTable[i - 1][w];
      }
    }
  }

  // Find the items included in the knapsack
  int selectedItems[numItems];
  int i = numItems;
  int w = capacity;
  int numSelectedItems = 0;

  while (i > 0 && w > 0)
  {
    if (dpTable[i][w] != dpTable[i - 1][w])
    {
      selectedItems[numSelectedItems++] = i - 1;
      w -= itemWeights[i - 1];
    }
    i--;
  }

  // Print the maximum value and the selected items
  printf("Maximum Value: %d\n", dpTable[numItems][capacity]);
  printf("Selected Items: ");
  for (int j = numSelectedItems - 1; j >= 0; j--)
  {
    printf("%d ", selectedItems[j]);
  }
  printf("\n");
}
