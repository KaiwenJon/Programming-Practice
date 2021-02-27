#include "bubbleSort.h"
#include "mytool.h"

void bubbleSort(DataType theArray[], int n){
	for (int pass = 0; pass <= n-1; ++pass){
		for (int arrow = 0; arrow <= n-2; ++arrow){
			if (theArray[arrow] > theArray[arrow+1]){
				swap(theArray[arrow], theArray[arrow+1]);
			}
		}
	}
	
}


