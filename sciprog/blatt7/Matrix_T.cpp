#include "matrix_T.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>

// Set number of matrix rows and columns and 
// initialize matrix elements with a given double value
template <typename T> void Matrix_T <T>::Resize(size_t numRows, size_t numCols, const T &value)
{
	a_.resize(numRows*numCols);
	for (size_t i = 0; i<a_.size(); ++i)
		a_[i] = value;
	numRows_ = numRows;
	numCols_ = numCols;
}

// Access matrix element at position (i,j)
template <typename T> T &Matrix_T <T>::operator()(size_t i, size_t j)
{
	if ((i<0) || (i >= numRows_))
	{
		std::cerr << "Illegal row index " << i;
		std::cerr << " valid range is (0:" << numRows_ - 1 << ")";
		std::cerr << std::endl;
		exit(EXIT_FAILURE);
	}
	if ((j<0) || (j >= numCols_))
	{
		std::cerr << "Illegal column index " << j;
		std::cerr << " valid range is (0:" << numCols_ - 1 << ")";
		std::cerr << std::endl;
		exit(EXIT_FAILURE);
	}
	return a_[i*numCols_ + j];
}

// Access matrix element at position (i,j)
template <typename T> T Matrix_T <T>::operator()(size_t i, size_t j) const
{
	if ((i<0) || (i >= numRows_))
	{
		std::cerr << "Illegal row index " << i;
		std::cerr << " valid range is (0:" << numRows_ - 1 << ")";
		std::cerr << std::endl;
		exit(EXIT_FAILURE);
	}
	if ((j<0) || (j >= numCols_))
	{
		std::cerr << "Illegal column index " << j;
		std::cerr << " valid range is (0:" << numCols_ - 1 << ")";
		std::cerr << std::endl;
		exit(EXIT_FAILURE);
	}
	return a_[i*numCols_ + j];
}

// Output matrix content
template <typename T> void Matrix_T <T>::Print() const
{
	std::cout << "(" << numRows_ << "x";
	std::cout << numCols_ << ") matrix:" << std::endl;
	for (size_t i = 0; i<numRows_; ++i)
	{
		std::cout << std::setprecision(3);
		for (size_t j = 0; j<numCols_; ++j)
			std::cout << std::setw(5) << a_[i*numCols_ + j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

// Arithmetic functions 

// Multiplication by value x
template <typename T> Matrix_T <T> &Matrix_T <T>::operator*=(double x)
{
	for (size_t i = 0; i<a_.size(); ++i)
		a_[i] *= x;

	return *this;
}

// Addition
template <typename T> Matrix_T <T> &Matrix_T <T>::operator+=(const Matrix_T &x)
{
	if ((x.numRows_ != numRows_) || (x.numCols_ != numCols_))
	{
		std::cerr << "Dimensions of matrix a (" << numRows_
			<< "x" << numCols_ << ") and matrix x ("
			<< numRows_ << "x" << numCols_ << ") do not match!";
		exit(EXIT_FAILURE);
	}
	for (size_t i = 0; i<a_.size(); ++i)
		a_[i] += x.a_[i];
	return *this;
}


// More arithmetic functions
template <typename T> Matrix_T <T> operator*(const Matrix_T<T> &a, double x)
{
	Matrix_T<T> temp(a);
	temp *= x;
	return temp;
}

template <typename T> Matrix_T <T> operator*(double x, const Matrix_T<T> &a)
{
	Matrix_T<T> temp(a);
	temp *= x;
	return temp;
}

// Concatenate
template <typename T> Matrix_T <T> operator+(const  Matrix_T<T> &a, const Matrix_T<T> &b)
{
	Matrix_T <T>temp(a);
	temp += b;
	return temp;
}
