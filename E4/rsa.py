import random

# Miller-Rabin
def isprime(n):
    if n<=1:
        return False
    if n==2:
        return True
    if n%2==0:
        return False
    d = n-1
    while d%2==0:
        d /= 2
    for _ in range(100):
        a = random.randint(0, n-2) + 1
        t = d
        y = pow(a, t, n)
        while t!=n-1 and y!=1 and y!=n-1:
            y = y*y%n
            t *= 2
        if y!=n-1 and t%2==0:
            return False
    return True

def nextprime(n):
    while not isprime(n):
        n += 1
    return n

def readflag(file, k):
    flag = open(file).read()
    flag = " "*(k/8-len(flag)) + flag
    return int(flag.encode("hex"), 16)

if __name__=="__main__":
    k = 2048
    r = random.SystemRandom()
    p = nextprime(r.randint(2**(k/2), 2**(k/2+1)))
    q = nextprime(r.randint(2**(k/2), 2**(k/2+1)))
    n = p*q
    e = r.randint(0, n-1)
    d = pow(e, (p-1)*(q-1)-1, n)
    flag = readflag("flag.txt", k)
    C = flag*e%n
    P = C*d%n
    assert flag==P
    print "n =", n
    print "e =", e
    print "C =", C
