import unittest
import sys
import os

sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))

from src import getFunctionName, executeFunction, initializeFunctionTable

class FunctionMappingTestCase(unittest.TestCase):
    def test_getFunctionName(self):
        # Test Case 1: Input 1
        input_val = 1
        functionName = getFunctionName(input_val)
        self.assertEqual(functionName, "Quick Sort Algorithm")

        # Test Case 2: Input 2
        input_val = 2
        functionName = getFunctionName(input_val)
        self.assertEqual(functionName, "Dijkstra's Algorithm")

        # Test Case 3: Input 3
        input_val = 3
        functionName = getFunctionName(input_val)
        self.assertEqual(functionName, "Prim's Algorithm")

        # Test Case 4: Input 4
        input_val = 4
        functionName = getFunctionName(input_val)
        self.assertEqual(functionName, "Knapsack Problem Algorithm")

        # Test Case 5: Input 5
        input_val = 5
        functionName = getFunctionName(input_val)
        self.assertEqual(functionName, "Fast Fourier Transform (FFT) Algorithm")

    def test_executeFunction(self):
        # Test Case 1: Input 1
        input_val = 1
        self.assertIsNone(executeFunction(input_val))

        # Test Case 2: Input 2
        input_val = 2
        self.assertIsNone(executeFunction(input_val))

        # Test Case 3: Input 3
        input_val = 3
        self.assertIsNone(executeFunction(input_val))

        # Test Case 4: Input 4
        input_val = 4
        self.assertIsNone(executeFunction(input_val))

        # Test Case 5: Input 5
        input_val = 5
        self.assertIsNone(executeFunction(input_val))

    def test_initializeFunctionTable(self):
        # Test the behavior of initializeFunctionTable
        initializeFunctionTable()
        # Add specific assertions to validate the content of the function table

if __name__ == '__main__':
    unittest.main()
