## SciProg Blatt 2
Jan Schnitker


#### 1. Pointer
`int i, *p;`
1. `i + 1` → `int`
- `*p` → `int`
- `*p + 3` → `int`
- `&i == p` → `bool`
- `i == *p` → `bool`
- `&p` → `int**`
- `p+1` → `int*`
- `&p == i` → `bool` but `==(int**,int)` forbidden by `ISO C++`
- `**(&p)` → `int`
- `*p + i > i` → `bool`


#### 2. Destruktor ?
Der Destruktor einer Klasse `C` ist dafür verantwortlich ...
... alle Komponenten von Objekten der Klasse `C`, die auf dem Heap liegen, wegzuräumen.

#### 3. New & Delete
```c
// Reserviert speicher auf dem Heap und gibt die Adresse davon zurück.
// Der Speicher bleibt nach Funktionsende erhalten
int * get_int1(){
  int * p = new int;
  return p;
}
// Erstellt eine lokale Variable auf dem Stack, deren Speicher nach
// Funktionsende gelöscht wird. Die Adresse dieser Variable sollte
// nach Funktionsende nicht mehr für Speicherzugriff verwendet werden.
int * get_int2(){
  int i, * p = &i;
  return p;
}
```

```c
int * p = new int;
*p = 17;
// a) - nicht sinnvoll!
p = 0; // verwerfe Adresse des reservierten Speichers
delete p; // gebe reservierten Speicher bei 0x0 frei.
// Wir haben hier ein Memoryleak erzeugt, da wir den reservierten Speicher nicht
// mehr freigeben können.
// delete 0x0; ist legitimer Code, hilft aber nicht weiter.

// b) - gute Praxis
delete p; // reservierten Speicher freigeben
p = 0; // Hierdurch können wir sicherstellen, dass zukünftige delete p;
// Aufrufe keine Fehler erzeugen und durch p==0 lässt sich generell herausfinden
// ob auf *p zugegriffen werden darf oder nicht.
```

#### 4. Verkettete Liste
1. Ein Pointer mit dem Wert `0` zeigt garantiert nicht auf (reservierten) Speicher. Entsprechend können Speicherzugriffsverletzungen leicht verhindert werden. `delete 0;` ist ebenfalls unschädlich.
4. `List: ->1->2->3`
5. Die Liste wird kopiert, allerdings ist mit Liste nur das Kopfkonstrukt gemeint, nicht die ganzen Nodes, die im Heap liegen. Beim löschen der Kopie stürzt das Programm mit einem `Error: double free [...]` ab. Die first-node wurde mehrfach freigegeben, weil in der Kopie noch ein Pointer darauf verblieb. Ließe sich durch angepassten Copy-Konstruktor vermeiden.

#### 5. Verkette Liste Min/Max
- Gute Testfälle:
  - Löschen von nichtexistenten Nodes
  - Insert vor nichtexistenten Nodes
  - Ob die Nodes tatsächlich `deleted` wurden.
- Seiteneffekte ???
