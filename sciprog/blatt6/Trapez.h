/**
 * @author Birte Pajunk, Jan Schnitker, Yule Meyer-Olbersleben
 * @file Trapez.h
 * @desc Homework Blatt6 for SciProg
 */

#pragma once
#include "Quadratur.h"

class Trapez : public Quadratur
{

public:
	double computeQuadratur(Funktion* f, double a, double b);
};
