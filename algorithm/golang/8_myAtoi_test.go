package golang

import "testing"

func TestMyAtoi(t *testing.T) {

	tests := []struct {
		Name  string
		Input string
		Want  int
	}{
		{Name: "case1", Input: "words and 987", Want: 0},
		{Name: "case2", Input: "-123", Want: -123},
		{Name: "case3", Input: "-9223372036854775809", Want: -2147483648},
	}

	for _, test := range tests {
		t.Run(test.Name, func(t *testing.T) {
			result := myAtoi(test.Input)
			if result == test.Want {
				t.Logf("test pass !!!")
			} else {
				t.Logf("test failed, test:%+v, result:%d", test, result)
			}
		})
	}

}
