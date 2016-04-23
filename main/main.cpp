#include <cstdlib>         // system()
#include <stdexcept>       // invalid_argument()
#include "../hpp/DNI.hpp"
#include <iostream>

using namespace std;

int main () {
   system("clear");

   DNI miDni;
   try{
      cout << "Enter DNI: ";
      cin >> miDni;
   }
   catch (const invalid_argument& error) {
      cout << error.what() << endl;
      return 0;
   }
   cout << "Your entry: " << miDni << endl;
   return 0;
}
