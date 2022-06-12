package golang

import (
	"math"
	"strings"
)

func myAtoi(s string) int {

	// 去除空格
	s = strings.TrimSpace(s)

	// 空串返回 0
	if s == "" {
		return 0
	}

	flag := 1
	num := 0
	for i, c := range s {

		if c >= '0' && c <= '9' {
			num = num*10 + int(c-'0')
		} else if c == '-' && i == 0 {
			flag = -1
		} else if c == '+' && i == 0 {
			flag = 1
		} else {
			break
		}

		if num > math.MaxInt32 {
			if flag == -1 {
				return math.MinInt32
			}
			return math.MaxInt32
		}
	}

	return num * flag
}
