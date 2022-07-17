package golang

import (
	"testing"
)

func TestFourSum(t *testing.T) {
	tests := []struct {
		Name   string
		Input  []int
		Target int
		Want   [][]int
	}{
		{"case1", []int{1, 0, -1, 0, -2, 2}, 0, [][]int{{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}}},
	}

	for _, test := range tests {
		t.Run(test.Name, func(t *testing.T) {
			result := fourSum(test.Input, test.Target)
			t.Logf("result:%+v", result)
		})
	}
}
