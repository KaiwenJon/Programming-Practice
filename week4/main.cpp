
#include "my_sorting_lib.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void *a, const void *b)
{
    int c = *(int *)a;
    int d = *(int *)b;
    if (c < d)
    {
        return -1;
    }
    else if (c == d)
    {
        return 0;
    }
    else
        return 1;
}

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

    // myqsort((void *)array, num, sizeof(array[0]), compare);
    // mybubbleSort((void *)array, num, sizeof(array[0]), compare);
    // myinsertionSort((void *)array, num, sizeof(array[0]), compare);
    myselectionSort((void *)array, num, sizeof(array[0]), compare);

    std::cout << "After Sorting....\n";
    //Sorted Array
    for (unsigned i = 0; i < num; i++)
    {
        printf(" %d\t", array[i]);
    }
    delete[] array;
    system("PAUSE");
}