/**
 * @author Birte Pajunk, Jan Schnitker, Yule Meyer-Olbersleben
 * @file Simpson.h
 * @desc Homework Blatt6 for SciProg
 */

#pragma once
#include "Quadratur.h"

class Simpson : public Quadratur
{

public:
	double computeQuadratur(Funktion* f, double a, double b);
};
