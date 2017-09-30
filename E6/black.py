import zlib
import struct

def encodeLiteral(literal):
    if literal < 144:
        x = 0b00110000 + literal
        w = 8
    elif literal < 256:
        x = 0b110010000 + literal - 144
        w = 9
    elif literal < 280:
        x = 0b0000000 + literal - 256
        w = 7
    else:
        x = 0b11000000 + literal - 280
        w = 8
    return [x>>i&1 for i in range(w)[::-1]]

def encodeLen(l):
    ext = [
        0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
        1, 1, 2, 2, 2, 2, 3, 3, 3, 3,
        4, 4, 4, 4, 5, 5, 5, 5, 0,
    ]
    length = [
        3, 4, 5, 6, 7, 8, 9, 10, 11, 13,
        15, 17, 19, 23, 27, 31, 35, 43, 51, 59,
        67, 83, 99, 115, 131, 163, 195, 227, 258,
    ]
    for i in range(len(length)):
        if length[i] <= l < length[i]+(1<<ext[i]):
            break
    return (
        encodeLiteral(i+257) +
        [(l-length[i])>>e&1 for e in range(ext[i])])

def encodeDist(d):
    ext = [
        0, 0, 0, 0, 1, 1, 2, 2, 3, 3,
        4, 4, 5, 5, 6, 6, 7, 7, 8, 8,
        9, 9, 10, 10, 11, 11, 12, 12, 13, 13,
    ]
    dist = [
        1, 2, 3, 4, 5, 7, 9, 13, 17, 25,
        33, 49, 65, 97, 129, 193, 257, 385, 513, 769,
        1025, 1537, 2049, 3073, 4097, 6145, 8193, 12289, 16385, 24577,
    ]
    for i in range(len(dist)):
        if dist[i] <= d < dist[i]+(1<<ext[i]):
            break
    return (
        [i>>j&1 for j in range(5)] +
        [(d-dist[i])>>j&1 for j in range(ext[i])])

def compress():
    flag = "FLAG{uERH37fgoBY6VObi}"

    bit = [1, 1, 0]

    bit += encodeLiteral(0)
    data = "\x00"

    for i in range(len(flag)):
        bit += encodeLen(ord(flag[i]))
        bit += encodeDist(1)
        data += "\x00"*ord(flag[i])

    size = (640*3+1)*480
    while len(data)<size:
        l = min(size-len(data), 258)
        bit += encodeLen(l)
        bit += encodeDist(1)
        data += "\x00"*l

    bit += encodeLiteral(0x100)
    while len(bit)%8 != 0:
        bit += [0]
    byte = ""
    for i in range(0, len(bit), 8):
        b = 0
        for j in range(8)[::-1]:
            b = b<<1 | bit[i+j]
        byte += chr(b)

    return "\x78\x9c" + byte + struct.pack(">I", zlib.adler32(data)&0xffffffff)

print len(compress().decode("zlib"))

from struct import *
from binascii import *

f = open("black.png", "wb")
f.write("\x89PNG\r\n\x1a\x0a")

def write(chunk, data):
    f.write(pack(">I", len(data)))
    f.write(chunk)
    f.write(data)
    f.write(pack(">I", crc32(chunk+data)&0xffffffff))

write("IHDR", pack(">IIBBBBB",
    640, # width
    480, # height
    8, # bitdepth
    2, # color
    0, # comp
    0, # filter
    0, # interlace
))

write("IDAT", compress())
write("IEND", "")
