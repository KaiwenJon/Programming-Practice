#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

#include "selectionSort.h"
#include "bubbleSort.h" 
#include "insertionSort.h"

typedef int DataType;

int compare(const void *a, const void *b)
{
      int c = *(int *)a;
      int d = *(int *)b;
      if(c < d) {return -1;}
      else if (c == d) {return 0;} 
      else return 1; 
}

int main(int argc, char** argv) {

	int num, i;
	std::cout << "Please enter the size of the array:" << std::endl; 
	std::cin >> num;
	
	int *array = new int[num];
	srand((unsigned) time(NULL));
	for(i=0;i<num;i++)
		array[i]=rand()%100;
		
	for(unsigned i = 0; i < num; i++)
	{
	 printf(" %d\t", array[i]);
	}
	printf("\n\n");
	
//	qsort((void *)array, num, sizeof(array[0]), compare);
//	selectionSort(array, num);
//	bubbleSort(array, num);
	insertionSort(array, num);
	
	
	for(unsigned i = 0; i < num; i++)
	{
	 printf(" %d\t", array[i]);
	}
	delete[] array;
	system("PAUSE");
}
