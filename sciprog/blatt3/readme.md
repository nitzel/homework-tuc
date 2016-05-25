## SciProg Blatt 3
Birte Pajunk, Jan Schnitker, Yule Meyer-Olbersleben


#### 1. `shared_ptr` und `weak_ptr`
1. Ok :)
2. Beim Löschen der Liste werden in der normalen Reihenfolge die Destruktoren aufgerufen, d.h. bei Liste [1,2,3,4,5] in aufsteigender Reihenfolge. In derselben Reihenfolge sollte auch der Speicher freigegeben werden. Das Manager-Objekt hat ja normalerweise nur eine Referenz zu verwalten.
  - Schönerweise gehen Listen, die sich Elemente teilen, nicht mehr nach dem Löschen einer Liste kaputt. Das Caching funktionert allerdings bei solchen Listen nur bedingt.
  - Die Manager-Objekte werden in umgekehrter Reihenfolge gelöscht
  - Wenn noch `shared_ptr` ausserhalb der Liste auf Nodes zeigen, bleibt die Liste ab diesen erhalten, solange die Zeiger bestehen.
3. Das Problem ist, dass wir nun `shared_ptr` Kreise haben - also zwei Objekte, die sich gegenseitig referenzieren. Dadurch werden diese niemals freigegeben. Führen wir in eine Richtung (z.B. zurück/previous) einen `weak_ptr` ein, werden die Objekte und ihre ManagerObjekte gelöscht.
4. (Ein weiteres Problem taucht bei Listen auf, die sich Elemente teilen:
  `L1 = [a,b,Z], L2 = [x,y,Z]`. Wird in einer Liste bis zu `Z` und dann zurückgegangen, so landet man eventuell in der anderen Liste. Insgesamt kann das nutzen von Nodes in mehreren Listen ein Chaos verursachen, ist also zu vermeiden. Das kann aber nur passieren, wenn dem Code böse mitgespielt wird. Werden nur `List` und `Node` verwendet, passiert das nicht.)

#### 2. Knobeln
Beim impliziten casten von `int**` nach `const int**` kann ein variabler Pointer auf eine Konstante gesetzt werden (sozusagen indirektes Zuweisen von `const int*` nach `int*`). Diese kann dann ohne Compiler-Error über den dereferenzierten Pointer verändert werden.
Um diesem undefinierten Verhalten vorzubeugen wird der implizite cast generell verboten - und kann entsprechend auch nicht bei der Übergabe von Parametern an Methoden genutzt werden.

Das zweite Programm hat eine Zuweisung von `const int *` nach `int *` was wir - wäre erstes Programm legal - wie oben beschrieben, indirekt machen könnten. Über den Pointer `v[0]` ließe sich dann die Konstante ändern.
Siehe dazu auch [link](https://web.archive.org/web/20130227025936/http://www.parashift.com/c++-faq-lite/constptrptr-conversion.html)

#### 3. Constness
 ```C++
 int foo ( const int & ){};
 int bar ( int & ){};
 int main()
 {
  int i = 0;
  int & j = i;
  static const int f = i;
  int * const p = 0;
  // p = &i; // geht nicht weil der pointer const ist.
  // * p = f; // ist legal, ergibt aber ein SEGFAULT
  const int & l = j;
  const int & k = f;
  foo ( j );
  // bar ( l ); // l ist const, bar nicht aber non-const als parameter
  foo ( k );
 }
```
