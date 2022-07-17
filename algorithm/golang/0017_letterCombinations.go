package golang

// letterCombinations
// 回溯算法
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

	var recur func(str string, count int, ans string)

	recur = func(str string, count int, ans string) {
		if len(str) == count {
			res = append(res, ans)
			return
		}
		s := digitsMap[str[count]]
		for i := 0; i < len(s); i++ {
			recur(str, count+1, ans+s[i])
		}
	}

	recur(digits, 0, "")

	return res
}
