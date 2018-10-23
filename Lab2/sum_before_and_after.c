#include "sum_before_and_after.h"
#include <stdio.h>
#include <stdlib.h>
int sum_before_and_after(int array[], int number)
	{
int first = index_first_zero(array, number);
int last = index_last_zero (array,number);
int sum=0;
int i=0;
for (i; i<first; i++)
sum+=abs(array[i]);
	for (i=++last; i<=number; i++)
	sum+=abs(array[i]);
return sum;
}
