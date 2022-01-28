package golang

import "testing"

func TestFindMedianSortedArrays(t *testing.T) {

	tests := []struct {
		Name  string
		Nums1 []int
		Nums2 []int
		Want  float64
	}{
		{
			Name:  "case1",
			Nums1: []int{1, 3},
			Nums2: []int{2},
			Want:  2.00000,
		},
		{
			Name:  "case2",
			Nums1: []int{1, 2},
			Nums2: []int{3, 4},
			Want:  2.50000,
		},
	}

	for _, test := range tests {
		t.Run(test.Name, func(t *testing.T) {
			result := FindMedianSortedArrays(test.Nums1, test.Nums2)
			if result == test.Want {
				t.Logf("test pass !!!")
			} else {
				t.Logf("test failed, test:%+v, result:%f", test, result)
			}
		})
	}

}
