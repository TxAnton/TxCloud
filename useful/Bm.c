#include<stdio.h>
#include<stdlib.h>
#include<time.h>//�� ������

//������� ��� �������� �������� ����� ������� ��� ����� ������� ����������
#define REPEATS 100

//��� � ����� ��������� �� �����������
#define ARR_SIZE 50
#define KEY 5

//��� ��������� �� ���� �� �����, �� ������ ������� ������ ����� �������� �������� ����������, ��� ��� ����� ����� ��� ��� ��������
int comparator(const void* a, const void* b){
	if( *(int*)a > *(int*)b ) return 1;
	else if(*(int*)a == *(int*)b) return 0;
	else return -1;
	/*
	��� ��� ����������, �� �������:
	a - ��������� �� void
	(int*)a - ��������(�������), ������ ��� ��������� �� int
	*(int*)a - ��������������, ������ ��� ��������������� �����(int) �� ���� ���������
	
	a >  b =>  1
	a == b =>  0
	a <  b => -1
	*/
}

//��� ��� �� ���� � �����������, ��� ��� bsearch, �� ����� ���� ������ �������
double BsearchBm(int* key, int* data, int n, int(*cmp)(const void*,const void*)){
	/*
	key - ��� ����(������ ��������, ��� ��� ������� bsearch ����� ������ ��������� �� �������� �����)
	
	data - ��� ����
	
	n - ������ ������� data
	
	int(*cmp)(const void*,const void*) - ��������� �� �������-����������
	�����:
	
	int - ��� ������������� ��������
	
	*�mp - ������ ���, ��-����� ���� ��������� �� �����������
	
	(const void*,const void*) - ��������� �������
	
	�.�. �� ���� ������ ��� �������-���������� �������� ���-�� ���:
	int cmp(const void* a, const void* b)
	�������� ��� ��� ���������� � ��������(comparator)
	
	*/
	
	clock_t clocks[REPEATS];// ������ �������, ���� ��� �������� ����� �����
	int j=0;//������� ������ ������� clocks
	
	for(int i=0; i<REPEATS; i++){//���� ��������� ������� REPEATS ���
		
		clock_t time = clock();//������� ����� ��
		
		int* found=(int*)bsearch(key,data,n,sizeof(int),cmp);//��������� �������. ����� ������ �������� �� �����������, ��� ��� �� ����������
		
		time = clock() - time;//�� ������� �����(�.�. ������) �������� ����� ��, �������� ����� �� ���������� ���� �������
		
		clocks[j]=time;///������ � ��� ���������
		j++;
		
	}
	
	//���� ������� ��������������
	double sum=0;
	for(int i=0; i<j; i++){//������ j ����� ������ REPEATS, ��� �� ������ ������ �����
		sum+=clocks[i];
	}
	sum/=j;
	
	return sum / CLOCKS_PER_SEC;//��������� ����� � ��������, �� ������� � �����, ������� ����� �� ���������(����/�������)
}

//����� �� ���� ���� �� �����������, ������ ���� ���������
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
