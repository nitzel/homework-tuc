/**
 * @author Birte Pajunk, Jan Schnitker, Yule Meyer-Olbersleben
 * @file Simpson.cpp
 * @desc Homework Blatt6 for SciProg
 */

#include "Simpson.h"

double Simpson :: computeQuadratur(Funktion* f, double a, double b)
{
	return (b - a) / 6.0*(f->getY(a) + 4.0*f->getY((a + b)*0.5) + f->getY(b));
}
