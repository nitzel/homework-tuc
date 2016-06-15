/**
 * @author Birte Pajunk, Jan Schnitker, Yule Meyer-Olbersleben
 * @file Funktion_2.h
 * @desc Homework Blatt6 for SciProg
 */

#pragma once
#include "Funktion.h"

class Funktion_2: public Funktion
{

public:
	double getY(double x);
	double exactIntegral();
};
