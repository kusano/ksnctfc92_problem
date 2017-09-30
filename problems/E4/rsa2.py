from rsa import *

k = 2048
r = random.SystemRandom()
p = nextprime(r.randint(2**(k/2), 2**(k/2+1)))
q = nextprime(p+1)
n = p*q
e = 65537
flag = readflag("flag2.txt", k)
C = pow(flag, e, n)
print "n =", n
print "C =", C
