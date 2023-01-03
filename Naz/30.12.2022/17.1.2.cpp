#include "17.1.2.h"
#include <cmath>

double FirstMedium(double y, double n) {
	double dividend = y * y - 0.8 * y + sqrt(y);
	double divider = 23.1 * (n * n) + cos(n);
	double result = dividend / divider;

	return result;
}