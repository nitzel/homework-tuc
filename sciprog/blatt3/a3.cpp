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
