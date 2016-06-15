#include "Funktion_2.h"
#include <cmath>
#include <iostream>

double Funktion_2::getY(double x) {
	return  2*(x*x)+ 5;
}

double Funktion_2::exactIntegral() {
	return 1562.7;
	
}
