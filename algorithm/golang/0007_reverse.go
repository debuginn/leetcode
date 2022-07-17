package golang

import "math"

func reverse(x int) int {

	resp := 0
	for x != 0 {

		resp = resp*10 + x%10
		x /= 10

		if resp > math.MaxInt32 || resp < math.MinInt32 {
			return 0
		}
	}

	return resp
}
