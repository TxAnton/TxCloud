import matplotlib.pyplot as plt
import math
x0 = 2.2248


n = 10
i = [0,1,2,3,4,5,6,7,8,9,10]
x = [0.2376,0.7368,1.1448,1.9872,2.5392,2.7648,3.0616,3.2088,3.2784,3.6904,3.9368]
y = [-3.7117,-0.7525,0.2297,0.0128,-0.3824,-0.3175,0.1348,0.5575,0.8109,3.1398,5.3285]


xy = [[x[j],y[j]] for j in i]
xy.sort(key=lambda x:x[0])

x=[j[0] for j in xy]
y=[j[1] for j in xy]


def divdif(a,b,xx,yy):
    if(b-a==1):
        return (yy[b]-yy[a])/(xx[b]-xx[a])
    return (divdif(a+1,b,xx,yy)-divdif(a,b-1,xx,yy))/(xx[b]-xx[a])

def inewton(n,x,xx,yy):
    s=yy[0] #f
    for i in range(1,n+1):
        mul=1
        for j in range(i):
            mul*=(x-xx[j])
        mul*=divdif(0,i,xx,yy)
        print("s_"+str(i)+"=\t"+str(mul))
        s+=mul
    return s

def aitken(x,xx,yy,a,b):
    f1 = yy[a] if b - a == 1 else aitken(x, xx, yy, a, b - 1)
    f2 = yy[b] if b - a == 1 else aitken(x, xx, yy, a+1, b)
    return (1/(xx[b]-xx[a])) * ((x-xx[a])*f2 - (x-xx[b])*f1)



def linSpace(a,b,s):
    x=[]
    #x.append(a)
    e=1/s
    e0=0
    while e0<=1:
        _x=round(a+(b-a)*e0,int(abs(math.log10(e))))
        #_x=a+(b-a)*e0
        x.append(_x)
        e0 += e
    return x


xx=linSpace(x[0],x[len(x)-1],100)

#yy = [inewton(n,i,x,y) for i in xx]

plt.plot(x,y)
#plt.plot(xx,yy)
print("f(x^*)=\t"+str(inewton(n,x0,x,y)))
yy = [aitken(i,x,y,0,n) for i in xx]
print(aitken(x0,x,y,0,n-2))
#plt.rcParams['lines.linewidth'] = 2  # Синтакс 2
plt.plot(xx,yy)
plt.xlabel('x')
plt.ylabel('y')
plt.legend(['initial','aitken'])
plt.show()