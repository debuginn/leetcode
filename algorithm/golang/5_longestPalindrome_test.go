package golang

import "testing"

func TestLongestPalindrome(t *testing.T) {

	tests := []struct {
		Name  string
		Nums1 string
		Want  string
	}{
		{
			Name:  "case1",
			Nums1: "babcd",
			Want:  "bab",
		},
		{
			Name:  "case2",
			Nums1: "cbbd",
			Want:  "bb",
		},
	}

	for _, test := range tests {
		t.Run(test.Name, func(t *testing.T) {
			result := longestPalindrome(test.Nums1)
			if result == test.Want {
				t.Logf("test pass !!!")
			} else {
				t.Logf("test failed, test:%+v, result:%s", test, result)
			}
		})
	}
}
