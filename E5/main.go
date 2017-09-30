package main

import (
	"crypto/rc4"
	"io/ioutil"
)

func main() {
	flag1 := []byte("FLAG{bBVqBLqTxy3pR4F8}")
	flag2, _ := ioutil.ReadFile("flag2.txt")
	crypted := []byte{}
	for iv0 := 0; iv0 < 256; iv0++ {
		for iv1 := 0; iv1 < 256; iv1++ {
			key := append([]byte{byte(iv0), byte(iv1)}, flag2...)
			cipher, _ := rc4.NewCipher(key)
			c := make([]byte, len(flag1))
			cipher.XORKeyStream(c, flag1)
			crypted = append(crypted, c...)
		}
	}
	ioutil.WriteFile("crypted.bin", crypted, 0644)
}
