#ifndef FUNCTION_MAPPING_H
#define FUNCTION_MAPPING_H

typedef void (*FunctionPointer)();

// Define the hash table entry structure
typedef struct {
    int input;
    char functionName[50];
    FunctionPointer function;
} HashEntry;

void initializeFunctionTable();
void executeFunction(int input);
const char* getFunctionName(int input);

#endif /* FUNCTION_MAPPING_H */