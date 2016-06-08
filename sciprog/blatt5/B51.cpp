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



