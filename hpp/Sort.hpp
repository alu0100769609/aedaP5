#include <iostream>
/*
Adexe Sabina Pérez
*/
using namespace std;

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////// Sort Class /////////////////////////////////
template <class TDATO>
class Sort{
private:
   TDATO* array;                       // Array with elements
   int size;                           // Size of array

public:
//   Sort();                           // Default constructor
   Sort(TDATO vector[], int size);     // Constructor (Vector, size of vector)
   ~Sort();                            // Default destructor

public:                 // Public Sort methods
   void directInsertion();             // Direct insertion
   void bubbleSort();                  // Bubble Sort
public:
   void printItems();
};

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// Methods ///////////////////////////////////
/*
template <class TDATO>
Sort<TDATO>::Sort(){
   array = new TDATO[10];
}
*/
template <class TDATO>
Sort<TDATO>::Sort(TDATO vector[], int size){
   array = new TDATO[size];
   array = vector;   ///////////////////////////////////////////////PROBLEM HERE////////////////////////////////////
   this->size = size;
}

template <class TDATO>
Sort<TDATO>::~Sort(){
   delete array;
}

template <class TDATO>
void Sort<TDATO>::printItems(){
   for (int i = 0; i < size; i++) {
      cout << array[i] << " ";
   }
   cout << endl;
}

///////////////////////////////// Sort Methods /////////////////////////////////
template <class TDATO>
void Sort<TDATO>::directInsertion(){
   TDATO token;
   for (int i = 1; i < size; i++) {
      token = array[i];
      int j = i - 1;
      while (j >= 0 && array[j] > token) {
         array[j + 1] = array[j];
         j--;
      }
      array[j + 1] = token;
   }
}

template <class TDATO>
void Sort<TDATO>::bubbleSort(){
   TDATO token;
   for(int i = 0; i < size; i++){
      // Comparaciones
	   for(int j = 0; j < size - i; j++){
         // Intercambiar los elementos
	      if(array[j] > array[j+1]){
            token = array[j];
		      array[j] = array[j+1];
		      array[j+1] = token;
         }
      }
   }
}
