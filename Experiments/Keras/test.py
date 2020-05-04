import numpy as np
import matplotlib as plt

def naive_relu(x):
    assert len(x.shape)==2

    x = x.copy()

    for i in range(x.shape[0]):
        for j in range(x.shape[1]):
            x[i][j]= max(x[i][j],0)
    return x



x = np.random.random((64,5))
y = np.random.random((64,5))
x-=0.5
y-=0.5
x=abs(x)
y=abs(y)
#y=-y
print(x)
print(y)
print(x+y)
