/**
 * @author Birte Pajunk, Jan Schnitker, Yule Meyer-Olbersleben
 * @file B5U3.cpp
 * @desc Homework Blatt5.3 for SciProg
 * Das ist vermutlich nicht die Lösung, die erwartet wurde - aber
 * weil im Script etwas unmaintainable Code gezeigt wurde, haben
 * wir versucht, den gegebenen Java Code möglichst nicht zu verändern.
 * Im Ausgleich gibt es eine Reihe bösartiger defines.
 *
 * Das Java-Programm ruft vermutlich rekursiv die aim-Methode des jeweiligen
 * target Objekts auf, d.h. der Ball wird "hin und hergeworfen und gefangen".
 * Zumindest im C++ gibt es irgendwann ein SEGFAULT, vielleicht
 * weil der Stack voll ist.
 */
#include<iostream> // for std::cout test
#include<string>
#define null nullptr
#define extends : // extends Throwable -> std::string. could've dropped the whole
#define Throwable std::string // phrase but like this we even have inheriance
#define class ;struct // all members&methods are public. semicolon after class-def
#define public ; // simocolon after class-def necessary in c++
#define static
#define new *new // new Ball() now is an object, not a pointer
#define void int // void main -> int main
#define String          // String[] args -> [](){} (lambda function)
#define args (){}
#define main(X) main() // main(lambda_t) -> main()
#define this (*this) // this.target -> (*this).target
#define child(X) child(&X)

// Except for two `*` and one `&` and the main-function the Code is quite java-ish :)
class Ball extends Throwable {}

class P {
  P *target;    // :(
  P(P *target){ // :(
    this.target = target;
  }

  void aim(Ball ball){
    try{
      //std::cout << &this << std::endl; // print calling objects addr to test
      throw ball;
    } catch (Ball b){
      target->aim(b);
    }
  }
}

public static void main(String[] args){
  P parent(null);
  P child(parent);
  parent.target = &child; // :(
  parent.aim(new Ball());
}

/**
 * Es hat sich ein valides C++ Programm ergeben
 * Nach den Präprocessordirektiven wird die main() Funktion aufgerufen
 * und parent und child erstellt. Sobald sie eine gegenseitige kennt-ein Beziehung
 * aufgebaut haben, wird die aim Methode von parent mit einer Ball-Instanz
 * aufgerufen. Ball wird als Exception geworfen und die Exception sofort
 * aufgefangen. Das auffangen zeichnet sich dadurch aus, dass nun die aim Methode
 * vom child aufgerufen wird. Es wird also abwechselnd die aim Methode der beiden
 * Ps aufgerufen, bis der Computer nicht mehr will.
 */
