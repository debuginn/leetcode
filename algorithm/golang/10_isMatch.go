package golang

//   a a a
// a 1 1 1
// * 1 1 1

// https://leetcode.cn/problems/regular-expression-matching/
// https://leetcode.com/problems/regular-expression-matching/discuss/5651/Easy-DP-Java-Solution-with-detailed-Explanation
// author: dolphinwby

func isMatch(s string, p string) bool {

	// 去除边界
	if len(s) <= 0 || len(p) <= 0 {
		return false
	}

	m, n := len(s), len(p)

	// 构造 dp 动态规划 结构
	dp := make([][]bool, m+1)
	for i := 0; i <= m; i++ {
		dp[i] = make([]bool, n+1)
	}

	// 初始化状态 dp[0][0]
	dp[0][0] = true
	// 初始化状态 dp[0][j]
	for j := 1; j <= n; j++ {
		if p[j-1] == '*' {
			if dp[0][j-1] || (j > 1 && dp[0][j-2]) {
				dp[0][j] = true
			}
		}
	}

	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {

			// 如果 匹配正则表达式的 对应字符是当前匹配的字符 则满足匹配要求
			if p[j-1] == s[i-1] {
				dp[i][j] = dp[i-1][j-1]
			}

			// 如果 匹配正则表达式的 对应字符是 '.' 代表着当前字符满足匹配要求
			if p[j-1] == '.' {
				dp[i][j] = dp[i-1][j-1]
			}

			// 如果 匹配正则表达式的 对应字符是 '*' 此处分为两种情况
			if p[j-1] == '*' {
				// 若 匹配正则表达式 j-2 位 正好不是匹配的字符也不是匹配的 '.' 通配符号
				// 则 匹配表达式 算作空
				if (p[j-2] != s[i-1]) && (p[j-2] != '.') {
					dp[i][j] = dp[i][j-2]
				} else {
					// dp[i-1][j] 匹配表达式 匹配字符重复
					// dp[i][j-1] 匹配表达式 匹配单个字符
					// dp[i][j-2] 匹配表达式 匹配算作空
					dp[i][j] = dp[i-1][j] || dp[i][j-1] || dp[i][j-2]
				}
			}

		}
	}

	return dp[m][n]
}
