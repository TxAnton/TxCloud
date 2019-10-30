
/* function
 *        fmod - вычисляет x по модулю y, остаток от  x/y
 *-----------------------------------------------------------------------*/
#pragma inline
#include "asmrules.h"
//#include <_math.h>
#include <math.h>
/*Имя             fmod - вычисляет x по модулю y,  остаток от  x/y
Использование   double fmod(double x, double y);
Прототип в...   math.h
Описание        fmod вычисляет  x - (y * int(x / y));
*/
*---------------------------------------------------------------------------*/
#pragma warn -rvl
double  _FARFUNC fmod (double x, double y)
{
asm     FLD     DOUBLE (y)
asm     mov     ax, y [6]
asm     shl     ax, 1              /* Игнорируется знаковый бит */
asm     jz      mod_resultZero     /* Если делитель равен 0 */
asm     cmp     ax, 0FFE0h
asm     jnb     mod_isX            /* Если делитель - бесконечность */
asm     FLD     DOUBLE (x)
asm     mov     ax, x [6]
asm     shl     ax, 1
asm     jz      mod_xZero          /* Если делимое равно 0  */
asm     cmp     ax, 0FFE0h
asm     jnb     mod_overflow       /* Если делимое - бесконечность */
mod_keepTrying:
asm     FPREM
asm     push    bx
asm     mov     bx, sp
asm     FSTSW   W0 (SS_ [bx])      /* C2 будет установлен, если еще не конец */
asm     FWAIT
asm     pop     ax
asm     sahf
asm     jp      mod_keepTrying     /* C2 бит отображается на флаг четности */
asm     FSTP    st(1)              /* сбросить  делитель */
mod_end:
        return;
}
#pragma warn .rvl


int main(){
	return 0	
}