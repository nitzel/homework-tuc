## SciProg Blatt 2
Birte Pajunk, Jan Schnitker, Yule Meyer-Olbersleben


#### 1. `shared_ptr` und `weak_ptr`
1. Ok :)
2. Beim Löschen der Liste werden in der normalen Reihenfolge die Destruktoren aufgerufen, d.h. bei Liste [1,2,3,4,5] in aufsteigender Reihenfolge. In derselben Reihenfolge sollte auch der Speicher freigegeben werden. Das Manager-Objekt hat ja normalerweise nur eine Referenz zu verwalten.
  - Schönerweise gehen Listen, die sich Elemente Teilen, nicht mehr nach dem Löschen einer Liste kaputt. Das Caching funktionert allerdings bei solchen Listen nur bedingt.
3. Das Problem ist, dass wir nun `shared_ptr` Kreise haben - also zwei Objekte, die sich gegenseitig referenzieren. Dadurch werden diese niemals freigegeben. Führen wir in eine Richtung (z.B. zurück/previous) einen `weak_ptr` ein, werden die Objekte und ihre ManagerObjekte gelöscht.
  - Ein weiteres Problem taucht bei Listen auf, die sich Elemente teilen:
  `L1 = [a,b,Z], L2 = [x,y,Z]`. Wird in einer Liste bis zu `Z` und dann zurückgegangen, so landet man eventuell in der anderen Liste.
4. Insgesamt kann das nutzen von Nodes in mehreren Listen ein Chaos verursachen, ist also zu vermeiden. Das kann aber nur passieren, wenn dem Code böse mitgespielt wird. Werden nur `List` und `Node` verwendet, passiert das nicht.

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
