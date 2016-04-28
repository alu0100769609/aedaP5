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
void demoMode();
void statisticMode();

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////// MAIN /////////////////////////////////////
int main () {
   system("clear");                       // Clean window before start


   int option;                            // To select from menu
   int mode;                              // Execution mode (demo, statistic)
   cout << "* * * * * * * *\n"
        << "*   Welcome   *\n"
        << "* * * * * * * *\n" << endl;

   do {
      cout << "Choose one option:\n"
           << "0. Exit\n"
           << "1. Demo mode\n"
           << "2. Statistic mode" << endl;
      cin >> mode;
      system("clear");

      if (mode == 0) {
         return 0;
      }
      else if (mode == 1) {
         vector<T_KEY> myDNIs = CreateDNI(NUMBER_OF_DNI);  // Create vector with DNIs
         Sort<T_KEY> sortDNIs = Sort<T_KEY>(myDNIs,NUMBER_OF_DNI);// Create Sort class

         cout << "Select sort method:\n"
              << "0. Exit\n"
              << "1. Direct Insertion\n"
              << "2. Bubble sort\n"
              << "3. Quick sort\n" << endl;
         cin >> option;
         system("clear");

         switch (option) {
            case 0: return 0;                // Exit
            case 1: sortDNIs.directInsertion(mode); break;
            case 2: sortDNIs.bubbleSort(mode); break;
            case 3: sortDNIs.quickSort(0, sortDNIs.getSize(), mode); break;
            default: cout << "..Wrong option.." << endl;
         }
      }
   } while (true);
/*
   cout << "Vector antes: ";
   sortDNIs.printItems();
   cout << "\n\n\n\n" << endl;
   sortDNIs.directInsertion();
   cout << "Vector despues: ";
   sortDNIs.printItems();
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
*/
   return 0;
}

///////////////////////////////////////////////////////////////////////////////
////////////////////////////// EXTERNAL FUNCTIONS /////////////////////////////
vector<T_KEY> CreateDNI (int numberOfDNI) {
   vector<T_KEY> database(numberOfDNI,0); //size, default value
   T_KEY dni = 0;
   for (int i = 0; i < numberOfDNI; i++) {
     dni = rand() % SIZE + 30000001; //random between 30.000.001 & 80.000.000
     database[i] = dni;
   };
   return database;  //Allowed because std::vector is a class
}
