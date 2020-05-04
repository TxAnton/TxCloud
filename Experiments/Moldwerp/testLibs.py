from pydub import AudioSegment
from pydub.playback import play

import math

def pm(m,al):
    m = int(m)
    a = (al**m)
    b = math.exp(-al)
    c = math.factorial(m)
    return a*b/c


def pn(m,n,p):
    f = math.factorial
    q = 1-p
    return (f(n)/(f(m)*f(n-m))) * p**m * q**(n-m)

p = 0.0001*0.1*0.5
n = 10000000

la = p*n
print(la)
s = 0
for i in range(0,11):
    s+=pn(i,n,p)

print(s)

exit(0)


n = 200
p = 0.01
print(pn(4,n,p))


exit(0)
song = AudioSegment.from_mp3("in.mp3")
play(song)