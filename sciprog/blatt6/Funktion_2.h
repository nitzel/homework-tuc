#pragma once
#include "Funktion.h"

class Funktion_2: public Funktion
{

public:
	double getY(double x);
	double exactIntegral();
};