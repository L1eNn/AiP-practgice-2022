#include "17.2.2.h"
#include <cmath>

double SecondMedium() {
	const double x = 0.9;
	const double t = 2.;

	double logX = log10(abs(x));
	double b = logX * logX;

	double a = t * x + abs(sqrt(b));

	double ab = a + pow(b, 3);
	double cos3Dividend = 3 * cos(ab) - cos(3 * ab);
	double y = cos3Dividend / 4;

	return y;
}