#include<iostream>
using namespace std;

const int * bar (){
  return nullptr;
}

void foo (int * const  * const  * const x ) {
  x[0][0][0] = 5;
}


int main()
{
  int ** v = new int*[10];
  v[0] = new int;
  v[1] = new int;
  //v[0] = bar();
  //foo(v);
  foo(&v);
  return 0;
}
