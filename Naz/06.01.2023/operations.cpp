#include "operations.h"
#include <numeric>
#include <complex>

using namespace std;

double NormalOperations(int op, double firstNum, double secondNum) {

	double result;

	switch (op) {
	case 1:
		result = firstNum + secondNum;
		return result;
	case 2:
		result = firstNum - secondNum;
		return result;
	case 3:
		result = firstNum * secondNum;
		return result;
	case 4:
		result = firstNum / secondNum;
		return result;
	}
}

complex<double> ComplexOperations(int op, int firstComplexOperation, int secondComplexOperation, double firstReal, double firstImag, double secondReal, double secondImag) {

	complex<double> result;

	complex<double> firstComplexNumber = SubComplexOperations(firstComplexOperation, firstReal, firstImag);
	complex<double> secondComplexNumber = SubComplexOperations(secondComplexOperation, secondReal, secondImag);

	switch (op) {
	case 1:
		result = firstComplexNumber + secondComplexNumber;
		return result;
	case 2:
		result = firstComplexNumber - secondComplexNumber;
		return result;
	case 3:
		result = firstComplexNumber * secondComplexNumber;
		return result;
	case 4:
		result = firstComplexNumber / secondComplexNumber;
		return result;
	}

	return result;
}

complex<double> SubComplexOperations(int op, double firstReal, double firstImag) {

	complex<double> result;

	complex<double> firstNum = firstReal;
	complex<double> secondNum = firstImag * 1i;

	switch (op) {
	case 1:
		result = firstNum + secondNum;
		return result;
	case 2:
		result = firstNum - secondNum;
		return result;
	case 3:
		result = firstNum * secondNum;
		return result;
	case 4:
		result = firstNum / secondNum;
		return result;
	}
}