#include "index_last_zero.h" 
int index_last_zero(int array[], int number)
{
int last_zero=-1;
int i=0;
int first=index_first_zero(array, number);
for(i=++first; i<=number; i++)
	{
		if (array[i]==0)
		last_zero=i;
	}
return last_zero;
}
