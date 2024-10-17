/**
 * This program measures the approximate runtimes it takes for various 
 * sorting algorithms to sort arrays of random integers and floating
 * point values.
 * @author Muntrail Jones
 * <pre>
 * File: SortProfiler.cpp
 * Date: 10-9-2024
 * Course: csc 1254 section 1
 * Project #: 2
 * Instructor: Dr. Duncan
 * </pre>
 */

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <iomanip>
#include "ArrayUtil.cpp"
#include "SortUtil.cpp"
#include "SortProfiler.h"

using namespace std;
using namespace std::chrono;


int main(int argc, char **argv)
{
   
   int *iArray1, *iArray2, *iArray3;
   double *dArray1, *dArray2, *dArray3;
   long time1, time2, time3;
   int size[] = {100, 500, 1000, 5000, 10000, 50000, 100000};
   srand(time(NULL));
   
   /******************************************************** 
   The code from lines 45-76 is intended for debugging. 
   Uncomment line 76, the 'exit(1);' line, to verify that 
   all the code for the various sorting algorithms are 
   working correctly. Comment out line 76, the 'exit(1);', 
   again once you have verified that they work correctly. In 
   each case a random integer array of size 25 is generated 
   and the orignal and sorted arrays are printed.
   ********************************************************/

   int *testArray = new int [50];

   cout<<"***Testing Bubble Sort***"<<endl;
   cout<<"Original Array:"<<endl;
   ArrayUtil::genRandArray(testArray,25,10,99);
   ArrayUtil::printArray(testArray,0,24,5);
   cout<<endl;
   SortUtil::bubbleSort(testArray,25);
   cout<<"Sorted Array:"<<endl;
   ArrayUtil::printArray(testArray,0,24,5);
   cout<<endl;

   cout<<"***Testing Selection Sort***"<<endl;
   cout<<"Original Array:"<<endl;
   ArrayUtil::genRandArray(testArray,25,10,99);
   ArrayUtil::printArray(testArray,0,24,5);
   cout<<endl;
   SortUtil::selectionSort(testArray,25);
   cout<<"Sorted Array:"<<endl;
   ArrayUtil::printArray(testArray,0,24,5);
   cout<<endl;
      
   cout<<"***Testing Merge Sort***"<<endl;
   cout<<"Original Array:"<<endl;
   ArrayUtil::genRandArray(testArray,25,10,99);
   ArrayUtil::printArray(testArray,0,24,5);
   cout<<endl;
   SortUtil::mergeSort(testArray,25);
   cout<<"Sorted Array:"<<endl;
   ArrayUtil::printArray(testArray,0,24,5);
   cout<<endl;
   //exit(1);

   cout<<"Using Arrays with Random Integers"<<endl;
   cout<<setw(8)<<left<<"n"<<setw(16)<<left<<"bubbleSort"<<setw(16)<<left<<"selectionSort"<<setw(12)<<left<<"mergeSort"<<endl;
   for(int i = 0; i < 50; i++) cout<<"-";
   cout<<endl;
   for (int i = 0; i < 7; i++)
   {
      iArray1 = new int[size[i]];
      iArray2 = new int[size[i]];
      iArray3 = new int[size[i]];		 
      
      ArrayUtil::genRandArray(iArray1,size[i]);
      ArrayUtil::arrayCopy(iArray1, 0, iArray2, 0, size[i]);
      ArrayUtil::arrayCopy(iArray1, 0, iArray3, 0, size[i]);
      
      auto start = high_resolution_clock::now();
      SortUtil::bubbleSort(iArray2,size[i]);
      auto elapsed = high_resolution_clock::now() - start;
      time1 = duration_cast<microseconds>(elapsed).count();

      start = high_resolution_clock::now();
      SortUtil::selectionSort(iArray1,size[i]);
      elapsed = high_resolution_clock::now() - start;
      time2 = duration_cast<microseconds>(elapsed).count();

      start = high_resolution_clock::now();
      SortUtil::mergeSort(iArray3,size[i]);
      elapsed = high_resolution_clock::now() - start;
      time3 = duration_cast<microseconds>(elapsed).count();
	  
      cout<<setw(8)<<size[i]<<setw(16)<<time1<<setw(16)<<time2<<setw(12)<<time3<<endl; 
      delete[] iArray1;
      delete[] iArray2; 
      delete[] iArray3;
   }
   cout<<endl<<endl;
   
   cout <<"*** NOW USING THE ALGORITHMS WITH DOUBLES ***"<<endl<<endl;

   /* Rabove for the epeat/modify the code same array sizes but this time
      the contents of the array (array type) would be doubles. The functions
      to generate random doubles and doubles has already been written for 
	  you.  Also, a pointer to a double, dArray, is declared for use in 
	  allocating the arrays of doubles. 
   
   */

   cout<<setw(8)<<left<<"n"<<setw(16)<<left<<"bubbleSort"<<setw(16)<<left<<"selectionSort"<<setw(12)<<left<<"mergeSort"<<endl;
   for(int i = 0; i < 50; i++) cout<<"-";
   cout<<endl;
   for (int i = 0; i < 7; i++)
   {
     double* dArray1 = new double [size[i]];
     double* dArray2 = new double [size[i]];
     double* dArray3 = new double [size[i]];		 
      
      ArrayUtil::genRandArray(dArray1,size[i]);
      ArrayUtil::arrayCopy(dArray1, 0, dArray2, 0, size[i]);
      ArrayUtil::arrayCopy(dArray1, 0, dArray3, 0, size[i]);
      
      auto start = high_resolution_clock::now();
      SortUtil::bubbleSort(dArray2,size[i]);
      auto elapsed = high_resolution_clock::now() - start;
      time1 = duration_cast<microseconds>(elapsed).count();

      start = high_resolution_clock::now();
      SortUtil::selectionSort(dArray1,size[i]);
      elapsed = high_resolution_clock::now() - start;
      time2 = duration_cast<microseconds>(elapsed).count();

      start = high_resolution_clock::now();
      SortUtil::mergeSort(dArray3,size[i]);
      elapsed = high_resolution_clock::now() - start;
      time3 = duration_cast<microseconds>(elapsed).count();
	  
      cout<<setw(8)<<size[i]<<setw(16)<<time1<<setw(16)<<time2<<setw(12)<<time3<<endl; 
      delete[] dArray1;
      delete[] dArray2; 
      delete[] dArray3;
   }
   cout<<endl<<endl;


   cout<<endl<<"Data Generation Complete"<<endl;;
  return 0;
}
