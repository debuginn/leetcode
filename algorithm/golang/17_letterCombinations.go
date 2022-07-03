package golang

func letterCombinations(digits string) []string {

	digitsMap := map[byte][]string{
		'2': []string{"a", "b", "c"},
		'3': []string{"d", "e", "f"},
		'4': []string{"g", "h", "i"},
		'5': []string{"j", "k", "l"},
		'6': []string{"m", "n", "o"},
		'7': []string{"p", "q", "r", "s"},
		'8': []string{"t", "u", "v"},
		'9': []string{"w", "x", "y", "z"},
	}

	var res []string
	if len(digits) <= 0 {
		return res
	}
	if len(digits) == 0 {
		return digitsMap[digits[0]]
	}

	return []string{}
}
