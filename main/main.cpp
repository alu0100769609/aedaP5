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

   DNI miDni[2];
/*
   type v[10] = {15,11,19,16,17,14,12,18,10,13};

   // Send to Sort one vector of 10 elements.
   Sort<type> t = Sort<type>(v,10);

   cout << "Vector antes: ";
   t.printItems();

//   t.directInsertion();
//   t.bubbleSort();
   t.quickSort(0,t.getSize());
   cout << "Vector despues: ";
   t.printItems();
*/


   try{
      cout << "Enter DNI-1: ";
      cin >> miDni[0];
      cout << "Enter DNI-2: ";
      cin >> miDni[1];

   }
   catch (const invalid_argument& error) {
      cout << error.what() << endl;
      return 0;
   }
   if (miDni[0] >= miDni[1])
      cout << "Is 1 >= than 2?: yes" << endl;
   else
      cout << "Is 1 >= than 2?: no" << endl;

   if (miDni[0] <= miDni[1])
      cout << "Is 1 <= than 2?: yes" << endl;
   else
      cout << "Is 1 <= than 2?: no" << endl;

   if (miDni[0] == miDni[1])
      cout << "Is 1 == 2?: yes" << endl;
   else
      cout << "Is 1 == 2?: no" << endl;

   cout << "DNIs are: " << miDni[0] << ", " << miDni[1] << endl;
   return 0;
}
