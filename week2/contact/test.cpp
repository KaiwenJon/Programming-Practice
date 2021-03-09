#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <windows.h>
#include "mytool.h"

int main(void)
{
    int array[10];
    std::cout << array << std::endl;

    char *order;
    order = "hello";
    std::cout << order << std::endl;

    char order2[10];
    // order2 = "012345678";
    std::cout << order2 << std::endl;
    system("PAUSE");
    return 0;
}