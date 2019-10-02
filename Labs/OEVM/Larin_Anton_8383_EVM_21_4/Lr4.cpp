#include "pch.h"
#include <iostream>
#include <stdio.h>

#define N 80
#define T 0
using namespace std;

int main()
{
	system("chcp 1251 > nul");
	char _str[N + 1];
	char msg[] = "��4. ����� ����� 8383. 13) ������������ ������ ��������� ������� ����� �� �������� � ������ ������� ��� ������� ��������� �� ������� ������ � ������ �� �� �����.\n";
	cout << msg;
	int i = 0;
	char alphaNum=-1;
	int firstOcc=-1;
	cin.getline(_str, N);
	_asm {
		sub eax, eax;
		mov al, T;	al <- termenate symbol
		mov ecx,N;	
		lea edi,_str;
		repne scas; cmps;
		sub ecx, N;
		not ecx;	ecx < -length(_str)
		mov edx, ecx; edx <- ecx (length)
		sub edi,edi

	cycle:
		mov edi, edx;	edi <- current index defined by counter
		sub edi, ecx;

		mov al, _str[edi];	al <- current symbol

		cmp al, '�';	Self-explanatory
		je isYo;
		cmp al, '�';
		je isYo;

		cmp al, '�';	In bounds. Otherwise - not cyrilic
		jl notCyrilic;
		cmp al, '�';
		jg notCyrilic;
	isCyrilic:
		mov firstOcc, edi;	firstOcc <- current sybmol index (first cyrilic occurance)
			cmp al, '�';	�+ are lower, �- are upper
		jge isLower;
	isUpper:
		cmp al, '�';
		jle beforeYo;
		inc al;	Letters after � are one position bigger
	beforeYo:
		sub al, '�';	Get alphabetical position
		inc al;			Muggles are counting from one
		mov alphaNum, al; alphaNum <-alphabetical position
		jmp hooray;	Thie end
	isLower:
		cmp al, '�';
		jle beforeYo_;
		inc al;
	beforeYo_:
		sub al, '�';
		inc al;
		mov alphaNum, al;
		jmp hooray;
	isYo:;D� y�� r�m�mb�r m�?
		mov alphaNum, 7; Truly magic number
		mov firstOcc, edi;
		jmp hooray;
	notCyrilic:
		loop cycle;
	hooray:
	}
	if (firstOcc != -1) {
		cout << "������ ��������� �������� �������: " << firstOcc << endl;
		cout << "����� �� ��������: " << (int)alphaNum<< endl;;
	}
	else {
		cout << "������� ���� ���" << endl;
	}
	return 0;
}