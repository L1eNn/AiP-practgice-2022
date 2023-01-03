#include "17.1.3.h"
#include <cmath>

double FirstHard(double a, double b, double y, double x) {

	double dividend = sqrt(x + b - a) + log(y);
	double result = dividend / atan(b + a);

	return result;
}