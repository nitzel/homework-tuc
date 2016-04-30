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

void testListMinMax();

int main(){
  cout  << "SciProg Blatt 2 - Jan Schnitker" << endl << endl;

  testListMinMax();
  return 0;
}

void testListMinMax(){
  // testfälle
  // destruktor teilt über cout mit, welche nodes gelöscht werden.
  // first und next funktionieren, weil print funktioniert
  // Testfall aus hausaufgabe
  {
    cout << "# Test Blatt2 4.4" << endl;
    List list;
    list.append(2);
    list.append(3);
    list.print();
    list.insert(list.first(), 1);
    list.print();
  }
  // konstruktor (mit array als parameter) (testet gleich auch append)
  // insert vor existierendes element
  // insert vor nicht-existierendes element
  // erase existierendes element
  // erase nicht-existierendes element
  {
    cout << endl << "# Test Constructor" << endl;
    const int a[] = {0,1,2,4,5,6}; const int alen = 6;
    List l(a, alen);
    l.print();

    cout << endl << "# Test Insert 3 before existing node 4" << endl;
    Node * four = l.next(l.next(l.next(l.first())));
    cout << "Node4: @"<< four << " = " << four->value << endl;
    l.insert(four, 3);
    l.print();
    cout << endl << "# Test Erase existing node 4" << endl;
    l.erase(four);
    l.print();
    cout << endl << "# Test Erase non-existing node 4" << endl;
    l.erase(new Node(4));
    l.print();
    cout << endl << "# Test Insert 123 before non-existing node 4" << endl;
    l.insert(new Node(4), 123);
    l.print();

    cout << endl << "# Test Erasing all nodes" << endl;
    while(l.first() != nullptr){
      cout << "Erase " << l.first()->value << " // ";
      l.erase(l.first());
      l.print();
    }
  }
}
