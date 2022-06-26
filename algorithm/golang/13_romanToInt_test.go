package golang

import "testing"

func TestRomanToInt(t *testing.T) {
	tests := []struct {
		Name  string
		Input string
		Want  int
	}{
		{"case1", "III", 3},
		{"case2", "IV", 4},
		{"case3", "IX", 9},
		{"case4", "LVIII", 58},
		{"case5", "MCM", 1900},
	}

	for _, test := range tests {
		t.Run(test.Name, func(t *testing.T) {
			result := romanToInt(test.Input)
			if result == test.Want {
				t.Logf("test pass !!!")
			} else {
				t.Fatalf("test not pass, %+v, result:%v", test, result)
			}
		})
	}
}
