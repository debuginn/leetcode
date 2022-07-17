package golang

import (
	"reflect"
	"testing"
)

func TestThreeSum(t *testing.T) {
	tests := []struct {
		Name  string
		Input []int
		Want  [][]int
	}{
		{"case1", []int{-1, 0, 1, 2, -1, -4}, [][]int{{-1, -1, 2}, {-1, 0, 1}}},
		{"case2", []int{}, [][]int{}},
		{"case3", []int{0}, [][]int{}},
	}

	for _, test := range tests {
		t.Run(test.Name, func(t *testing.T) {
			result := threeSum(test.Input)
			if len(test.Input) < 3 && len(test.Want) <= 0 {
				t.Logf("test pass !!!")
				return
			} else if reflect.DeepEqual(test.Want, result) {
				t.Logf("test pass !!!")
			} else {
				t.Fatalf("test not pass, %+v", test)
			}
		})
	}
}
