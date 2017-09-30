import sys
import socket
import hashlib

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(("localhost", 1234))

def read(l):
    d = ""
    while len(d)<l:
        t = s.recv(l-len(d))
        if len(t)==0:
            print "error"
            sys.exit(0)
        d += t
    return d

print read(len("Wait...\n"))

hash = []

for i in range(22):
    print read(len("Input data length: "))
    s.send("%d\n"%(i+48))
    print read(len("Input data: "))
    s.send("a"*(i+48)+"\n")
    print read(len("MD5(your data): 08ff5f7301d30200ab89169f6afdb7af\n"))
    t = read(len("MD5(flag): bbb74d8f36fae25d5f41a8733597acfc\n"))
    print t
    hash += [t[-33:-1]]

flag = ""
for i in range(22)[::-1]:
    for c in range(256):
        if hashlib.md5("a"*i+chr(c)+flag).hexdigest()==hash[i]:
            flag = chr(c)+flag
            break
    print i, flag
print flag
