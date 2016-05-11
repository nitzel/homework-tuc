/**
 * @author Birte Pajunk, Jan Schnitker, Yule Meyer-Olbersleben
 * @file main.cpp
 * @desc Homework Blatt2 for SciProg
 * Testing unit for a linked list class
 * @compile g++ main.cpp List.cpp -std=c++11
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
  // Adding a bunch of numbers and finding the min/max of the list
  // we'll insert the next number in front of the previous lists max/min
  {
    cout << endl << "# Test findMin/findMax after inserting" << endl;
    const int a[] = {5,6,4,7,3,8,2};
    const int alen = 7;
    List l;
    l.append(a[0]);
    for(int i = 1; i<alen; i++){
      Node * where;
      if(i%2) where = l.findMax();
      else where = l.findMin();
      cout << (i%2?"Max: ":"Min: ") << where->value << endl;
      l.insert(where, a[i]);
      l.print();
    }
    cout << endl << "# Test findMin/findMax Caching" << endl;
    for(int i=0; i<2; i++){
      cout << "Min " << l.findMin()->value << endl;
      cout << "Max " << l.findMax()->value << endl;
    }
  }

}
