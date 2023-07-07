import unittest
import sys
import os

# Add the parent directory to the module search path
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))

from src import main

class MainTestCase(unittest.TestCase):
    def test_main(self):
        # Test Case 1: User input 1
        userInput = 1
        main(userInput)
        # Add assertions or checks to validate the expected behavior for input 1

        # Test Case 2: User input 2
        userInput = 2
        main(userInput)
        # Add assertions or checks to validate the expected behavior for input 2

        # Test Case 3: User input 3
        userInput = 3
        main(userInput)
        # Add assertions or checks to validate the expected behavior for input 3

        # Test Case 4: User input 4
        userInput = 4
        main(userInput)
        # Add assertions or checks to validate the expected behavior for input 4

        # Test Case 5: User input 5
        userInput = 5
        main(userInput)
        # Add assertions or checks to validate the expected behavior for input 5

if __name__ == '__main__':
    unittest.main()
