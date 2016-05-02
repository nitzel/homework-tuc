/**
 * @author Jan Schnitker
 * @file Rational.hpp
 * @desc Homework Blatt1 for SciProg
 * A class representing fractions / rational numbers.
 * The consist of a numerator and a denominator and offer basic mathematical
 * operators like +,-,*,/,==,+=,-=,*=,/=,!(inverse value) with Rationals
 * and ints. They will always use the most simple form, though there is no
 * guarantee for negative numbers to have the negative sign on the numerator
 * or the denominator.
 *
 * 1. Was ist eine geeignete Datenstruktur für rationale Zahlen?
 * * Eine geeigente Datenstruktur zur Repräsentation Rationaler Zahlen
 * * besteht aus zwei Integern, die Zähler und Nenner repräsentieren.
 * * Soll viel mit rationalen Zahlen gerechnet werden, empfiehlt sich die
 * * implementierung der entsprechenden Operationen in einer Klasse.
 * 2. - 6.
 * * Finden sich in main.cpp, Rational.cpp und Rational.hpp
 */

#ifndef __H__RATIONAL__
#define __H__RATIONAL__

#include <iostream>

class Rational
{
public:
  static int gcd(int a, int b);
  // getters
  void print() const;
  int numerator() const;
  int denominator() const;
  // operators
  Rational operator!() const; // inverse
  Rational& operator+=(const Rational &rhd);
  Rational& operator-=(const Rational &rhd);
  Rational& operator*=(const Rational &rhd);
  Rational& operator/=(const Rational &rhd);
  bool     operator==(const Rational &rhd) const;
  Rational operator+(const Rational &rhd) const;
  Rational operator-(const Rational &rhd) const;
  Rational operator*(const Rational &rhd) const;
  Rational operator/(const Rational &rhd) const;
  // constructors
  Rational()          : Rational(    1, 1){}; // default
  Rational(int value) : Rational(value, 1){}; // from int
  Rational(const Rational *r) : Rational(*r){}; // copy constr
  Rational(const Rational &r) : Rational(r.numerator(), r.denominator()){};
  Rational(int numerator, int denominator);
private:
  int m_numerator;
  int m_denominator;

  void simplify();

};

Rational operator+(const int &lhd, const Rational &rhd);
Rational operator+(const Rational &lhd, const int &rhd);
Rational operator-(const int &lhd, const Rational &rhd);
Rational operator-(const Rational &lhd, const int &rhd);
Rational operator*(const int &lhd, const Rational &rhd);
Rational operator*(const Rational &lhd, const int &rhd);
Rational operator/(const int &lhd, const Rational &rhd);
Rational operator/(const Rational &lhd, const int &rhd);

#endif
