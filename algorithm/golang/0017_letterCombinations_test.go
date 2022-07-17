package golang

import "testing"

func TestLetterCombinations(t *testing.T) {
	tests := []struct {
		Name  string
		Input string
		Want  []string
	}{
		{"case1", "23", []string{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}},
		{"case2", "", []string{}},
		{"case1", "2", []string{"a", "b", "c"}},
	}

	for _, test := range tests {
		t.Run(test.Name, func(t *testing.T) {
			result := letterCombinations(test.Input)
			if stringSliceEqualBCE(result, test.Want) {
				t.Logf("test pass !!!")
			} else {
				t.Fatalf("test not pass, %+v, result:%v", test, result)
			}
		})
	}
}
