/**
* @author Birte Pajunk, Jan Schnitker, Yule Meyer-Olbersleben
* @file Test.cpp
* @desc Homework Blatt8 for SciProg
* leider haben wir zu Aufgabe 6 ja noch nicht die korrigierte Lösung ... :(
*
* Die Verwendung von statischen Ploymorphismus bietet den Vorteil, 
* dass der Code bereits zur Kompilierzeit ausgewertet wird.
* Bei dynamischen Polymorphismuswird der Code erst zur Laufzeit ausgewertet.
*
* bei timer.hh wird uns bei
* #include <sys/time.h>
* #include <sys/resource.h> und
* #include <unistd.h> der Fehler ausgegeben, dass die Quelle nicht gefunden werden kann ...
* insofern können wir timer.hh nicht verwenden, was insofern nicht schlimm ist, 
* da der Rest eh nicht funktioniert ...
*/
#include "Funktion_1.h"
#include "Funktion_2.h"
#include "Simpson.h"
#include "Trapez.h"
#include "Integrator.h"
#include <iostream>
#include "Quadratur_T.cpp"
#include "Funktion_T.cpp"


void fehlerOrdnung(Funktion* f, Quadratur* q, int n, double a, double b) {

	Integrator integrator;

	double ordnung = abs(log((f->exactIntegral()-integrator.computeQuadratur(f, a, b,q,n))/ (f->exactIntegral() - integrator.computeQuadratur(f, a, b, q, 2*n))))/log(2);
	std::cout << "Ordnung: " << ordnung << std::endl;
}


int main()
{
	double a_f1 = 0;
	double b_f1 = 2.0*3.1415;
	double a_f2 = -3;
	double b_f2 = 13;
	Funktion* f1 = new Funktion_1();
	Funktion* f2 = new Funktion_2();

	Quadratur* simps = new Simpson();
	Quadratur* trap = new Trapez();
	
	Funktion_T<Funktion_1> * f1_T;
	Funktion_T<Funktion_2> * f2_T;
	Quadratur_T <Simpson> * simps_T;
	Quadratur_T <Trapez> * trap_T;

	Integrator integrator;

	int n = 5;
	/* Blatt 8 a)*/
	// es wird gemeckert, dass die Argumente inkompatibel seien ...
	std::cout << "Berechnung der Quadratur von f_1 mit der Simpsonregel via Template:" <<  integrator.computeQuadratur(f1, a_f1, b_f1, simps_T,n) << std::endl;
	std::cout << "Berechnung der Quadratur von f_1 mit der Trapezregel via Template:" << integrator.computeQuadratur(f1, a_f1, b_f1, trap_T, n) << std::endl;
	fehlerOrdnung(f1_T, trap, n, a_f1, b_f1);
	//std::cout << "Berechnung der Quadratur von f_1 mit der Simpsonregel:" <<  integrator.computeQuadratur(f1, a_f1, b_f1,simps,n) << std::endl;
	//std::cout << "Berechnung der Quadratur von f_1 mit der Trapezregel:" << integrator.computeQuadratur(f1, a_f1, b_f1, trap, n) << std::endl;
	//std::cout << "Korrektes Ergebnis von f_1:" << f1->exactIntegral()<< std::endl;
	//std::cout << "Berechnung der Quadratur von f_2 mit der Simpsonregel:" << integrator.computeQuadratur(f2, a_f2, b_f2, simps, n) << std::endl;
	//std::cout << "Berechnung der Quadratur von f_2 mit der Trapezregel:" << integrator.computeQuadratur(f2, a_f2, b_f2, trap, n) << std::endl;
	//std::cout << "Korrektes Ergebnis von f_2:" << f2->exactIntegral() << std::endl;
	//fehlerOrdnung(f1, trap,n, a_f1, b_f1);
	//fehlerOrdnung(f1, simps, n, a_f1, b_f1);

	//fehlerOrdnung(f2, trap, n, a_f2, b_f2);
	//fehlerOrdnung(f2, simps, n, a_f2, b_f2);

	system("PAUSE");
	delete trap;
	delete simps;
	delete f2;
	delete f1;
	return 0;
}