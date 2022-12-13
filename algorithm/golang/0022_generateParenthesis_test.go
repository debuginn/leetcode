package golang

import "testing"

func TestGenerateParenthesis(t *testing.T) {
	tests := []struct {
		Name  string
		Input int
		Want  []string
	}{
		{"case2", 1, []string{"()"}},
		{"case3", 3, []string{"((()))", "(()())", "(())()", "()(())", "()()()"}},
	}

	for _, test := range tests {
		t.Run(test.Name, func(t *testing.T) {
			result := generateParenthesis(test.Input)
			if stringSliceEqualBCE(result, test.Want) {
				t.Logf("test pass !!!")
			} else {
				t.Fatalf("test not pass, %+v, result:%v", test, result)
			}
		})
	}
}
