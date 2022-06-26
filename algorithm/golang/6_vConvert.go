package golang

import "strings"

func vConvert(s string, numRows int) string {

	// 一行直接返回
	if numRows == 1 {
		return s
	}

	// 创建 num 的切片
	rows := make([]string, numRows)

	// 计算循环周期
	n := 2*numRows - 2

	for i, char := range s {

		// 计算字符串在周期内的索引位置
		x := i % n

		// 计算行数
		// 循环周期前 numRows 行个索引,      计算行数 是 y = n
		// 循环周期后 周期数-numRows 个索引, 计数行数 是 y = n - x
		y := min(x, n-x)

		// 将字符存在索引的行切片上面
		rows[y] += string(char)
	}
	return strings.Join(rows, "")
}
