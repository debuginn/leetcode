package golang

import "testing"

func TestIsValid(t *testing.T) {
	tests := []struct {
		Name  string
		Input string
		Want  bool
	}{
		{"case1", "()", true},
		{"case2", "()[]{}", true},
		{"case3", "(]", false},
		{"case4", "([)]", false},
		{"case5", "{[]}", true},
	}

	for _, test := range tests {
		t.Run(test.Name, func(t *testing.T) {
			result := isValid(test.Input)
			if result == test.Want {
				t.Logf("test pass !!!")
			} else {
				t.Fatalf("test not pass, %+v, result:%v", test, result)
			}
		})
	}
}
