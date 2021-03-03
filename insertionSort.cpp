#include "insertionSort.h"
#include "mytool.h"

void insertionSort(DataType theArray[], int n){
	for (int arrow = 1; arrow <= n-1; ++arrow){
		for (int compareIndex = arrow; compareIndex >= 1; --compareIndex){
			if (theArray[compareIndex] < theArray[compareIndex-1]){
				swap(theArray[compareIndex] , theArray[compareIndex-1]);
			}
		}
	}
}
