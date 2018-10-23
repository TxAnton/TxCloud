#include "sum_between.h"
#include <stdio.h>
#include <stdlib.h>
int sum_between(int array[], int number)	
{
int first = index_first_zero(array, number);
int last = index_last_zero(array, number);
int sum=0;
int i=0;
	for (i=++first; i<last; i++) 
	{
	sum+=abs(array[i]);
	}
return sum;
}
