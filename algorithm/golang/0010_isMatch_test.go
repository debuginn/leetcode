package golang

import "testing"

func TestIsMatch(t *testing.T) {

	tests := []struct {
		Name   string
		Param1 string
		Param2 string
		Want   bool
	}{
		{
			"case1",
			"aa",
			"a",
			false,
		},
		{
			"case2",
			"aa",
			"a*",
			true,
		},
		{
			"case3",
			"ab",
			".*",
			true,
		},
	}

	for _, test := range tests {
		t.Run(test.Name, func(t *testing.T) {
			result := isMatch(test.Param1, test.Param2)
			if result == test.Want {
				t.Logf("test pass !!!")
			} else {
				t.Fatalf("test not pass, %+v, result:%v", test, result)
			}
		})
	}
}
