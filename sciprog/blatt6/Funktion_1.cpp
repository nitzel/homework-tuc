/**
 * @author Birte Pajunk, Jan Schnitker, Yule Meyer-Olbersleben
 * @file Funktion_1.cpp
 * @desc Homework Blatt6 for SciProg
 */

#include "Funktion_1.h"
#include <cmath>


double Funktion_1::getY(double x) {
	return  x/3.1415 * sin(x);
	}

double Funktion_1::exactIntegral() {
	return -2.0;
}
