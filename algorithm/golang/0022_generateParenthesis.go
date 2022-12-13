package golang

// generateParenthesis backtracking algorithm 回溯算法
func generateParenthesis(n int) []string {

	// 声明返回值及回溯函数
	var resp []string
	var generate func(left int, right int, n int, s string)

	// 回溯函数
	// 主要就是先回溯左括号在计算右括号
	// 二叉树剔除边界计算
	generate = func(left int, right int, n int, s string) {
		if left == n && right == n {
			resp = append(resp, s)
		}
		if left < n {
			generate(left+1, right, n, s+"(")
		}
		if right < left {
			generate(left, right+1, n, s+")")
		}
	}

	generate(0, 0, n, "")
	return resp
}
