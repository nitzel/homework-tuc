#include <iostream>
using namespace std;

class A{
public:
  char name;
  A(char n){
    name = n;
  }

  void t(int x){
    static int last;
    if(x == 0)
      cout << name << " " << last << endl;
    else
      last = x;
  }
};

int main(){
  A a('a');
  A b('b');
  a.t(5);
  b.t(6);
  a.t(0);
  b.t(0);
  return 0;
}
