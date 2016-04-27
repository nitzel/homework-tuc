/**
 * @author Jan Schnitker
 * @file Rational.hpp
 * @compile g++ blatt1.cpp -std=c++11
 * @output
 SciProg Blatt 1 - Jan Schnitker

 f1, f2, and f3:
 1/-4
 4/3
 0/1

 The calculations compared to the expected results:
 13/12 == 13/12
 1/-3 == 1/-3
 16/3 == 16/3
 19/3 == 19/3
 -3/1 == -3/1
 3/-2 == 3/-2
 -3/16 == -3/16

 It passed all tests!

 @desc Homework Blatt1 for SciProg
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
  Rational operator+=(const Rational &rhd);
  Rational operator-=(const Rational &rhd);
  Rational operator*=(const Rational &rhd);
  Rational operator/=(const Rational &rhd);
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

/**
 * @author Jan Schnitker
 * @file Rational.cpp
 * @desc Homework Blatt1 for SciProg
 * See Rational.hpp
 */
//#include "Rational.hpp" // use if in separate file

/**
 * Greatest common divisor of a and b, via euclids algorithm
 */
int Rational::gcd(int a, int b) {
  if(b == 0) return a;     // if modulo was 0, return previous
  return Rational::gcd(b, a%b); // calculate next modulo + recurse
}
/**
 * Choose denominator!=0 or the program will quit!
 */
Rational::Rational(int numerator, int denominator) {
  if(denominator == 0){
    // not the cleanest way, but at least quitting with a complaint
    std::cout << "Error, denominator is 0" << std::endl;
    exit(5);
  }
  m_numerator = numerator;
  m_denominator = denominator;
  simplify();
}
/**
 * "simplifies" a rational number, dividing it by the numerators and
 * denominators gcd.
 */
void Rational::simplify() {
  int tmpGcd = Rational::gcd(numerator(), denominator());
  m_numerator = numerator() / tmpGcd;
  m_denominator = denominator() / tmpGcd;
}

/// +
Rational Rational::operator+(const Rational &rhd) const {
  Rational lhd(this);
  lhd+=rhd;
  return lhd;
}
Rational Rational::operator+=(const Rational &rhd) {
  // extend to a common denominator and sum up the numerators
  m_numerator = numerator()*rhd.denominator() + denominator()*rhd.numerator();
  m_denominator = denominator() * rhd.denominator(); // 2nd step!
  simplify();
}
/// -
Rational Rational::operator-(const Rational &rhd) const {
  Rational lhd(this);
  lhd-=rhd;
  return lhd;
}
Rational Rational::operator-=(const Rational &rhd) {
  *this += -1 * rhd;
}
/// *
Rational Rational::operator*(const Rational &rhd) const {
  Rational lhd(this);
  lhd*=rhd;
  return lhd;
}
Rational Rational::operator*=(const Rational &rhd) {
  m_numerator = numerator() * rhd.numerator();
  m_denominator = denominator() * rhd.denominator();
  simplify();
}
/// /
Rational Rational::operator/(const Rational &rhd) const {
  Rational lhd(this);
  lhd/=rhd;
  return lhd;
}
Rational Rational::operator/=(const Rational &rhd) {
  *this *= !rhd; // multiply with inverse
}
/// == ->  (a,b)==(a,b) || (a,b)==(-a,-b)
bool Rational::operator==(const Rational &rhd) const {
  return
     (numerator() == rhd.numerator() && denominator() == rhd.denominator())
  || (numerator() ==-rhd.numerator() && denominator() ==-rhd.denominator());

}
/// ! inverse value (Kehrwert)
Rational Rational::operator!() const {
  return Rational(denominator(), numerator());
}
// get the numerator
int Rational::numerator() const {
    return m_numerator;
}
// get the denominator
int Rational::denominator() const {
    return m_denominator;
}
// print as a/b
void Rational::print() const {
  // I'd prefer (a/b) over a/b:
  //std::cout << "(" << numerator() << "/" << denominator() << ")";
  std::cout << numerator() << "/" << denominator();
}


// mathematical operators for Rationals and Integers,
// merely converting the Integers to a Rational and
// then performing a Rational operation.
Rational operator+(const int &lhd, const Rational &rhd){
  return Rational(lhd) + rhd;
}
Rational operator+(const Rational &lhd, const int &rhd){
  return rhd + lhd;
}
Rational operator-(const int &lhd, const Rational &rhd){
  return Rational(lhd) - rhd;
}
Rational operator-(const Rational &lhd, const int &rhd){
  return rhd - lhd;
}
Rational operator*(const int &lhd, const Rational &rhd){
  return Rational(lhd) * rhd;
}
Rational operator*(const Rational &lhd, const int &rhd){
  return rhd * lhd;
}
Rational operator/(const int &lhd, const Rational &rhd){
  return Rational(lhd) / rhd;
}
Rational operator/(const Rational &lhd, const int &rhd){
  return rhd / lhd;
}


/**
 * @author Jan Schnitker
 * @file main.cpp
 * @desc Homework Blatt1 for SciProg
 * Testing unit for the class Rational.
 */

#include <iostream>

//#include "Rational.hpp" // use if in separate file

using namespace std;

int main(){
  cout  << "SciProg Blatt 1 - Jan Schnitker" << endl << endl;

  Rational a(-3, 12);
  Rational b(4,  3);
  Rational c(0, 1);

  cout << "f1, f2, and f3:" << endl;
  a.print(); cout << endl;
  b.print(); cout << endl;
  c.print(); cout << endl << endl;

  // the correct answers
  const Rational facts[] = {
    Rational(13,12),  Rational(-1,3), Rational(16,3),
    Rational(19,3),   Rational(-3,1), Rational(-3,2),
    Rational(-3,16)
  };
  // results calculated with our methods
  Rational results[7]{
    a + b,    a * b,    4 + b,
    b + 5,    12 * a,   a * 6,
    a / b
  };

  int fails = 0; // the # incorrect results
  cout << "The calculations compared to the expected results:" << endl;
  for(int i = 0; i<7; i++){
    results[i].print();
    if(results[i] == facts[i]) // result was correct
      cout << " == ";
    else {                     // or incorrect
      cout << " != ";
      fails++;
    }
    facts[i].print();
    cout << endl;
  }
  if(fails)
    cout << endl << fails << " / 7 operations failed" << endl;
  else
    cout << endl << "It passed all tests!" << endl;
}
