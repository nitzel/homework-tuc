##SciProg Blatt 4

Birte Pajunk, Jan Schnitker, Yule Meyer-Olbersleben
#### 1. Leere-Basisklassen-Optimierung

| Class           | Bytes |
| :-------------- | ----: |
| Empty           |     1 |
| EmptyDerived    |     1 |
| NonEmpty        |     1 |
| Composite(int)  |     8 |
| Composite(char) |     2 |
1. Beanspruchte `Empty` keinen Speicherplatz, hätten Instanzen von `Composite` für die beiden Attribute `a` und `b` dieselben Adressen.
2. Die Größe von Objekten des Klassentyps `Composit` ändert sich von **8 Bytes** zu **2 Bytes**, wenn `b` vom Typ `int` nach `char` wechselt. Vermutlich hängt das damit zusammen, dass Variablen entsprechend ihrer Größe im Speicher justiert (aligned) werden - um schnellere Zugriffszeiten zu gewährleisten. Um sie kleiner zu halten wird von Groß nach Klein sortiert deklariert oder so, dass die entsprechende Schrittgröße genau aufgefüllt wird. Compilerabhängig gibt es auch Möglichkeiten, diese Geschwindigkeitsoptimierung auszuschalten.
```c++
struct Waste {
  char b; // 1 byte
          // 3 bytes unused
  int a;  // 4 bytes
  char c; // 1 byte
          // 3 bytes unused
};
struct Better {
  char c; // 1 byte
  char b; // 1 byte
          // 2 bytes unused
  int a;  // 4 bytes
};
struct MaybeEvenBetter {
  int a;  // 4 bytes
  short x;// 2 bytes - maybe used
  char c; // 1 byte
  char b; // 1 byte
};
//sizeof(Waste)  = 16 Bytes, 6 unused;
//sizeof(Better) = 8 Bytes, 2 unused;
//sizeof(GoMaybeEvenBetter) = 8 Bytes, 0 unused
```

#### 2. Vererbung und Komposition
###### Programmausgabe: 
norm is 5.09902
vector is [1, 3, 4]
#### 3. Vererbung und Funktionen
```c++
#include<iostream>

class A {
  public: void foo() const { std::cout<<"A::foo"<<std::endl; }
};

class B : public A {
  public: void foo() { std::cout<<"B::foo"<<std::endl; }
};

class C : private B { // 2. class C : public B {
  public: void bar() { foo();}
};

void test(const A& a) {
  a.foo();
}

int main() {
  A a; B b; C c;
  a.foo();
  b.foo();
  test(b);
  c.bar();
  test(c); // 1. Entferne diese Zeile
}
```
Um das Programm lauffähig zu machen, wird entweder Änderung `1.` durchgeführt oder `2.`.
Die Ausgaben sind dann Folgende:
```c++
A::foo // 1. & 2.
B::foo // 1. & 2.
A::foo // 1. & 2.
B::foo // 1. & 2.
A::foo // 2.
```
1. `a.foo()` ruft `A::foo()` auf
- `b.foo()` ruft `B::foo()` auf
- `test(b)` konvertiert `b` in ein `const A` und ruft entsprechend `A::foo()` auf
- `c.bar()` ruft das von `B` an `C` vererbte `B::foo()` auf
- `test(c)` konvertiert `c` in ein `const A` (wenn public vererbt wurde) und ruft entsprechend `A::foo()` auf
