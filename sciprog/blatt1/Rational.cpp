/**
 * @author Jan Schnitker
 * @file Rational.cpp
 * @desc Homework Blatt1 for SciProg
 * See Rational.hpp
 */
#include "Rational.hpp"

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
