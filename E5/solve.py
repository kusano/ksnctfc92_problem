flag1 = map(ord, "FLAG{bBVqBLqTxy3pR4F8}")
f = open("crypted.bin", "rb")
crypted = []
for _ in range(256*256):
    crypted += [map(ord, f.read(22))]

flag2 = []
for p in range(20):
    C = [0]*256
    for iv0 in range(256):
     for iv1 in range(256):
        key = [iv0, iv1] + flag2
        S = range(256)
        j = 0
        for i in range(p+2):
            j = (j+S[i]+key[i])%256
            S[i],S[j] = S[j],S[i]
        X = crypted[iv0*256+iv1][p+1] ^ flag1[p+1]
        t = S.index((p+2-X)%256) - (S[p+2]+j)
        C[t%256] += 1
    T = sorted((C[i], i) for i in range(256))[::-1]
    print "p", p
    for i in range(4):
        print T[i]
    flag2 += [T[0][1]]
    print "".join(map(chr, flag2))
    print

def RC4(plain, key):
    S = range(256)
    j = 0
    for i in range(256):
        j = (j+S[i]+key[i%len(key)])%256
        S[i],S[j] = S[j],S[i]

    crypted = []
    i = 0
    j = 0
    for p in plain:
        i = (i+1)%256
        j = (j+S[i])%256
        S[i],S[j] = S[j],S[i]
        crypted += [p ^ S[(S[i]+S[j])%256]]
    return crypted

for c0 in range(256):
    for c1 in range(256):
        if RC4(flag1, [0,0]+flag2+[c0,c1]) == crypted[0]:
            print "".join(map(chr, flag2+[c0,c1]))
