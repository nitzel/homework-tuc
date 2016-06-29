/**
* @author Birte Pajunk, Jan Schnitker, Yule Meyer-Olbersleben
* @file Funktion_T.cpp
* @desc Homework Blatt8 for SciProg
* vermutlich nicht das, was gefordert war...
*/
template <class Funktion>
class Funktion_T
{
public:
	double getY(double x) {
		return  Funktion.getY;
	}

	double exactIntegral() {
		return Funktion.exactIntegral;
	}
};