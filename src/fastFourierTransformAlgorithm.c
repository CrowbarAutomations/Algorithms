#include "inc/fastFourierTransformAlgorithm.h"

void recursiveFFT(ComplexNumber data[], int n, int isInverse)
{
  if (n <= 1)
  {
    return;
  }

  // Separate the even and odd elements
  ComplexNumber even[n / 2];
  ComplexNumber odd[n / 2];
  for (int i = 0; i < n / 2; i++)
  {
    even[i] = data[2 * i];
    odd[i] = data[2 * i + 1];
  }

  // Recursively compute FFT on even and odd elements
  recursiveFFT(even, n / 2, isInverse);
  recursiveFFT(odd, n / 2, isInverse);

  // Compute the twiddle factors
  double angle = (isInverse ? 2 * M_PI : -2 * M_PI) / n;
  ComplexNumber wn = {cos(angle), sin(angle)};
  ComplexNumber w = {1.0, 0.0};

  // Combine the results
  for (int i = 0; i < n / 2; i++)
  {
    ComplexNumber temp = complexMultiply(w, odd[i]);
    data[i] = complexAdd(even[i], temp);
    data[i + n / 2] = complexSubtract(even[i], temp);
    w = complexMultiply(w, wn);
  }
}

void fastFourierTransformAlgorithm(FileData *data)
{
  // Access the data from the FileData structure
  int numValues = data->numValues;
  float *values = data->values;

  // Check if there are enough values for the algorithm
  if (numValues < 2)
  {
    printf("Insufficient values for Fast Fourier Transform (FFT) Algorithm\n");
    return;
  }

  // Determine the size of the input based on the number of values
  int size = 1;
  while (size < numValues)
  {
    size *= 2;
  }

  // Create an array of complex numbers to hold the input data
  ComplexNumber input[size];
  for (int i = 0; i < numValues; i++)
  {
    input[i] = createComplexNumber(values[i], 0);
  }
  for (int i = numValues; i < size; i++)
  {
    input[i] = createComplexNumber(0, 0);
  }

  // Apply the FFT algorithm
  recursiveFFT(input, size, 0);

  // Print the results
  printf("FFT Results:\n");
  for (int i = 0; i < size; i++)
  {
    printf("%.2f + %.2fi\n", input[i].real, input[i].imaginary);
  }
}
