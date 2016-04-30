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

#include "List.hpp"
#include "Node.hpp"

using namespace std;

int main(){
  cout  << "SciProg Blatt 2 - Jan Schnitker" << endl << endl;

  List list;
  list.append(2);
  list.append(3);
  list.print();
  list.insert(list.first(), 1);
  list.print();
  List list2 = list;
  return 0;
}
