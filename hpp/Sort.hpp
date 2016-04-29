#include <unistd.h>
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
   int directInsertion(int);             // Direct insertion (int mode)
   int bubbleSort(int);                  // Bubble sort (int mode)
   int quickSort(int, int, int, int = 0);           // Quick sort (3rd param = int mode)
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
   int counter = 0;
   for (int i = 0; i < size; i++) {
      if (counter % 5 == 0) {
         cout << endl;
      }
      cout << array[i] << "\t";
      counter ++;
   }
   cout << endl;
}

///////////////////////////////// Sort Methods /////////////////////////////////
template <class TDATO>
int Sort<TDATO>::directInsertion(int mode){ // mode = 1 -> Show couts
   TDATO token;
   int iteration = 0;
   if (mode == 1) {
      for (int i = 1; i < size; i++) {
         token = array[i];
         int j = i - 1;
         while (j >= 0 && array[j] > token) {
            array[j + 1] = array[j];
            cout << "\nIteration " << iteration << ":";
            cout << "\nbuffer: " << token << endl;
            printItems();
            j--;
            iteration ++;
            sleep(1);
         }
         array[j + 1] = token;
      }
   }
   else if (mode == 2) {
      for (int i = 1; i < size; i++) {
         token = array[i];
         int j = i - 1;
         while (j >= 0 && array[j] > token) {
            array[j + 1] = array[j];
            iteration++;
            j--;
         }
         array[j + 1] = token;
      }
   }
   return iteration;
}

template <class TDATO>
int Sort<TDATO>::bubbleSort(int mode){
   TDATO token;
   int iteration = 0;
   if (mode == 1) {
      for(int i = 0; i < size; i++){
   	   for(int j = 0; j < size - i; j++){
   	      if(array[j] > array[j+1]){
               token = array[j];
   		      array[j] = array[j+1];
   		      array[j+1] = token;
               cout << "\nIteration " << iteration << ":";
               cout << "\nbuffer: " << token << endl;
               printItems();
               iteration++;
               sleep(1);
            }
         }
      }
   }
   else if (mode == 2) {
      for(int i = 0; i < size; i++){
   	   for(int j = 0; j < size - i; j++){
   	      if(array[j] > array[j+1]){
               token = array[j];
   		      array[j] = array[j+1];
   		      array[j+1] = token;
               iteration++;
            }
         }
      }
   }
   return iteration;
}

template <class TDATO>
int Sort<TDATO>::quickSort(int l, int r, int mode, int iteration) {
   int left = l;
   int right = r;
   TDATO center = array[(l + r) / 2];
   TDATO token;
   if (mode == 1) {
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
            cout << "\nIteration " << iteration << ":";
            cout << "\nbuffer: " << token << endl;
            printItems();
            sleep(1);
            left++;
            right--;
            iteration++;
         }
      }while( left <= right );
      if( l < right )
         quickSort(l, right, mode, iteration);
      if( left < r )
         quickSort(left, r, mode, iteration);
   }
   else if (mode == 2) {
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
         iteration++;
      }while( left <= right );
      if( l < right )
         iteration+= quickSort(l, right, mode, iteration);
      if( left < r )
         quickSort(left, r, mode, iteration);
   }
   return iteration;
}
