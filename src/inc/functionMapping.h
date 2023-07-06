#ifndef FUNCTION_MAPPING_H
#define FUNCTION_MAPPING_H

// Define the function pointer type for algorithm functions
typedef void (*FunctionPointer)();

// Define the hash table entry structure
typedef struct {
    int input;                          // User input associated with the algorithm
    char functionName[50];              // Name of the algorithm
    FunctionPointer function;           // Function pointer to the algorithm
} HashEntry;

// Function prototypes
void initializeFunctionTable();         // Initialize the hash table with algorithm mappings
void executeFunction(int input);        // Execute the function based on user input
const char* getFunctionName(int input); // Get the function name based on user input

#endif /* FUNCTION_MAPPING_H */
