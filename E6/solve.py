def readLiteral(bit):
	literal = 0
	for _ in range(7):
		literal = literal<<1 | bit.pop(0)
	if literal<=0b0010111:
		literal += 256 - 0b000000
	else:
		literal = literal<<1 | bit.pop(0)
		if literal<=0b10111111:
			literal += 0 - 0b00110000
		elif literal<=0b11000111:
			literal += 280 - 0b11000000
		else:
			literal = literal<<1 | bit.pop(0)
			literal += 144 - 0b110010000
	return literal

def readLen(literal, bit):
	ext = [
		0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
		1, 1, 2, 2, 2, 2, 3, 3, 3, 3,
		4, 4, 4, 4, 5, 5, 5, 5, 0,
	]
	len = [
		3, 4, 5, 6, 7, 8, 9, 10, 11, 13,
		15, 17, 19, 23, 27, 31, 35, 43, 51, 59,
		67, 83, 99, 115, 131, 163, 195, 227, 258,
	]
	e = 0
	for i in range(ext[literal-257]):
		e |= bit.pop(0)<<i
	return len[literal-257] + e

def readDist(bit):
	symbol = 0
	for _ in range(5):
		symbol = symbol<<1 | bit.pop(0)
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
	e = 0
	for _ in range(ext[symbol]):
		e = e<<1 | bit.pop(0)
	return dist[symbol] + e

def decomp(data):
	data = data[2:-4]
	bit = []
	for d in data:
		for i in range(8):
			bit += [ord(d)>>i&1]

	result = ""
	while True:
		BFINAL = bit.pop(0)
		BTYPE = bit.pop(0)
		BTYPE |= bit.pop(0)<<1
		assert BTYPE==1

		while True:
			literal = readLiteral(bit)
			if literal<256:
				result += chr(literal)
			elif literal==256:
				break
			else:
				len = readLen(literal, bit)
				dist = readDist(bit)
				print chr(len),
				for _ in range(len):
					result += result[-dist]

		if BFINAL:
			break
	return result

print decomp(open("black.png", "rb").read()[0x29:0x1fb7])
