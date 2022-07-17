package golang

import "testing"

func TestMaxArea(t *testing.T) {

	tests := []struct {
		Name   string
		Param1 []int
		Want   int
	}{
		{
			"case1",
			[]int{1, 8, 6, 2, 5, 4, 8, 3, 7},
			49,
		},
		{
			"case2",
			[]int{1, 1},
			1,
		},
	}

	for _, test := range tests {
		t.Run(test.Name, func(t *testing.T) {
			result := maxArea(test.Param1)
			if result == test.Want {
				t.Logf("test pass !!!")
			} else {
				t.Fatalf("test not pass, %+v, result:%v", test, result)
			}
		})
	}
}
