package golang

import "testing"

func TestLengthOfLongestSubstring(t *testing.T) {

	tests := []struct {
		Name string
		Str  string
		Want int
	}{
		{
			Name: "case1",
			Str:  "abcabcbb",
			Want: 3,
		},
		{
			Name: "case2",
			Str:  "bbbbbb",
			Want: 1,
		},
		{
			Name: "case3",
			Str:  "pwwkewqi",
			Want: 5,
		},
		{
			Name: "case4",
			Str:  "aab",
			Want: 2,
		},
	}

	for _, test := range tests {
		t.Run(test.Name, func(t *testing.T) {
			res := LengthOfLongestSubstring(test.Str)
			if res == test.Want {
				t.Logf("test pass!")
			}
		})
	}

}

func TestName(t *testing.T) {
	a := "aab"
	t.Log(a[1:])
}
