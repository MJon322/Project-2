/**
 * implementation of the functions for various sorting algorithms
 * along with auxilliary functions (for internal use).
 * @author Duncan, YOUR NAME
 * <pre>
 * File: SortUtil.cpp
 * Date: 10-7-2024
 * Course: csc 1254 Section 1
 * Project #: 2
 * Instructor: Dr. Duncan
 * </pre>
 */


#include <iostream>
#include <algorithm>
#include "ArrayUtil.h"
#include "SortUtil.h"

using namespace std;


/* auxilliary function (for internal use only) */

/** This function merges two subarrays into the original array.
 * @param data - the original array
 * @param first - a subarray
 * @param sizeFirst - the size of the first subarray
 * @param second - a subarray
 * @param sizeSecond - the size of the second subarray.
 */
template <typename T>
static void merge(T data[], T first[],int sizeFirst, T second[], int sizeSecond)
{
   T* merge = new T[sizeFirst + sizeSecond];
   int i=0, j=0,k=0;
   while (i < sizeFirst && j < sizeSecond){
      if (first[i] < second[j]){
         data[k++] = first[i++];
      } else{
         data[k++] = second[j++];
      }
   }

while (i < sizeFirst){
   data[k++] = first[i++];
}
while( j < sizeSecond){
   data[k++] = second[j++];
}
}

/* sorting functions */
template <typename T>
inline void SortUtil::bubbleSort(T data[], int size)
{
   for(int i = size -1; i > 0; i--){
      for (int j=0; j < i; j++)
      {
         if(data[j] > data[j + 1]){
         swap(data[j], data[j+1]);
      }
   }
}
}
//implement this function
template <typename T>
inline void SortUtil::selectionSort(T data[], int size)
{
   for (int i=0; i < size; ++i){
      int minIndex = i;
      for (int j=i+1; j < size; j++){
         if (data[j] < data[minIndex]){
            minIndex = j;
         }
      }
       swap(data[i],data[minIndex]);
   }

}
template <typename T>
inline void SortUtil::mergeSort(T data[], int size)
{
   if (size <= 1) return;
   int size1 = size/2;
   int size2 = size - size1;
   T *first = new T[size1];
   T *second = new T[size2];
   ArrayUtil::arrayCopy(data,0,first,0,size1);
   ArrayUtil::arrayCopy(data,size1,second,0,size2);
   mergeSort(first,size1);
   mergeSort(second,size2);
   merge(data,first,size1,second,size2);
   delete[] first;
   delete[] second;
}
