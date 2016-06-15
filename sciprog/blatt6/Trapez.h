#pragma once
#include "Quadratur.h"

class Trapez : public Quadratur
{

public:
	double computeQuadratur(Funktion* f, double a, double b);
};