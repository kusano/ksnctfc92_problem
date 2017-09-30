import math
import random

flag = "FLAG{8YDxdZTCAsugdBEv}"

random.seed(31337)
r = range(len(flag)+1)
random.shuffle(r)

print r[0]
T = ["get_flag(%2d, Acc) -> get_flag(%2d, [%3d|Acc]);" % (r[i], r[i+1], ord(flag[-i-1]))
    for i in range(len(flag))]
T.sort()
for t in T:
    print t
print r[-1]

for i in range(8):
    print "%04d" % random.randint(0,9999)

flag = "FLAG{UGZRtAx3xoYTvHNr}"
for f in flag:
    print "%.16f" % math.log(ord(f)+0.5)
