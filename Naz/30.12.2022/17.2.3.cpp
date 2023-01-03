#include "17.2.3.h"
#include <cmath>

double SecondHard(double x, int len) {
	double result = 1.;

	len *= 2;

	for (int i = 2; i < len + 1; i += 2) {
		int fak = Faktorial(i);
		result += pow(x, i) / fak;
	}

	return result;
}

int Faktorial(int n) {
	int faktorial = 1.;

	for (int i = 1; i <= n; i++) {
		faktorial *= i;
	}

	return faktorial;
}