import math



etalonEps = 0.00000000000001

def horda(F=(lambda x: 2.5 * (x**2 - 5.3)), Left=0, Right=10, Eps=0.000001, Iters=10,  type=1, echo=1):
    ############################################################
    #     F - function to investigate
    #     Left - a - left border of interval
    #     Right - b - right border of interval
    #
    # F(a) and F(b) should be of diffrent signs: F(a)*F(b)<0
    #
    # type:
    #     0 - do 'Iters' iterations
    #     1 - iterate till percision reaches 'Eps'
    # echo:
    #     0 - silent
    #     1 - print data as iterations goes on
    ############################################################
    FLeft = F(Left)
    FRight = F(Right)
    X = -1
    Y = -1

    if (FLeft * FRight > 0.0):
        print("Wrong interval. Required: F(a) * F(b) < 0")
        exit()

    if (Eps <= 0.0):
        print("Wrong precision. Required: Eps > 0")
        exit()

    if echo == 1 : eX = horda(F, Left, Right, etalonEps, 100000,  1, 0)[0]
    else: eX = 0

    if echo == 1:
        print("Interval [a,b]: " + "[" + str(Left) + "," + str(Right) + "]")
        print("F(a) * F(b) < 0 => interval is correct")
        print("Etalon x* = " + str(eX))
        print("\nHorde equation: (x-a)/(y-f(a) = (b-a)/(f(b)-f(a)")
        print("Intersection with OX(x=c0, y=0): c0=a- f(a) * (b-a) / (f(b)-f(a))\n")

    N = 0

    if (FLeft == 0.0):
        if echo == 1: print("Bad stuff: left border is root (f(a)=0), better take different one")
        return Left

    if (FRight == 0.0):
        if echo == 1: print("Bad stuff: right border is root (f(b)=0), better take different one")
        return Right

    while abs(Y) >= Eps if type == 1 else Iters > 0:
        if echo == 1:
            print("Iteration " + str(N+1) + ":")
            print("\t[a, b] : " + "[" + str(Left) + ", " + str(Right) + "]")

        X = Left - (Right - Left) * FLeft / (FRight - FLeft)
        Y = F(X)

        if echo == 1:
            print("\tInterection with OX:")
            print("\t c0 = x_" + str(N+1) + " = " + str(X))
            print("\tf(c0) = " + str(Y))

        if (Y == 0.0):
            print("x_current = x* = "+X)
            return X

        if (Y * FLeft < 0.0):
            if echo == 1:
                print("\tf(a) * f(c0) < 0 => new [left, right] = [a, c0] = " + "[" + str(Left) + ", " + str(X) + "]")
            Right = X
            FRight = Y
        else:
            if echo == 1:
                print("\tf(c0) * f(b) < 0 => new [left, right] = [c0, b] = " + "[" + str(X) + ", " + str(Right) + "]")

            Left = X
            FLeft = Y

        N += 1
        Iters -= 1

    if echo==1:
        print("\nResult:")
        print("x_"+str(N)+" = "+str(X))
        print("Etalon x* = " + str(eX))
        print("Error (Epsilon?) = |x_" + str(N) + " - x*| = " + str(abs(X-eX)))
        print("f(x_" + str(N) + ")  = " + str(F(X)))

    return (X, N);

def newton(F, F1, X, m1, M2, Eps=0.000001, Iters = 10, type=1, echo=1):
    ###############################################################################
    # F - function to investigate
    # F1 - first derivative of F (f')
    # X - first evaluation of root. Required: f(x) * f''(x) > 0)
    #
    # !Function's f second derivative f'' should exist!
    #
    # m1 - min abs value of first derivative of f on [a,b] (min[a,b] f')
    # M2 - max abs value of second derivative of f on [a,b] (max[a,b] f'')
    # type:
    #     0 - do 'Iters' iterations
    #     1 - iterate till percision reaches 'Eps'
    # echo:
    #     0 - silent
    #     1 - print data as iterations goes on
    ################################################################################


    Y, Y1, DX, Eps0=(0,0,0,0)

    N = 0

    if echo == 1: eX = newton(F,F1,X,m1,M2,etalonEps,Iters,1,0)
    else: eX = 0

    if echo == 1:
        print("Etalon x* = " + str(eX))
        print("x_n = x_n-1 - f(x_n-1)/f'(x_n-1)")

    Eps0 = math.sqrt(2 * m1 * Eps / M2)



    if echo == 1:
        print("Eps0 = sqrt( (2*m1*Eps)/(M2) ) = " + str(Eps0))

    DX=2*Eps0
    while (abs(DX) > Eps0 if type==1 else Iters>0):
        if echo == 1:
            print("Iteration " + str(N + 1) + ":")

        Y = F(X)

        if echo == 1:
            print("\tX_"+str(N)+" = "+str(X))

        if (Y == 0.0):
            return X

        Y1 = F1(X);

        if (Y1 == 0.0):
            print("Derivative turned to zero: f'("+str(X)+") = 0\n")
            exit()

        DX = Y / Y1
        X -= DX


        if echo==1:
            print("\tX_"+str(N+1)+" = X_"+str(N)+" - f("+str(N)+")/f'("+str(N)+") = "+str(X)+" - "+" "+str(Y) + "/"+ str(Y1) + " = "+str(X))
            print("\tDX = X_"+str(N+1)+" - X_"+str(N)+" = "+str(DX))

        N += 1
        Iters -= 1

    if echo==1:
        print("\nResult:")
        print("x_"+str(N)+" = "+str(X))
        print("Etalon x* = " + str(eX))
        print("Error (Epsilon?) = |x_" + str(N) + " - x*| = " + str(abs(X-eX)))
        print("f(x_" + str(N) + ")  = " + str(F(X)))

    return X

    #math.sin()
    #math.cos()
    #math.acos()
    #math.tan()
    #math.atan()
    #math.exp()
    #math.pi
    #x**2
    #x**(1/2)
    #math.sqrt()

def func(x):                    # Given function
    return math.sin(x)/(1+x)

def dfunc(x):                   # Function derivative (f'(x))
    return math.tan(x)**2 + 1

def p(n,x):
    nn=n-1
    if(n==0):return 1
    if(n==1):return x
    return ((2*nn+1)/(nn+1))*x*(p(n-1,x)) - (nn/(nn+1))*p(n-2,x)

def pn(n):
    return lambda x:p(n,x)

def pp(n,x):
    return n/(1-x**2)*(p(n-1,x)-x*p(n,x))

def ppn(n):
    return lambda x: pp(n, x)

def proot(n):
    lst=[]
    for i in range(1,n+1):
        x0=math.cos(math.pi * (4*i-1)/(4*n+2))
        lst.append(newton(pn(n),ppn(n),x0,1,1.87777,0.01,100,0,0))
    w = [2/((1-x**2)*(pp(n,x))**2) for x in lst]

    return [lst,w]

def _simps(h,n,x0,f):
    m=int(n/2)
    s=0
    for i in range (m):
        s+=f((x0+(2 * i)*h)) + 4 * f((x0+(2 * i + 1)*h)) + f((x0+(2 * i + 2)*h))
    s*=h/3
    return s

def simps(a,b,e,f):
    h,h2,Ih,Ih2=(0,0,0,0)
    k = 4
    e0 = e * ((2**k) - 1)
    d = e0 + 1
    n = 1

    Ih2 = _simps(((b - a) / n),n, a, f)
    while d>=e0:
        n*=2
        Ih = Ih2;
        Ih2 = _simps(((b - a) / n), n, a, f);
        d = abs(Ih2 - Ih);
    return [(Ih2 - (Ih2 - Ih) / 15),n]


def gauss(a,b,f,nn):
    def R(n):
        #m = f(i for i in range(a,b,e))
        #m1=max(m)
        r = ((b-a)/(2.5*math.sqrt(n)))*((b-a)/(3*n))**(2*n)
        return n
    #n=1
    #while(e>R(n)):n+=1

    x,w=proot(nn)
    t = [(a+b)/2 + ((b-a)/2)*i for i in x]
    s = sum([w[i]*f(t[i]) for i in range(len(t))])
    l1 = len(x)
    l2 = len(w)
    I = ((b-a)/2 * s)
    return I

a=0
b=1
e=0.00000000000000001

#print(proot(20))
s=simps(a,b,e,func)
print(s)

#for n in []
g = gauss(a,b,func,2)

d=[]
gg=[]
nn=[]
for n in range(22):
    g = gauss(a, b, func, n)
    nn.append(n)
    gg.append(g)
    d.append(abs(g-s[0]))
    print(str(n)+"\t"+str(g)+"\t" +str(abs(g-s[0])))
print(nn)
print(gg)
print(d)


#print(simps(math.pi/2,math.pi,0.0001,(lambda x:math.sqrt(x)*math.e**(-x**2) ) ))



#Horda
Iterations = 10                 # Needed amount of iterations
Interval_a = 1                  # Left border of interval
Interval_b = 1.5                # Right border of interval

#horda(F=func, Left=Interval_a, Right=Interval_b, Iters=Iterations, type=0, echo=1)
#horda(F=func, Left=Interval_a, Right=Interval_b, Eps=0.00001, type=0, echo=1)


#Newton
Iterations = 5                 # Needed amount of iterations
_m1 = 3.4255                   # min abs value of first derivative of f on [a,b] (min[a,b] f')
_M2 = 536.3388                 # max abs value of second derivative of f on [a,b] (max[a,b] f'')
x0 = 1.5                       # first evaluation of root. Required: f(x) * f''(x) > 0)

#newton(F=func,F1=dfunc,X=x0,m1=_m1,M2=_M2,Iters=Iterations,type=0,echo=1)
#newton(F=func,F1=dfunc,X=x0,m1=_m1,M2=_M2,Eps=0.00001,type=1,echo=1)