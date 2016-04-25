#include <cstdlib>         // system()
#include <stdexcept>       // invalid_argument()
#include "../hpp/DNI.hpp"
#include "../hpp/Sort.hpp"
#include <iostream>
/*
Adexe Sabina Pérez
*/
using namespace std;
typedef int type;
int main () {
   system("clear");

//   DNI miDni;
   type v[10] = {15,11,19,16,17,14,12,18,10,13};

   // Send to Sort one vector of 10 elements.
   Sort<type> t = Sort<type>(v,10);

   cout << "Vector antes: ";
   t.printItems();

//   t.directInsertion();
   t.bubbleSort();
   cout << "Vector despues: ";
   t.printItems();


/*
   try{
      cout << "Enter DNI: ";
      cin >> miDni;
   }
   catch (const invalid_argument& error) {
      cout << error.what() << endl;
      return 0;
   }
   cout << "Your entry: " << miDni << endl;
*/

   return 0;
}
