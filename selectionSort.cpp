#include "selectionSort.h"
#include <iostream>
#include "mytool.h"

void selectionSort(DataType theArray[], int n){
	for(int arrow = n; arrow >= 1; --arrow){
	 int largest = indexOfLargest(theArray, arrow);
	 swap(theArray[arrow-1], theArray[largest]); 
	}		
}

int indexOfLargest(const DataType theArray[], int size){
	int indexSoFar = 0;
	for (int currentIndex = 0; currentIndex <= size-1; ++currentIndex){
		if (theArray[currentIndex] > theArray[indexSoFar]){
			indexSoFar = currentIndex;
		}
	}
	return indexSoFar; 
}


