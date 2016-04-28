#include <cstdlib>         // system()
#include <stdexcept>       // invalid_argument()
#include <vector>
#include "../hpp/DNI.hpp"
#include "../hpp/Sort.hpp"
#include <iostream>
/*
Adexe Sabina Pérez
*/
using namespace std;

typedef DNI T_KEY;
#define SIZE 50000000                  // To generate random DNIs
#define NUMBER_OF_DNI 25               // 25 DNIs

///////////////////////////////////////////////////////////////////////////////
////////////////////////////// DECLARED FUNCIONS //////////////////////////////
vector<T_KEY> CreateDNI(int);

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////// MAIN /////////////////////////////////////
int main () {
   system("clear");

   vector<T_KEY> myDNIs = CreateDNI(NUMBER_OF_DNI);  // create vector with DNIs
   Sort<T_KEY> sortDNIs = Sort<T_KEY>(myDNIs,NUMBER_OF_DNI);
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

/*
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
*/
   return 0;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////// CREATE_DNI FUNCTION /////////////////////////////
vector<T_KEY> CreateDNI (int numberOfDNI) {
   vector<T_KEY> database(numberOfDNI,0); //size, default value
   T_KEY dni = 0;
   for (int i = 0; i < numberOfDNI; i++) {
     dni = rand() % SIZE + 30000001; //random between 30.000.001 & 80.000.000
     database[i] = dni;
   };
   return database;  //Allowed because std::vector is a class
}
