## SciProg Blatt 2
Birte Pajunk, Jan Schnitker, Yule Meyer-Olbersleben


#### 1. `shared_ptr` und `weak_ptr`
1. -
2. -
3. Das Problem ist, dass wir nun `shared_ptr` Kreise haben - also zwei Objekte, die sich gegenseitig referenzieren. Dadurch werden diese niemals freigegeben. Führen wir in eine Richtung (z.B. zurück/previous) einen `weak_ptr` ein, werden die Objekte und ihre ManagerObjekte gelöscht.

#### 2. Knobeln
[link](http://stackoverflow.com/questions/16390294/conversion-from-int-to-const-int)


 #### 3. Constness
 `C++
 int foo ( const int & );
 int bar ( int & );
 int main()
 {
  int i = 0;
  int & j = i;
  static const int f = i;
  int * const p = 0;
  p = &i;
  * p = f;
  const int & l = j;
  const int & k = f;
  foo ( j );
  bar ( l );
  foo ( k );
}
`
