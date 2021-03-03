#include "bubbleSort.h"
#include "mytool.h"

void bubbleSort(DataType theArray[], int n){
	bool sorted = false;
	for (int pass = 0; pass <= n-1 && !sorted; ++pass){
		sorted = true;
		for (int arrow = 0; arrow <= n-2-pass; ++arrow){
			if (theArray[arrow] > theArray[arrow+1]){
				swap(theArray[arrow], theArray[arrow+1]);
				sorted = false;
			}
		}
	}
	
}


