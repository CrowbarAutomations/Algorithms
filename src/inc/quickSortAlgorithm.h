#ifndef QUICKSORT_ALGORITHM_H
#define QUICKSORT_ALGORITHM_H

// Libraries
#include <stdio.h>
#include <stdlib.h>

// Local Files
#include "fileProcessing.h"

// Function to swap two float values
void swap(float *a, float *b);

// Function to partition the array for Quick Sort
int partition(float arr[], int low, int high);

// Recursive function to perform Quick Sort
void quickSort(float arr[], int low, int high);

// Quick Sort algorithm function
void quickSortAlgorithm(FileData *data);

#endif /* QUICKSORT_ALGORITHM_H */
