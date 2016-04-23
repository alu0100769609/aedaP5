#include <stdexcept>       // invalid_argument()
#include <ctype.h>         // isalpha(), toupper()
#include <iomanip>         // setprecision()
#include <iostream>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////// DNI Class //////////////////////////////////

class DNI {
private:                   // Private attributes
   double number;                            // DNI number
   char letter;                              // DNI letter

public:                    // Public methods
   DNI();                                    // Default constructor
   DNI(double, char);                        // Constructor
   ~DNI();                                   // Default destructor

public:                    // Public setters and getters
   void setNumber(double);
   const double getNumber();
   void setLetter(char);
   const char getLetter();

public:                    // Public inline overload method
   bool operator ==(const DNI dni) const {
      return ((number == dni.number) && (letter == dni.letter));
   }
};

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// Methods ///////////////////////////////////

DNI::DNI() {
   // By default;
}

DNI::DNI(double number, char letter) {
   setNumber(number);
   setLetter(letter);
}

DNI::~DNI() {
   // By default;
}

void DNI::setNumber(double number) {
   this->number = number;
}

const double DNI::getNumber() {
   return number;
}

void DNI::setLetter(char letter) {
   this->letter = letter;
}

const char DNI::getLetter() {
   return letter;
}


///////////////////////////////////////////////////////////////////////////////
////////////////////////// Overload is (>>) & os (<<)//////////////////////////
ostream& operator << (ostream& os, DNI& dni) {
   os << setprecision(8) << dni.getNumber()  // setprecision(8) remove floating number
      << "-"
      << (char)toupper(dni.getLetter());     // Cast toupper() as char
   return os;                                // Return formatted DNI
}

istream& operator >>(istream& is, DNI& dni) {
   double num;
   char letter;
   char discard;
   is >> ws;                                 // Eat up any leading white spaces
                                             // Start of parse input
   int c = is.peek();                        // See first character
   if (isdigit(c)){                          // If isDigit save into DNI
      is >> num;
      if ( (10000000 < num) && (num < 99999999)) {
         dni.setNumber(num);                 // Set the DNI number
         is >> ws;                           // Eat up any leading white spaces
         c = is.peek();                      // See next char
         if (c == '-'){                      // If '-', discard
            is >> discard;
            is >> ws;                        // Eat up any leading white spaces
            c = is.peek();                   // Get next char
            if (isalpha(c)) {                // If it is alphabetic character
               is >> letter;
               dni.setLetter(letter);        // Save DNI letter
               return is;                    // All successfully, return istream
            }
         }
         else if (isalpha(c)) {              // If it is alphabetic character
            is >> letter;
            dni.setLetter(letter);           // Save DNI letter
            return is;                       // All successfully, return istream
         }
      }
   }                                         // If here, DNI input was wrong
   throw invalid_argument( "Wrong DNI. Try something like: 12345678-A or 12345678A" );
}
