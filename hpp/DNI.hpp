#include <stdexcept>       // invalid_argument()
#include <ctype.h>         // isalpha(), toupper()
#include <iomanip>         // setprecision()
#include <iostream>
/*
Adexe Sabina Pérez
*/
using namespace std;

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////// DNI Class //////////////////////////////////

class DNI {
private:                   // Private attributes
   long int number;                            // DNI number
   char letter;                              // DNI letter

public:                    // Public methods
   DNI();                                    // Default constructor
   DNI(long int);                        // Constructor
   ~DNI();                                   // Default destructor

public:                    // Public setters and getters
   void setNumber(long int);
   const long int getNumber();
   const char getLetter();                   // Be able to get letter from os

private:                   // Private setters and getters
   void setLetter();

public:                    // Public inline overload method
   bool operator ==(const DNI dni) const {
      return (number == dni.number);
   }
   bool operator >(const DNI dni) const {
      return (number > dni.number);
   }
   bool operator <(const DNI dni) const {
      return (number < dni.number);
   }
};

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// Methods ///////////////////////////////////

DNI::DNI() {
   // By default;
}

DNI::DNI(long int number) {
   setNumber(number);
}

DNI::~DNI() {
   // By default;
}

void DNI::setNumber(long int number) {
   this->number = number;
   setLetter();
}

const long int DNI::getNumber() {
   return number;
}

void DNI::setLetter() {
   int operation = getNumber() % 23;
   switch (operation) {
      case 0: letter = 'T'; break;
      case 1: letter = 'R'; break;
      case 2: letter = 'W'; break;
      case 3: letter = 'A'; break;
      case 4: letter = 'G'; break;
      case 5: letter = 'M'; break;
      case 6: letter = 'Y'; break;
      case 7: letter = 'F'; break;
      case 8: letter = 'P'; break;
      case 9: letter = 'D'; break;
      case 10: letter = 'X'; break;
      case 11: letter = 'B'; break;
      case 12: letter = 'N'; break;
      case 13: letter = 'J'; break;
      case 14: letter = 'Z'; break;
      case 15: letter = 'S'; break;
      case 16: letter = 'Q'; break;
      case 17: letter = 'V'; break;
      case 18: letter = 'H'; break;
      case 19: letter = 'L'; break;
      case 20: letter = 'C'; break;
      case 21: letter = 'K'; break;
      case 22: letter = 'E'; break;
   }
}

const char DNI::getLetter() {
   return letter;
}


///////////////////////////////////////////////////////////////////////////////
////////////////////////// Overload is (>>) & os (<<)//////////////////////////
ostream& operator << (ostream& os, DNI& dni) {
   os << setprecision(8) << dni.getNumber()  // remove floating number
      << "-"
      << (char)toupper(dni.getLetter());     // Cast toupper() as char
   return os;                                // Return formatted DNI
}

istream& operator >>(istream& is, DNI& dni) {
   long int num;
   is >> ws;                                 // Eat up any leading white spaces
                                             // Start of parse input
   int c = is.peek();                        // See first character
   if (isdigit(c)){                          // If isDigit save into DNI
      is >> num;
      if ( (10000000 < num) && (num < 99999999)) {
         dni.setNumber(num);                 // Set the DNI number
         return is;                    // All successfully, return istream
      }
   }                                         // If here, DNI input was wrong
   throw invalid_argument( "Wrong DNI. Try something like: 12345678-A or 12345678A" );
}
