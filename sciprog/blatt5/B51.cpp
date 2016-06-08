**
 * @author Birte Pajunk, Jan Schnitker, Yule Meyer-Olbersleben
 * @file B51.cpp
 * @desc Homework Blatt5.1 for SciProg
 *
 * wenn eine Exception geworfen wird, werden alle Destructoren aufgerufen
 * -> Freigabe der Ressourcen sollte in den Destructoren geregelt sein und
 * somit sollte der Speicher beim Wurf einer Exception wieder freigegeben werden.
 * Vermutung warum das unter 'Note' beschriebene Verhalten sinnvoll ist:
 * Wenn eine Exception in einem Destructor aufgerufen wird, werden alle
 * Destructoren aufgerufen - auch nochmal der aus dem die Exception kam,
 * bzw. wenn eine Exception geworfen und in Folge dessen ein Destructor
 * aufgerufen wird, in dem eine weitere Exception geworfen wird, kommt es zu
 * einem unvorhersehbaren Verhalten, da auf den Destructor eines bereits
 * gelöschten Objekts zugegriffen wird.

 */
#include <iostream>
#include <string>
#include <exception>

class my_exception : std::exception {
std::string errorMessage;

public:
    my_exception (std::string errorMessage){
      this->errorMessage = errorMessage;
}
~my_exception () {}
virtual const char* what() {
return errorMessage.c_str();
}
};
// class Foo throws in the destructor
class Foo {
public :
     ~Foo () {
        throw my_exception("Foo_exception");
     }
};

// class Bar throws in the constructor
class Bar {
public :
     Bar () {
        throw my_exception("Bar exception");
     }
};

int main ()
try {
     Foo f;
     Bar b;
}
catch (const std::exception & e){
     std::cout << "ERROR:" << e.what() << std::endl;
}



