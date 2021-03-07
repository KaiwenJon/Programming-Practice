#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 


int compare(const void *a, const void *b)
{
      int c = *(int *)a;
      int d = *(int *)b;
      if(c < d) {return -1;}
      else if (c == d) {return 0;} 
      else return 1; 
}



