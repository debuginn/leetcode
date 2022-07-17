package golang

import "testing"

func TestThreeSumClosest(t *testing.T) {
	tests := []struct {
		Name   string
		Input  []int
		Input2 int
		Want   int
	}{
		{"case1", []int{-1, 2, 1, -4}, 1, 2},
		{"case1", []int{0, 0, 0}, 1, 0},
	}

	for _, test := range tests {
		t.Run(test.Name, func(t *testing.T) {
			result := threeSumClosest(test.Input, test.Input2)
			if result == test.Want {
				t.Logf("test pass !!!")
			} else {
				t.Fatalf("test not pass, %+v, result:%v", test, result)
			}
		})
	}
}
