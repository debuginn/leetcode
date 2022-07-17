package golang

import "testing"

func TestLongestCommonPrefix(t *testing.T) {
	tests := []struct {
		Name  string
		Input []string
		Want  string
	}{
		{"case1", []string{"flower", "flow", "flight"}, "fl"},
		{"case2", []string{"dog", "racecar", "car"}, ""},
	}

	for _, test := range tests {
		t.Run(test.Name, func(t *testing.T) {
			result := longestCommonPrefix(test.Input)
			if result == test.Want {
				t.Logf("test pass !!!")
			} else {
				t.Fatalf("test not pass, %+v, result:%v", test, result)
			}
		})
	}
}
