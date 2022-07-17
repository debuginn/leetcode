package golang

func romanToInt(s string) int {

	mp := map[byte]int{
		'I': 1,
		'V': 5,
		'X': 10,
		'L': 50,
		'C': 100,
		'D': 500,
		'M': 1000,
	}

	ans := 0
	tmp := 1000
	for i := 0; i < len(s); i++ {
		now := mp[s[i]]
		if tmp < now {
			ans -= 2 * tmp
		}
		ans += now
		tmp = now
	}
	return ans
}
