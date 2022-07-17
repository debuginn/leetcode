package golang

import "testing"

func TestReverse(t *testing.T) {

	tests := []struct {
		Name  string
		Input int
		Want  int
	}{
		{Name: "case1", Input: 123, Want: 321},
		{Name: "case2", Input: -123, Want: -321},
		{Name: "case3", Input: 120, Want: 21},
		{Name: "case4", Input: 0, Want: 0},
	}

	for _, test := range tests {
		t.Run(test.Name, func(t *testing.T) {
			result := reverse(test.Input)
			if result == test.Want {
				t.Logf("test pass !!!")
			} else {
				t.Logf("test failed, test:%+v, result:%d", test, result)
			}
		})
	}

}
