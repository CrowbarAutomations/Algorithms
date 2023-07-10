#include "quickSortAlgorithm.h"

// Function to swap two float values
void swap(float *a, float *b)
{
  float temp = *a;
  *a = *b;
  *b = temp;
}

// Function to partition the array for Quick Sort
int partition(float arr[], int low, int high)
{
  // Select the pivot element
  float pivot = arr[high];

  // Initialize the partition index
  int i = low - 1;

  // Iterate through the array elements
  for (int j = low; j <= high - 1; j++)
  {
    // If the current element is smaller than or equal to the pivot,
    // swap arr[i+1] and arr[j]
    if (arr[j] <= pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }

  // Swap the pivot element with the element at (i+1) to place the pivot in the correct position
  swap(&arr[i + 1], &arr[high]);

  // Return the partition index
  return (i + 1);
}

// Recursive function to perform Quick Sort
void quickSort(float arr[], int low, int high)
{
  if (low < high)
  {
    // Find the partition index
    int pi = partition(arr, low, high);

    // Recursively call quickSort on the left and right partitions
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

// Quick Sort algorithm function
void quickSortAlgorithm(FileData *data)
{
  // Access the data from the FileData structure
  int numValues = data->numValues;
  float *values = data->values;

  // Apply Quick Sort algorithm to the values array
  quickSort(values, 0, numValues - 1);

  // Print the sorted values
  printf("Sorted Values: ");
  for (int i = 0; i < numValues; i++)
  {
    printf("%.2f ", values[i]);
  }
  printf("\n");
}
