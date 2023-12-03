package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
)

func check(e error) {
	if e != nil {
		panic(e)
	}
}

func main() {
	// dat, err := os.ReadFile("input.txt")
	file, err := os.Open("input.txt")
	check(err)

	scanner := bufio.NewScanner(file)
	counter := 1
	sum := 0
	for scanner.Scan() {
		line := scanner.Text()
		var first_num, last_num int
		first_set := false

		for _, char := range line {
			// fmt.Printf("%d: %s\n", pos, string(char))
			num, err := strconv.Atoi(string(char))
			if err != nil {
				continue
			}
			if first_set != true {
				first_num = num
			}
			first_set = true
			last_num = num
		}

		number, _ := strconv.Atoi(strconv.Itoa(first_num) + strconv.Itoa(last_num))
		fmt.Printf("Line %02d -> %s %d\n", counter, line, number)
		counter++
		sum = sum + number
	}

	if scanner.Err() != nil {
		log.Println(scanner.Err())
	}
	fmt.Printf("Sum: %d\n", sum)
}
