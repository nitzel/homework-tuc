/**
 * @author Birte Pajunk, Jan Schnitker, Yule Meyer-Olbersleben
 * @file Trapez.cpp
 * @desc Homework Blatt6 for SciProg
 */

#include "Trapez.h"

double Trapez::computeQuadratur(Funktion* f, double a, double b)
{
	return (b - a) *0.5*(f->getY(a) + f->getY(b));
}
