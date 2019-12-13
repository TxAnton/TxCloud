import math
import numpy


def gauss(A):
    n=len(A)
    lc = False#lin comb
    for brow in range(n-1):
        A[brow::1] = sorted(A[brow::1], key=lambda x: -abs(x[brow]))
        for crow in range(brow+1,n):
            if A[brow][brow] ==0:
                print("lc")
                lc=True
                continue
            mul = A[crow][brow] / A[brow][brow]
            for ccol in range(n+1):
                A[crow][ccol]-=A[brow][ccol] * mul

    ic=False           #insolvable
    for brow in range(n-1,-1,-1):
        #A[brow::1] = sorted(A[brow::1], key=lambda x: -abs(x[brow]))
        for crow in range(brow-1,-1,-1):
            if A[brow][brow] ==0:
                print("lc")
                ic=True
                continue
            mul = A[crow][brow] / A[brow][brow]
            for ccol in range(n+1):
                A[crow][ccol]-=A[brow][ccol] * mul

    if ic: return False

    x=[]
    for i in range(n):
        x.append(A[i][-1]/A[i][i])
    return x

def iter(A):
    b = [i[-1] for i in A]
    A = [i[:-1] for i in A]

    n=len(A)

    C = [[0 for i in range(n)]for j in range(n)]
    d = [0 for i in range(n)]

    for i in range(n):
        for j in range(n):
            if i==j:
                C[i][j] = 0
            else:
                C[i][j] = -A[i][j] / A[i][i]
                d[i] = b[i] / A[i][i]

    print(C)
    print(d)



    A = numpy.array(A)
    b = numpy.array(b)
    C = numpy.array(C)
    d = numpy.array(d)

    print("N", numpy.linalg.norm(C))

    x0 = numpy.array([0.47 for i in range(n)])
    x = x0
    for i in range(10):
        x = C.dot(x)+d



    print("Foo",x)
    return 0


if __name__ == '__main__':
    A=[]
    n = int(input())
    [A.append([int(j) for j in input().strip(' ').split(' ')]) for i in range(n)]
    B=[i[:-1] for i in A]
    #iter(A)
    x = gauss(A)

    [print(i) for i in x]
    # print([i for i in [str(j) for j in A]])