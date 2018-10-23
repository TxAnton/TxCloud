#include "index_first_zero.h" 
int index_first_zero(int array[], int number)
{
int first_zero=-1;
int i=0;
for (i; i<=number; i++)
	{
	if (array[i]==0)
		{
		first_zero=i;
		break;
		}
	}
return first_zero;
}
