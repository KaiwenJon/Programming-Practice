#ifndef MYSORTINGLIB
#define MYSORTINGLIB

typedef int DataType;

void swap(DataType &x, DataType &y);

int indexOfLargest(const DataType theArray[], int size);

void selectionSort(DataType theArray[], int n);

void bubbleSort(DataType theArray[], int n);

void insertionSort(DataType theArray[], int n);

int compare(const void *a, const void *b);

#endif