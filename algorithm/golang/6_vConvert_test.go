package golang

import "testing"

func TestVCovert(t *testing.T) {

	tests := []struct {
		Name    string
		Str     string
		RowsNum int
		Want    string
	}{
		{
			Name:    "case1",
			Str:     "PAYPALISHIRING",
			RowsNum: 3,
			Want:    "PAHNAPLSIIGYIR",
		},
		{
			Name:    "case2",
			Str:     "PAYPALISHIRING",
			RowsNum: 4,
			Want:    "PINALSIGYAHRPI",
		},
	}

	for _, test := range tests {
		t.Run(test.Name, func(t *testing.T) {
			result := vConvert(test.Str, test.RowsNum)
			if result == test.Want {
				t.Logf("test pass !!!")
			} else {
				t.Logf("test failed, test:%+v, result:%s", test, result)
			}
		})
	}
}
