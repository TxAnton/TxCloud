import matplotlib.pyplot as plt
import math

from sympy import *


x, y=symbols('x,y')

F  = 42*x + S(105)/2


print(F)

#F = F.subs(x,5)

print(F)


print("x",diff(F,y))

print(F.evalf())