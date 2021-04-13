
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

void printVector(vector<int> array)
{
    for (int i = 0; i < array.size(); i++)
    {
        std::cout << array.at(i) << ";";
    }
    std::cout << std::endl;
}
void printArray(int array[], int num)
{
    for (int i = 0; i < num; i++)
    {
        std::cout << array[i] << ";";
    }
    std::cout << std::endl;
}
void swapElementVector(vector<int> &array, int index1, int index2)
{
    int tmp = array.at(index1);
    array[index1] = array[index2];
    array[index2] = tmp;
    printVector(array);
}
void swapElementPointer(vector<int> *array, int index1, int index2)
{
    int tmp = array->at(index1);
    (*array)[index1] = (*array)[index2];
    (*array)[index2] = tmp;
    printVector(*array);
}
void swapElementArray(int *array, int index1, int index2, int total)
{
    int tmp = array[index1];
    array[index1] = array[index2];
    array[index2] = tmp;
    printArray(array, total);
}

void printAllPermutation(vector<int> array)
{
    printVector(array);
}

int main(int argc, char **argv)
{
    // Construct the objects=
    vector<int> numbers;
    vector<int> *numberPtr = new vector<int>();
    int total = 10;
    int *number_array = new int[total];
    for (int i = 0; i < total; i++)
    {
        numbers.push_back(i);
        numberPtr->push_back(i);
        number_array[i] = i;
    }

    // Show the difference between array and vector: vector needs to be passed by reference. Otherwise, use pointers
    cout << "Vector:\n";
    printVector(numbers);
    swapElementVector(numbers, 1, 2);

    cout << "Vector with pointer:\n";
    printVector(*numberPtr);
    swapElementPointer(numberPtr, 1, 2);

    cout << "Array:\n";
    printArray(number_array, total);
    swapElementArray(number_array, 1, 2, total);
    // for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
    // {
    //     auto n = *it;
    //     cout << n << endl;
    // }

    // Print all permutations of numbers:

    system("PAUSE");
}