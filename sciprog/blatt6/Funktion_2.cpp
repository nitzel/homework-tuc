/**
 * @author Birte Pajunk, Jan Schnitker, Yule Meyer-Olbersleben
 * @file Funktion_2.cpp
 * @desc Homework Blatt6 for SciProg
 */

#include "Funktion_2.h"
#include <cmath>
#include <iostream>

double Funktion_2::getY(double x) {
	return  2*(x*x)+ 5;
}

double Funktion_2::exactIntegral() {
	return 1562.7;
	
}
