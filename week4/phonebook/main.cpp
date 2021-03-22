#include "string.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "my_sorting_lib.h"

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
    int num = 100;
    Account *phonebook = new Account[num];
    ///////////////////////////////////////// Generate the phonebook./////////////////////////////////////
    // std::cout << "Generating Phonebook...." << std ::endl;
    // srand((unsigned)time(NULL));
    // for (int i = 0; i < num; i++)
    // {
    //     printf("Account %i's name:\t", i);
    //     genRandomName(10, phonebook[i].name);
    //     // Sleep(1000);
    //     printf("Account %i's phone:\t", i);
    //     genRandomPhone(10, phonebook[i].phone);
    //     // Sleep(1000);
    //     printf("Account %i's address:\t", i);
    //     genRandomAddr(30, phonebook[i].address);
    //     // Sleep(1000);
    //     printf("--------\n");
    // }
    // Save the PhoneBook to file.
    // FILE *outfile;
    // outfile = fopen("phonebook.dat", "w");
    // if (outfile == NULL)
    // {
    //     fprintf(stderr, "\nError opend file\n");
    //     exit(1);
    // }
    // for (int i = 0; i < num; i++)
    // {
    //     fwrite(&phonebook[i], sizeof(Account), 1, outfile);
    // }

    // if (fwrite != 0)
    //     printf("contents to file written successfully !\n");
    // else
    //     printf("error writing file !\n");

    // // close file
    // fclose(outfile);
    /////////////////////////////////////////// Read phonebook from phonebook.dat ///////////////////////////
    FILE *infile;
    infile = fopen("phonebook.dat", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit(1);
    }
    for (int i = 0; i < num; i++)
    {
        fread(&phonebook[i], sizeof(Account), 1, infile);
    }
    fclose(infile);

    char order;
    std::cout << "1 : name\n2 : phone\n3 : address" << std::endl;
    std::cout << "Please enter your priority of sorting the phonebook: ex: type 3 if you want the sorting order to be address first." << std::endl;
    std::cin >> order;

    // Sort the phonebook
    switch (order)
    {
    case '1':
        // myqsort((void *)phonebook, num, sizeof(phonebook[0]), compareName);
        // mybubbleSort((void *)phonebook, num, sizeof(phonebook[0]), compareName);
        // myinsertionSort((void *)phonebook, num, sizeof(phonebook[0]), compareName);
        myselectionSort((void *)phonebook, num, sizeof(phonebook[0]), compareName);

        printf("==========After sorting by name:==============\n");
        break;
    case '2':
        // myqsort((void *)phonebook, num, sizeof(phonebook[0]), comparePhone);
        // mybubbleSort((void *)phonebook, num, sizeof(phonebook[0]), comparePhone);
        // myinsertionSort((void *)phonebook, num, sizeof(phonebook[0]), comparePhone);
        myselectionSort((void *)phonebook, num, sizeof(phonebook[0]), comparePhone);

        printf("==========After sorting by phone:============\n");
        break;
    case '3':
        // myqsort((void *)phonebook, num, sizeof(phonebook[0]), compareAddress);
        // mybubbleSort((void *)phonebook, num, sizeof(phonebook[0]), compareAddress);
        // myinsertionSort((void *)phonebook, num, sizeof(phonebook[0]), compareAddress);
        myselectionSort((void *)phonebook, num, sizeof(phonebook[0]), compareAddress);

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