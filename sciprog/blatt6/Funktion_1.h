/**
 * @author Birte Pajunk, Jan Schnitker, Yule Meyer-Olbersleben
 * @file Funktion_1.h
 * @desc Homework Blatt6 for SciProg
 */

#pragma once
#include "Funktion.h"

class Funktion_1 : public Funktion
{

public:
	double getY(double x);
	double exactIntegral();
};
