#include<stdio.h>
#include<stdlib.h>
#include<time.h>//Не забудь

//Сколько раз бенчмарк повторит вызов функции для более точного результата
#define REPEATS 100

//Это в самом бенчмарке не потребуется
#define ARR_SIZE 50
#define KEY 5

//Для бенчмарка он тоже не нужен, но вообще Круглик скорее всего попросит написать компаратор, так что лучше знать как это делается
int comparator(const void* a, const void* b){
	if( *(int*)a > *(int*)b ) return 1;
	else if(*(int*)a == *(int*)b) return 0;
	else return -1;
	/*
	Что тут происходит, по порядку:
	a - указатель на void
	(int*)a - приводим(кастуем), теперь это указатель на int
	*(int*)a - разыменовываем, теперь это непосредственно число(int) по тому указателю
	
	a >  b =>  1
	a == b =>  0
	a <  b => -1
	*/
}

//Вот это от тебя и потребуется, это для bsearch, он может дать другую функцию
double BsearchBm(int* key, int* data, int n, int(*cmp)(const void*,const void*)){
	/*
	key - что ищем(обрати внимание, что для функции bsearch нежен именно указатель на значение ключа)
	
	data - где ищем
	
	n - размер массива data
	
	int(*cmp)(const void*,const void*) - указатель на функцию-компаратор
	Сдесь:
	
	int - тип возвращаемого значения
	
	*сmp - просто имя, по-моему даже звездочка не обязательна
	
	(const void*,const void*) - аргументы функции
	
	т.е. по этим данным эта функция-компаратор выглядит как-то так:
	int cmp(const void* a, const void* b)
	примерно так она собственно и выглядит(comparator)
	
	*/
	
	clock_t clocks[REPEATS];// массив значний, коих для точности нужно много
	int j=0;//счетчик внутри массива clocks
	
	for(int i=0; i<REPEATS; i++){//Цикл прогоняет функцию REPEATS раз
		
		clock_t time = clock();//Считаем время до
		
		int* found=(int*)bsearch(key,data,n,sizeof(int),cmp);//Выполняем функцию. Можно никуда значение не присваивать, оно нас не интересует
		
		time = clock() - time;//От времени после(т.е. сейчас) отнимаем время до, получаем время на выполнение этой функции
		
		clocks[j]=time;///Пихаем в наш массивчик
		j++;
		
	}
	
	//Ищем среднее арифметическое
	double sum=0;
	for(int i=0; i<j; i++){//Вместо j можно писать REPEATS, они на данный момент равны
		sum+=clocks[i];
	}
	sum/=j;
	
	return sum / CLOCKS_PER_SEC;//Результат нужен в секундах, мы считаем в тиках, поэтому делим на константу(тики/секунды)
}

//Этого от тебя тоже не потребуется, просто тест бенчмарка
int main(){
	int arr[ARR_SIZE];
	int n = ARR_SIZE;
	int key = KEY;
	for(int i =0; i< ARR_SIZE; i++){
		arr[i] = i;
	}
	double bmTime = BsearchBm(&key, arr, n, comparator);
	
	printf("%lf", bmTime);
	/*
	int a = 15;
	int b = 15;
	printf("%d", comparator(&a,&b));
	*/	
	
}
