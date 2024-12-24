package main

import "testing"
import "fmt"
import "reflect"

func TestMainFunction(t *testing.T) {
	product := simpleCalc(3, 5)
	expectedProduct := 8
	fmt.Println(reflect.TypeOf(expectedProduct))
	if product != expectedProduct {
		t.Errorf("expected %s, got %s", expectedProduct, product)
	}
}
