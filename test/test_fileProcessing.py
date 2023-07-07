import unittest
import sys
import os

# Add the parent directory to the module search path
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))

from src import processFile

class FileProcessingTestCase(unittest.TestCase):
    def test_processFile(self):
        # Test Case 1: Algorithm 1
        algorithm = 1
        fileData = None
        fileOpenStatus = 0
        result = processFile(algorithm, fileData, fileOpenStatus)
        self.assertEqual(result, "Processing file for Quick Sort Algorithm")

        # Test Case 2: Algorithm 2
        algorithm = 2
        fileData = None
        fileOpenStatus = 0
        result = processFile(algorithm, fileData, fileOpenStatus)
        self.assertEqual(result, "Processing file for Dijkstra's Algorithm")

        # Test Case 3: Algorithm 3
        algorithm = 3
        fileData = None
        fileOpenStatus = 0
        result = processFile(algorithm, fileData, fileOpenStatus)
        self.assertEqual(result, "Processing file for Prim's Algorithm")

        # Test Case 4: Algorithm 4
        algorithm = 4
        fileData = None
        fileOpenStatus = 0
        result = processFile(algorithm, fileData, fileOpenStatus)
        self.assertEqual(result, "Processing file for Knapsack Problem Algorithm")

        # Test Case 5: Algorithm 5
        algorithm = 5
        fileData = None
        fileOpenStatus = 0
        result = processFile(algorithm, fileData, fileOpenStatus)
        self.assertEqual(result, "Processing file for Fast Fourier Transform (FFT) Algorithm")

if __name__ == '__main__':
    unittest.main()
