#ifndef QUICKSORT_ALGORITHM_H
#define QUICKSORT_ALGORITHM_H

// Libraries
#include <stdio.h>
#include <stdlib.h>

// Local Files
#include "fileProcessing.h"

// Function to swap two float values
static inline void swap(float *a, float *b);

// Function to partition the array for Quick Sort
static inline int partition(float arr[], int low, int high);

// Recursive function to perform Quick Sort
static void quickSortHelper(float arr[], int low, int high);

// Quick Sort algorithm function
void quickSortAlgorithm(FileData *data);

#endif /* QUICKSORT_ALGORITHM_H */
