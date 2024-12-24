package main

import (
	"bytes"
	"fmt"
	"log"
)

type Server struct {
	a string
}

func simpleCalc(a int, b int) (product int) {
	return a + b
}

func (s Server) funcName(input string) (output string, err error) {
	return input, nil
}

func main() {
	var buf bytes.Buffer
	logger := log.New(&buf, "logger: ", log.Lshortfile)
	fmt.Println("hi")
	s := Server{}
	callFunction, err := s.funcName("input")
	if err != nil {
		logger.Fatal()
	}

	fmt.Println(callFunction)
}
