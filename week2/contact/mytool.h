#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <windows.h>
#ifndef MYTOOL
#define MYTOOL

int genRandomName(int length, char output[])
{

    int flag, i;
    for (i = 0; i < length - 1; i++)
    {
        flag = rand() % 2;
        switch (flag)
        {
        case 0:
            output[i] = 'A' + rand() % 26;
            break;
        case 1:
            output[i] = 'a' + rand() % 26;
            break;
        }
    }
    printf("Generated String: %s\n", output);
    return 0;
}
int genRandomPhone(int length, char output[])
{
    int flag, i;
    for (i = 0; i < length - 1; i++)
    {
        output[i] = '0' + rand() % 10;
    }
    printf("Generated String: %s\n", output);
    return 0;
}
int genRandomAddr(int length, char output[])
{
    int flag, i;
    for (i = 0; i < length - 1; i++)
    {
        flag = rand() % 3;
        switch (flag)
        {
        case 0:
            output[i] = 'A' + rand() % 26;
            break;
        case 1:
            output[i] = 'a' + rand() % 26;
            break;
        case 2:
            output[i] = '0' + rand() % 10;
            break;
        default:
            output[i] = 'x';
            break;
        }
    }
    printf("Generated String: %s\n", output);
    return 0;
}

#endif