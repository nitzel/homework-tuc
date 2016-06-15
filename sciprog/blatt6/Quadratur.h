/**
 * @author Birte Pajunk, Jan Schnitker, Yule Meyer-Olbersleben
 * @file Quadratur.cpp
 * @desc Homework Blatt6 for SciProg
 */

#pragma once
#include "Funktion.h"
class Quadratur

{

public:
	virtual double computeQuadratur(Funktion* f, double a, double b ) = 0;
};
