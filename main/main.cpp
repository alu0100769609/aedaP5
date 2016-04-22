#include <cstdlib>      // To use system()
#include <iostream>

using namespace std;

int main () {
   system("clear");
   cout << "Enter any key to continue..";
   cin.ignore();                 // Press any key (doing nothing)

   system("clear");
   cout << "Bye! :-(" << endl;
   return 0;
}
