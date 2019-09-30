N=5

d=[45,45,50,45,46]
f=[312,313,310,312,316]

F=[ (d[i]*f[i])/(f[i]-d[i]) for i in range(len(d)) ]
print(F)

ap_F=sum(F)/len(F)

print(ap_F)

Sf=((sum([(i-ap_F)**2 for i in F]))/(N*(N-1)))**0.5

dF=Sf*2.8
print(dF)

ap_d = sum(d)/len(d)
ap_f = sum(f)/len(f)
print(ap_d)
print(ap_f)

af=-(ap_d*(ap_f-ap_d)-ap_d*ap_f)/((ap_f-ap_d)**2)
print(af)

ad=(ap_f*(ap_f-ap_d)-ap_d*ap_f)/((ap_f-ap_d)**2)
print(ad)

thF=0.5*ad+0.5*af
print(thF)

print(thF+dF)

#dap_l=(L**2-l**2)/(4*L)
#print(dap_f)
'''
f=181.80
d=418.20
ad=(f*(d+f)-d*f)/((d+f)**2)
print(ad)
af=(d*(d+f)-d*f)/((d+f)**2)
print(af)

thF=0.5*ad+0.5*af
print(thF)
'''


