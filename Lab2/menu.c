#include<stdio.h>
#include "index_first_zero.h"
#include "index_last_zero.h"
#include "summa_between.h"
#include "summa_before_and_after.h"
#define SIZE 100
int main()
{
int op_num;
int i;
int array[SIZE];
int result;
scanf("%d", &op_num );
for (i=0; i<SIZE; i++) 
	{
	if (getchar() == '\n')
	break;
scanf("%d", &array[i]);
result=i;
}

switch(op_num) 
{
case 0:
printf ("%d\n",index_first_zero (array, result));
break;

case 1:
printf ("%d\n",index_last_zero (array, result));
break;

case 2:
printf("%d\n", summa_between (array, result));
break;

case 3:
printf("%d\n", summa_before_and_after (array, result));
break;

default:
printf("Данные некорректны");
break;
}

return 0;

}

