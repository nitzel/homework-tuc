#pragma once
#include "Funktion.h"
#include "Quadratur.h"
class Integrator

{

public:
	double computeQuadratur(Funktion* f, double a, double b, Quadratur* q, int n);

};