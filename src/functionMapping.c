#include "inc/functionMapping.h"

// Hash table size
#define FUNCTION_TABLE_SIZE 5

// Hash table array
HashEntry functionTable[FUNCTION_TABLE_SIZE];

// Hash function
unsigned int hash(int input)
{
    return (input - 1) % FUNCTION_TABLE_SIZE;
}

// Initialize the hash table
void initializeFunctionTable()
{
    // Clear the function table
    memset(functionTable, 0, sizeof(HashEntry) * FUNCTION_TABLE_SIZE);

    // Add Algorithm function to user input mappings
    functionTable[hash(1)].input = 1;
    strcpy(functionTable[hash(1)].functionName, "Quick Sort Algorithm");
    functionTable[hash(1)].function = &quickSortAlgorithm;

    functionTable[hash(2)].input = 2;
    strcpy(functionTable[hash(2)].functionName, "Dijkstra's Algorithm");
    functionTable[hash(2)].function = &dijkstrasAlgorithm;

    functionTable[hash(3)].input = 3;
    strcpy(functionTable[hash(3)].functionName, "Prim's Algorithm");
    functionTable[hash(3)].function = &primsAlgorithm;

    functionTable[hash(4)].input = 4;
    strcpy(functionTable[hash(4)].functionName, "Knapsack Problem Algorithm");
    functionTable[hash(4)].function = &knapsackProblemAlgorithm;

    functionTable[hash(5)].input = 5;
    strcpy(functionTable[hash(5)].functionName, "Fast Fourier Transform (FFT) Algorithm");
    functionTable[hash(5)].function = &fastFourierTransformAlgorithm;
}

// Execute the function based on user input
void executeAlgorithm(int input, FileData *data)
{
    // Calculate the hash index
    unsigned int index = hash(input);

    // Check if the function exists for the given input
    if (functionTable[index].input == input)
    {
        // Execute the corresponding algorithm function
        functionTable[index].function(data);
    }
    else
    {
        printf("No matching function found for input '%d'\n", input);
    }
}

// Get the function name based on user input
const char *getFunctionName(int input)
{
    // Calculate the hash index
    unsigned int index = hash(input);

    // Check if the function exists for the given input
    if (functionTable[index].input == input)
    {
        // Return the name of the corresponding algorithm
        return functionTable[index].functionName;
    }
    else
    {
        return "No matching function";
    }
}
