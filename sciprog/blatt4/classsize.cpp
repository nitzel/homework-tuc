/**
 * @author Birte Pajunk, Jan Schnitker, Yule Meyer-Olbersleben
 * @file classsize.cpp
 * @desc Homework Blatt4 for SciProg
 */
#include <iostream>

class Empty {
};

class EmptyDerived : public Empty {
};

class NonEmpty : public Empty {
  int m_attr;
};

class Composite {
  Empty a;
  int b;
};

struct Waste {
  char b;
  int a;
  char c;
};


int main(){
  std::cout << "Empty: " << sizeof(Empty) << std::endl;
  std::cout << "EmptyDerived: " << sizeof(EmptyDerived) << std::endl;
  std::cout << "NonEmpty: " << sizeof(NonEmpty) << std::endl;
  std::cout << "Composite: " << sizeof(Composite) << std::endl;
  std::cout << "Waste: " << sizeof(Waste) << std::endl;
}
