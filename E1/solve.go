package main

import (
	"fmt"
	"image"
	_ "image/png"
	"os"
)

func main() {
	file, _ := os.Open("flag2.png")
	img, _, _ := image.Decode(file)
	for y := 0; y < 177; y++ {
		for x := 0; x < 177; x++ {
			r, _, _, _ := img.At(x*8+36, y*8+36).RGBA()
			if r < 65536/2 {
				fmt.Print("#")
			} else {
				fmt.Print(" ")
			}
		}
		fmt.Println()
	}
}
