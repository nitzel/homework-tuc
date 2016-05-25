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

#### 3. Vererbung und Funktionen
