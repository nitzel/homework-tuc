#pragma once
#include <iostream>
class Funktion

{

public:
	virtual double getY(double x) = 0;
	virtual double exactIntegral() = 0;
	void integrationInterval(double& l, double& r) {
		std::cout << "Linke Intervallgrenze:" << l << ", rechte Intervallgrenze:" << r << std::endl;
	}
};
