/**
* @author Birte Pajunk, Jan Schnitker, Yule Meyer-Olbersleben
* @file Matrix_T.h
* @desc Homework Blatt7 for SciProg
* Abgabe besteht aus den Aufgabenteilen 1 und 2. 
* Die Abgabe ist leider Fehlerhaft ... :(
*/

#pragma once
#include <iomanip>
#include <iostream>
#include <vector>

/**
* Matrix Class representing matrices of double values
*/

template <typename T> class Matrix_T
{
public:

	// Set number of matrix rows and columns and initialize its elements with value
	void Resize(size_t numRows, size_t numCols, const T &value = T());

	// Access matrix element at position (i,j)
	T &operator()(size_t i, size_t j);
	T operator()(size_t i, size_t j) const;

	// Arithmetic functions 
	template <typename T> Matrix_T <T> &Matrix_T <T>::operator*=(T x);
	template <typename T> Matrix_T <T> &Matrix_T <T>::operator+=(const Matrix_T &x);

	// Output matrix content
	void Print() const;

	// Returns number of matrix raws
	size_t Rows() const
	{
		return numRows_;
	}

	// Returns number of matrix columns
	size_t Cols() const
	{
		return numCols_;
	}


	// Constructors
	Matrix_T(size_t numRows = 0, size_t numCols = 0, const T &value = T()) :
		a_(numRows), numRows_(numRows), numCols_(numCols)
	{
		a_.resize(numRows_*numCols_);
		if (((numCols == 0) && (numRows != 0)) || ((numCols != 0) && (numRows == 0)))
		{
			numRows_ = 0;
			numCols_ = 0;
		}
		else
		{
			numRows_ = numRows;
			numCols_ = numCols;
		}
		for (size_t j = 0; j<a_.size(); ++j)
			a_[j] = value;
	}

private:
	// matrix elements
	std::vector<T> a_;
	// number of rows
	size_t numRows_;
	// number of columns
	size_t numCols_;
};

// More arithmetic functions
template <typename T> Matrix_T<T>  operator*(const Matrix_T<T> &a, T x);
template <typename T> Matrix_T<T>  operator*(T x, const Matrix_T< T> &a);
template <typename T> Matrix_T<T> operator+(const Matrix_T<T> &a, const Matrix_T < T>&b);

