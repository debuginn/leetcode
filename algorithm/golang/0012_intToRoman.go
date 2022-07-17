package golang

// 字符          数值
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
//

func intToRoman(num int) string {

	romanStr := ""

	romanSlice := []struct {
		Val   int
		Roman string
	}{
		{1000, "M"},
		{900, "CM"},
		{500, "D"},
		{400, "CD"},
		{100, "C"},
		{90, "XC"},
		{50, "L"},
		{40, "XL"},
		{10, "X"},
		{9, "IX"},
		{5, "V"},
		{4, "IV"},
		{1, "I"},
	}

	for _, roman := range romanSlice {
		for num >= roman.Val {
			romanStr += roman.Roman
			num -= roman.Val
		}
	}

	return romanStr
}
