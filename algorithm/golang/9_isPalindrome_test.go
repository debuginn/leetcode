package golang

import "testing"

func TestIsPalindrome(t *testing.T) {
	tests := []struct {
		Name  string
		Input int
		Want  bool
	}{
		{Name: "case1", Input: 121, Want: true},
		{Name: "case2", Input: -121, Want: false},
		{Name: "case3", Input: 10, Want: false},
	}

	for _, test := range tests {
		t.Run(test.Name, func(t *testing.T) {
			result := isPalindrome(test.Input)
			if result == test.Want {
				t.Logf("test pass !!!")
			} else {
				t.Logf("test failed, test:%+v, result:%v", test, result)
			}
		})
	}

}
