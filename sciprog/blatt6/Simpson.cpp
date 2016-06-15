#include "Simpson.h"

double Simpson :: computeQuadratur(Funktion* f, double a, double b)
{
	return (b - a) / 6.0*(f->getY(a) + 4.0*f->getY((a + b)*0.5) + f->getY(b));
}