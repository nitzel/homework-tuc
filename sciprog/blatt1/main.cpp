/**
 * @author Jan Schnitker
 * @file main.cpp
 * @desc Homework Blatt1 for SciProg
 * Testing unit for the class Rational.
 * @compile g++ main.cpp Rational.cpp -std=c++11
 *
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
 */

#include <iostream>

#include "Rational.hpp"

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
