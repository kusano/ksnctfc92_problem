from struct import *
from binascii import *

f = open("emb1.png", "rb")
header = f.read(8)
IDAT = ""
while True:
    size = unpack(">I", f.read(4))[0]
    chunk = f.read(4)
    data = f.read(size)
    crc = f.read(4)
    print size, chunk, crc.encode("hex")
    if chunk == "IHDR":
        IHDR = data
    if chunk == "IDAT":
        IDAT += data
    if chunk == "IEND":
        break

f = open("flower.png", "wb")
f.write("\x89PNG\r\n\x1a\x0a")

def write(chunk, data):
    f.write(pack(">I", len(data)))
    f.write(chunk)
    f.write(data)
    f.write(pack(">I", crc32(chunk+data)&0xffffffff))

flag = "FLAG{1jmmZSL4A7FSVyBz}"

write("IHDR", IHDR)
s = 0
for c in flag:
    write("IDAT", IDAT[s:s+ord(c)])
    s += ord(c)
write("IDAT", IDAT[s:])
write("IEND", "")
