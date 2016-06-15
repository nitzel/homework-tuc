#pragma once
#include "Funktion.h"
class Quadratur

{

public:
	virtual double computeQuadratur(Funktion* f, double a, double b ) = 0;
};