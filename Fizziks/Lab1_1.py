import math

inputType = 1#0:default; not 0:file


toMeters = lambda x: x*(10**(-3)) #mm to m
#print(lines)

Epsilon = 1
Epsilon0 = 8.85 * 10**(-12)
U = 8 #max voltage
ddf = 2 #default delta f
h = 0.13

l=[]
r=[]
df=[]
E=[]
n = 0

#Input (SEE INPUT TYPE ABOVE ^^^)

if(inputType):
    #file
    lines = [line.rstrip('\n') for line in open('input.txt')]
    print(lines)
    n  = int(lines[0])
    r  = [toMeters(float(i)) for i in lines[1].split(' ')]
    l  = [toMeters(float(i)) for i in lines[2].split(' ')]
    df = [(float(i)) for i in lines[3].split(' ')]
    print("\nn :",n,"\nr :",r,"\nl :",l,"\ndf:",df)
else:
    n  = int(input("n:"))
    print("print r")
    r  = [toMeters(float(i)) for i in input().split(' ')]
    print("print l")
    l  = [toMeters(float(i)) for i in input().split(' ')]
    print("print delta fi")
    df = [(float(i)) for i in input().split(' ')]
    print("\nn :", n, "\nr :", r, "\nl :", l, "\ndf:", df)



#Counting E
print("\nМодуль напряженности")
print("\nE[i] = df[i]/r[i]")

for i in range(n+1):
    E.append(df[i]/r[i])
    print("E[",i,"] = ",df[i],"/",r[i]," = ",E[i],sep='')

#Counting Ch
print("\nПогонная емкость")
print("Epsilon =",Epsilon)
print("U =",U)

print("\nSum = ",end='')
Sum = 0
for i in range(n):
    Sum+=l[i] / r[i+1]
    print(l[i]," / ",r[i+1],sep='',end=' +')
print()

Ch =( (Epsilon * Epsilon0 * ddf) / U ) *  Sum
print("Ch = C/h = ( (Epsilon * Epsilon0 * ddf) / U ) * Sum{1..n}( l[i] / r[i] ) = ")
print("( (",Epsilon," * ",Epsilon0," * ",ddf,") / ",U," ) * ",Sum," ) = ",sep='')
print('=',Ch)

#Counting W
print("\nПлотность энергии")
W = []
print("W[i] = ( Epsilon * Epsilon0 * (E[i])^2 ) / 2")
for i in range(n+1):
    W.append(( Epsilon * Epsilon0 * (E[i])**2 ) / 2)
    print("W[",i,"] = ( ",Epsilon," * ",Epsilon0," * (",E[i],")^2 ) / 2 = ",sep='')
    print('=',W[i])

#Counting theoretical E
print("\nТеоретическая погонная емкость")
Ct = ( math.pi * Epsilon * Epsilon0 * (h*10) ) / math.log((h-r[0])/r[0],math.e)
#Ct = ( math.pi * Epsilon * Epsilon0 * (h/10) ) / math.log(50,math.e)
print("Cт = q / u = ( Pi * Epsilon * Epsilon0 * h ) / Ln((h-r[0])/r[0]) =")
print("    ( ",math.pi," * ",Epsilon," * ",Epsilon0," * (",h,") ) / ",math.log((h-r[0])/r[0],math.e))
print("Ct",Ct)
print("Ch",Ch)
print("Ch / Ct =",Ch / Ct)
