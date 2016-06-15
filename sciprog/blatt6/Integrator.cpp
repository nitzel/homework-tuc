
#include "Integrator.h"


double Integrator::computeQuadratur(Funktion* f, double a, double b, Quadratur* q, int n){
	double deltaX = (b - a) / n;
	double result = 0;
	// Aufteilung der Intervallgrenzen in Teilintervalle und  Bildung der Summe über die Integrale der Teilintervalle.
	for (int i = 0; i < n; i++)
	{
		double left = a + i*deltaX;
		double right = left + deltaX;
		result += q->computeQuadratur(f,left, right);
	}
	return result;
}