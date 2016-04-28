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
   vector<TDATO> array;                // Array with elements
   int size;                           // Size of array

public:
//   Sort();                           // Default constructor
   Sort(vector<TDATO> vector, int size);     // Constructor (Vector, size of vector)
   ~Sort();                            // Default destructor

public:                 // Public Sort methods
   void directInsertion();             // Direct insertion
   void bubbleSort();                  // Bubble sort
   void quickSort(int, int);           // Quick sort
public:
   void printItems();
   int getSize() { return size; }
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
Sort<TDATO>::Sort(vector<TDATO> vector, int size){
   array = vector;   ///////////////////////////////////////////////PROBLEM HERE////////////////////////////////////
   this->size = size;
}

template <class TDATO>
Sort<TDATO>::~Sort(){
//   delete array;
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
      // Comparsion
	   for(int j = 0; j < size - i; j++){
         // Exchange elements
	      if(array[j] > array[j+1]){
            token = array[j];
		      array[j] = array[j+1];
		      array[j+1] = token;
         }
      }
   }
}

template <class TDATO>
void Sort<TDATO>::quickSort(int l, int r) {
   int left = l;
   int right = r;
   TDATO center = array[(l + r) / 2];
   TDATO token;
    do{
      while((array[left] < center) && (right <= r)) {
         left++;
      }
      while((center < array[right]) && (right > l)) {
         right--;
      }
      if(left <= right) {
         token = array[left];
         array[left] = array[right];
         array[right] = token;
         left++;
         right--;
      }
   }while( left <= right );
   if( l < right )
      quickSort(l, right);
   if( left < r )
      quickSort(left, r);
}
