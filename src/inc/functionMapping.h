#ifndef FUNCTION_MAPPING_H
#define FUNCTION_MAPPING_H

#include "quickSortAlgorithm.h"
#include "dijkstrasAlgorithm.h"
#include "primsAlgorithm.h"
#include "knapsackProblemAlgorithm.h"
#include "fastFourierTransformAlgorithm.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the function pointer type for algorithm functions
typedef void (*FunctionPointer)();

// Define the hash table entry structure
typedef struct
{
    int input;                // User input associated with the algorithm
    char functionName[50];    // Name of the algorithm
    FunctionPointer function; // Function pointer to the algorithm
} HashEntry;

// Function prototypes
void initializeFunctionTable();         // Initialize the hash table with algorithm mappings
void executeAlgorithm(int input);       // Execute the function based on user input
const char *getFunctionName(int input); // Get the function name based on user input

#endif /* FUNCTION_MAPPING_H */
