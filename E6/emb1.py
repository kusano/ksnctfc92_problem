from PIL import Image

image = Image.open("original.png")
flag = Image.open("flag1.png")

for y in range(480):
    for x in range(640):
        r,g,b = image.getpixel((x, y))
        b = b&0xfd | int(flag.getpixel((x, y))[0] > 128)<<1
        image.putpixel((x, y), (r,g,b))

image.save("emb1.png")
