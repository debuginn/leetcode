package golang

import "testing"

func TestIntToRoman(t *testing.T) {

	tests := []struct {
		Name  string
		Input int
		Want  string
	}{
		{"case1", 3, "III"},
		{"case2", 4, "IV"},
		{"case3", 9, "IX"},
		{"case4", 58, "LVIII"},
	}

	for _, test := range tests {
		t.Run(test.Name, func(t *testing.T) {
			result := intToRoman(test.Input)
			if result == test.Want {
				t.Logf("test pass !!!")
			} else {
				t.Fatalf("test not pass, %+v, result:%v", test, result)
			}
		})
	}
}
