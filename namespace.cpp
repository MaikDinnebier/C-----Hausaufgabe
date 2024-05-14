#include <iostream>

// Namespace NS1 definieren
namespace NS1 {
    //Sub-Namespace NSI1::Utils definieren
    namespace Utils {
        //Funktion printHello() in NS1::Utils
        void printHello() {
            std::cout << "Hello from NS1::Utils" << std::endl;
         }
    }
}
// Namespace NS2 definieren
namespace NS2 {
  //Sub-Namespace NS2::Data definieren
  namespace Data {
    //Funktion printHello() in NS2::Data
    void printHello() {
        std::cout << "Hello from NS2::Data" << std::endl;
        }
    }
}

int main() {
  // Funktionsaufruf aus NS1::Utils
  NS1::Utils::printHello();

  // Funktionsaufruf aus NS2::Data
  NS2::Data::printHello();

  return 0;
}
//Dieses Programm zeigt, wie Namespaces verwendet werden können, um Namenskonflikte zu vermeiden und den Code zu organisieren, 
//wenn Funktionen mit demselben Namen in verschiedenen Teilen eines Programms definiert werden müssen.
//Als zusätzliche Verschachtelung mit der Utils und Data