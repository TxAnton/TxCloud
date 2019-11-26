import matplotlib.pyplot as plt
import math

# x0 = 2.2248

x1 = 0.6190
x2 = 1.3990
x3 = 1.1000

n = 10

i = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
x = [0.3310, 0.5290, 0.7280, 0.9270, 1.1260, 1.3240, 1.5230, 1.7220, 1.9210, 2.1190, 2.3180]
y = [-0.3630, -0.0900, 0.0210, 0.0180, -0.0520, -0.1440, -0.2110, -0.2040, -0.0770, 0.2150, 0.7240]

xy = [[x[j], y[j]] for j in i]
xy.sort(key=lambda x: x[0])
x = [j[0] for j in xy]
y = [j[1] for j in xy]


def descdiv(r, k, yy):
    if (r == 1):
        return yy[k + 1] - yy[k]
    return descdiv(r - 1, k + 1, yy) - descdiv(r - 1, k, yy)


def ascdiv(r, k, yy):
    # yy=yy[::-1]
    if (r == 1):
        return yy[k] - yy[k - 1]
    return ascdiv(r - 1, k, yy) - ascdiv(r - 1, k - 1, yy)
    # return descdiv(r, k - r, yy)


def nforward(n, x, xx, yy):
    s = yy[0]
    h = abs(xx[1] - xx[0])
    q = (x - xx[0]) / h
    for i in range(1, n + 1):
        m = 1
        for j in range(i):
            m *= (q - j)
        m *= descdiv(i, 0, yy) / math.factorial(i)
        s += m
        print("m=\t" + str(m))
    return s


def nbackward(n, x, xx, yy):
    s = yy[-1]
    h = abs(xx[1] - xx[0])
    q = (x - xx[-1]) / h
    for i in range(1, n + 1):
        m = 1
        for j in range(i):
            m *= (q + j)
        m *= descdiv(i, n-i, yy) / math.factorial(i)
        s += m
        print("m=\t"+str(m))
    return s


def stirling(x, x0, xx, yy):
    h = abs(xx[1] - xx[0])
    x0-=h

    xy = [[xx[j], yy[j]] for j in range(len(xx))]

    _xy = [j for j in xy if j[0] < x0]
    xy_ = [j for j in xy if j[0] > x0]

    _xy.sort(key=lambda k: abs(k[0] - x0))
    xy_.sort(key=lambda k: abs(k[0] - x0))

    _xy = [_xy[j] for j in range(min(len(_xy), len(xy_)))]
    xy_ = [xy_[j] for j in range(min(len(_xy), len(xy_)))]

    _xy.sort(key=lambda x:x[0])

    xy=_xy+xy_

    '''
    if (abs(_xy[0][0] - x0) < abs(xy_[0][0] - x0)):
        xy = mergelists(_xy, xy_)
    else:
        xy = mergelists(xy_, _xy)
    '''
    xx = [j[0] for j in xy]
    yy = [j[1] for j in xy]
    '''
    min=abs(xx[0]-x)
    j0=0
    n=len(xx)-1
    for j in range(n+1):
        if(min>abs(xx[j]-x)):
            min = abs(xx[j]-x)
            j0=j

    if(j0>n-j0):
        n=n-j0
    else:
        n=j0
    '''
    n=int(len(xx)/2)
    s = yy[n]
    q = abs(x - xx[n]) / h
    for i in range(1, n):
        e=0
        m = 1
        m *= q
        m /= math.factorial(2 * i - 1)
        for j in range(1, i):
            m *= (q ** 2 - j ** 2)
        m *= (descdiv(2 * i - 1, n-i, yy) + descdiv(2 * i - 1, n-(i - 1), yy)) / 2
        e+=m
        s += m
        m = 1

        m /= math.factorial(2 * i)
        for j in range(i):
            m *= (q ** 2 - j ** 2)
        m *= descdiv(2 * i, n-i, yy)
        e+=m
        s += m

        print("m=\t"+str(e))

    return s


def mergelists(l1, l2):
    N = 2
    temp_iter = iter(l1)
    res = []
    for ele in l2:
        res.extend([next(temp_iter) for _ in range(N - 1)])
        res.append(ele)
    res.extend(temp_iter)
    return res


def divdif(a, b, xx, yy):
    if (b - a == 1):
        return (yy[b] - yy[a]) / (xx[b] - xx[a])
    return (divdif(a + 1, b, xx, yy) - divdif(a, b - 1, xx, yy)) / (xx[b] - xx[a])


def inewton(n, x, xx, yy):
    s = yy[0]  # f
    for i in range(1, n + 1):
        mul = 1
        for j in range(i):
            mul *= (x - xx[j])
        mul *= divdif(0, i, xx, yy)
        print("s_" + str(i) + "=\t" + str(mul))
        s += mul
    return s


def aitken(x, xx, yy, a, b):
    f1 = yy[a] if b - a == 1 else aitken(x, xx, yy, a, b - 1)
    f2 = yy[b] if b - a == 1 else aitken(x, xx, yy, a + 1, b)
    return (1 / (xx[b] - xx[a])) * ((x - xx[a]) * f2 - (x - xx[b]) * f1)


def linSpace(a, b, s):
    x = []
    # x.append(a)
    e = 1 / s
    e0 = 0
    while e0 <= 1:
        _x = round(a + (b - a) * e0, int(abs(math.log10(e))))
        # _x=a+(b-a)*e0
        x.append(_x)
        e0 += e
    return x

x1=input()
x2=input()
x3=input()
n = input()
for i in range(n):
    x[i]=input()
for i in range(n):
    y[i]=input()


xx = linSpace(x[0], x[-1], 100)
#xx = linSpace(2, 2.5, 100)

#yy = [nbackward(n, i, x, y) for i in xx]
#yy = [stirling(i, 1.0, x, y) for i in xx]
'''
print("nfoward(x1)=\t"+str(nforward(n,x1,x,y)))
print("nfoward(x2)=\t"+str(nforward(n,x2,x,y)))
print("nfoward(x3)=\t"+str(nforward(n,x3,x,y)))

print("nbackward(x1)=\t"+str(nbackward(n,x1,x,y)))
print("nbackward(x2)=\t"+str(nbackward(n,x2,x,y)))
print("nbackward(x3)=\t"+str(nbackward(n,x3,x,y)))
'''
#print("stirliing x2=\t"+str(stirling(x2, 1.50, x, y)))
#print("stirliing x3=\t"+str(stirling(x3, 1.25, x, y)))
#print(stirling(x2,1.25,x,y))
plt.plot(x, y, marker=".")

# print([x[j] - x[j-1] for j in i[1:]])

#plt.plot(xx, yy)
plt.rcParams['lines.linewidth'] = 2  # Синтакс 2
#
# for j in range(len(i)-1,-1,-1):
#     print(str(i[j])+"\t"+str(d[j]))
# plt.plot(i,d)
plt.vlines(x1, -0.4, 0.8)
plt.vlines(x2, -0.4, 0.8)
plt.vlines(x3, -0.4, 0.8)
plt.xlabel('x')
plt.ylabel('y')
plt.legend(['initial','stirling x3', 'x1','x2','x3'])
plt.show()
