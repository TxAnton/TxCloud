#include <iostream>

//using namespace std;
int main() {
    int a = 1;
    int b = 2;
    int c;

    asm("//.intel_syntax noprefix\n\t" // директива GAS, включаем Intel синтаксис.
        "mov eax, %1\n\t"            // перемещаем в eax значение переменной a.
        "add eax, %2\n\t"            // прибавляем значение переменной b к eax.
        "mov %0, eax\n\t"            // перемещаем в переменную c значение eax.
        :"=r"(c)                     // список выходных параметров.
        :"r"(a), "r"(b)              // список входных параметров.
        : "eax"                      // список разрушаемых регистров.
    );

    printf("%d + %d = %d\n", a, b, c);
    return 0;
}