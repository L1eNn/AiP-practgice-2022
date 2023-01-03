#include "17.2.1.h"
#include <cmath>

double SecondEasy(double a, double b, double alpha) {
	double result = 0.5 * (a * a - b * b) * tan(alpha);
	return result;
}