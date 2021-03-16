#include "MySortingLib.h"

typedef int DataType;

void swap(DataType &x, DataType &y)
{
    DataType temp = x;
    x = y;
    y = temp;
}
int indexOfLargest(const DataType theArray[], int size)
{
    int indexSoFar = 0;
    for (int currentIndex = 0; currentIndex <= size - 1; ++currentIndex)
    {
        if (theArray[currentIndex] > theArray[indexSoFar])
        {
            indexSoFar = currentIndex;
        }
    }
    return indexSoFar;
}
void selectionSort(DataType theArray[], int n)
{
    for (int arrow = n; arrow >= 1; --arrow)
    {
        int largest = indexOfLargest(theArray, arrow);
        swap(theArray[arrow - 1], theArray[largest]);
    }
}

void bubbleSort(DataType theArray[], int n)
{
    bool sorted = false;
    for (int pass = 0; pass <= n - 1 && !sorted; ++pass)
    {
        sorted = true;
        for (int arrow = 0; arrow <= n - 2 - pass; ++arrow)
        {
            if (theArray[arrow] > theArray[arrow + 1])
            {
                swap(theArray[arrow], theArray[arrow + 1]);
                sorted = false;
            }
        }
    }
}
void insertionSort(DataType theArray[], int n)
{
    for (int arrow = 1; arrow <= n - 1; ++arrow)
    {
        for (int compareIndex = arrow; compareIndex >= 1; --compareIndex)
        {
            if (theArray[compareIndex] < theArray[compareIndex - 1])
            {
                swap(theArray[compareIndex], theArray[compareIndex - 1]);
            }
        }
    }
}

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
