#ifndef FASTFOURIERTRANSFORM_ALGORITHM_H
#define FASTFOURIERTRANSFORM_ALGORITHM_H

// Libraries
#include <stdio.h>
#include <math.h>

// Local Files
#include "fileProcessing.h"

typedef struct
{
  double real;
  double imaginary;
} ComplexNumber;

// Function to create a complex number
ComplexNumber createComplexNumber(double real, double imaginary);

// Function to add two complex numbers
ComplexNumber complexAdd(ComplexNumber a, ComplexNumber b);

// Function to subtract two complex numbers
ComplexNumber complexSubtract(ComplexNumber a, ComplexNumber b);

// Function to multiply two complex numbers
ComplexNumber complexMultiply(ComplexNumber a, ComplexNumber b);

// Function to perform the Fast Fourier Transform (FFT) algorithm
void fastFourierTransformAlgorithm(FileData *data);

#endif /* FASTFOURIERTRANSFORM_ALGORITHM_H */
