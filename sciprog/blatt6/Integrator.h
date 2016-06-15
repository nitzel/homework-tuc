/**
 * @author Birte Pajunk, Jan Schnitker, Yule Meyer-Olbersleben
 * @file Integrator.h
 * @desc Homework Blatt6 for SciProg
 */

#pragma once
#include "Funktion.h"
#include "Quadratur.h"
class Integrator

{

public:
	double computeQuadratur(Funktion* f, double a, double b, Quadratur* q, int n);

};
