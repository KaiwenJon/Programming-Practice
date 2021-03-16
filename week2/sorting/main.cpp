#include "MySortingLib.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int DataType;

int main(int argc, char **argv)
{

    int num, i;
    std::cout << "Please enter the size of the array:" << std::endl;
    std::cin >> num;

    int *array = new int[num];
    srand((unsigned)time(NULL));
    for (i = 0; i < num; i++)
        array[i] = rand() % 100;

    // Random numbers
    for (unsigned i = 0; i < num; i++)
    {
        printf(" %d\t", array[i]);
    }
    printf("\n\n");

    //Sorting Algorithm
    // qsort((void *)array, num, sizeof(array[0]), compare);
    // selectionSort(array, num);
    // bubbleSort(array, num);
    insertionSort(array, num);
    std::cout << "After Sorting....\n";
    //Sorted Array
    for (unsigned i = 0; i < num; i++)
    {
        printf(" %d\t", array[i]);
    }
    delete[] array;
    system("PAUSE");
}