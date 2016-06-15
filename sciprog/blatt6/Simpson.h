#pragma once
#include "Quadratur.h"

class Simpson : public Quadratur
{

public:
	double computeQuadratur(Funktion* f, double a, double b);
};