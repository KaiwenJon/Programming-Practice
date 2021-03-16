#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <windows.h>
#include "mytool.h"
#include "String.h"

typedef struct Account
{
    char name[10] = {0};
    char phone[10] = {0};
    char address[30] = {0};
} Account;

int compareName(const void *a, const void *b)
{
    Account c = *(Account *)a;
    Account d = *(Account *)b;
    return strcmp(c.name, d.name);
}

int comparePhone(const void *a, const void *b)
{
    Account c = *(Account *)a;
    Account d = *(Account *)b;
    return strcmp(c.phone, d.phone);
}

int compareAddress(const void *a, const void *b)
{
    Account c = *(Account *)a;
    Account d = *(Account *)b;
    return strcmp(c.address, d.address);
}

int main(void)
{
    // Generate the phonebook.
    std::cout << "Generating Phonebook...." << std ::endl;
    int num = 100;
    Account *phonebook = new Account[num];
    srand((unsigned)time(NULL));
    for (int i = 0; i < num; i++)
    {
        printf("Account %i's name:\t", i);
        genRandomName(10, phonebook[i].name);
        // Sleep(1000);
        printf("Account %i's phone:\t", i);
        genRandomPhone(10, phonebook[i].phone);
        // Sleep(1000);
        printf("Account %i's address:\t", i);
        genRandomAddr(30, phonebook[i].address);
        // Sleep(1000);
        printf("--------\n");
    }

    char order;
    std::cout << "1 : name\n2 : phone\n3 : address" << std::endl;
    std::cout << "Please enter your priority of sorting the phonebook: ex: type 3 if you want the sorting order to be address first." << std::endl;
    std::cin >> order;

    // Sort the phonebook
    switch (order)
    {
    case '1':
        qsort((void *)phonebook, num, sizeof(phonebook[0]), compareName);
        printf("==========After sorting by name:==============\n");
        break;
    case '2':
        qsort((void *)phonebook, num, sizeof(phonebook[0]), comparePhone);
        printf("==========After sorting by phone:============\n");
        break;
    case '3':
        qsort((void *)phonebook, num, sizeof(phonebook[0]), compareAddress);
        printf("==========After sorting by address:===========\n");
        break;
    }

    for (int i = 0; i < num; ++i)
    {
        printf("Account %i's name:\t", i);
        std::cout << phonebook[i].name << std::endl;
        printf("Account %i's phone:\t", i);
        std::cout << phonebook[i].phone << std::endl;
        printf("Account %i's address:\t", i);
        std::cout << phonebook[i].address << std::endl;
        printf("--------\n");
    }

    delete[] phonebook;
    system("pause");
    return 0;
}