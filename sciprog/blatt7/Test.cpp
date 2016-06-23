/**
* @author Birte Pajunk, Jan Schnitker, Yule Meyer-Olbersleben
* @file Test.cpp
* @desc Homework Blatt7 for SciProg
* 
*/
#include <iostream>
#include <cstdlib>
#include "Matrix_T.cpp"
int main()
{
	// Define a matrix A
	Matrix_T <int> A(4, 4);
	//Matrix_T <char*> S(4, 4);
	std::cout << "A : " << std::endl;
	A.Print();

	// Define a square tridiagonal matrix A
	for (size_t i = 0; i<A.Rows(); ++i)
		A(i, i) = 2;
	for (size_t i = 0; i<A.Rows() - 1; ++i)
		A(i + 1, i) = A(i, i + 1) = -1;

	// Define a matrix C of same content as A
	Matrix_T <int> C(A);
	std::cout << "C : " << std::endl;
	C.Print();
	int i = 2;
	A = 2 * C;
	std::cout << "A = 2 * C" << std::endl;
	A.Print();

	A = C*2;
	std::cout << "A = C * 2." << std::endl;
	A.Print();

	A = C + A;
	std::cout << "A = C + A" << std::endl;
	A.Print();
	const int a = 0;
	// Resize A
	A.Resize(5, 5,a);
	for (size_t i = 0; i<A.Rows(); ++i)
		A(i, i) = 2;
	for (size_t i = 0; i<A.Rows() - 1; ++i)
		A(i + 1, i) = A(i, i + 1) = -1;

	// Print A
	std::cout << "A :" << std::endl;
	A.Print();

}
