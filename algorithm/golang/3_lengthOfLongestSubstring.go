package golang

// https://leetcode.com/problems/longest-substring-without-repeating-characters/

func LengthOfLongestSubstring(s string) int {

	if len(s) <= 0 {
		return 0
	}

	// max   最长子串长度
	// start 最长字串开始索引值
	// end   最长字串结束索引值
	// index 出现重复字符的时候用来做偏移字符的
	max, start, end, index := 1, 0, 0, -1

	for i := 0; i < len(s); i++ {

		// 重置偏移
		index = -1

		// 计算从字串开始索引值开始出现重复字符的索引
		// 将字串索引开始调整至重复字符串处
		for j := start; j < i; j++ {
			if s[j] == s[i] {
				index = j
				break
			}
		}

		// 没有重复字符 偏移索引值没有变更，顺延结束索引
		// 存在重复字符 开始索引的值调整至没有重复字符处计算
		if index == -1 {
			end = i
		} else {
			start = index + 1
		}

		// 真正记录长度的是 max
		// 会把字符中所有存在的字串的长度做对比，最长的做比较存储
		if compare := end - (start - 1); compare > max {
			max = compare
		}

	}

	return max
}
