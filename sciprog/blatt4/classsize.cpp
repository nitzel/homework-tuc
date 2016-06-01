/**
 * @author Birte Pajunk, Jan Schnitker, Yule Meyer-Olbersleben
 * @file classsize.cpp
 * @desc Homework Blatt4 for SciProg
 */
#include <iostream>

using namespace std;

class Empty {
};

class EmptyDerived : public Empty {
};

class NonEmpty : public Empty {
  int m_attr;
};

class Composite {
  int b;
  Empty a;
};
struct Waste {
  char b;
  int a;
  char c;
};


int main(){
  cout << sizeof(Empty) << endl;
  cout << sizeof(EmptyDerived) << endl;
  cout << sizeof(NonEmpty) << endl;
  cout << sizeof(Composite) << endl;
  Composite c;
  cout << sizeof(c) << endl;
  cout << sizeof(Waste) << endl;
}
