package golang

// https://leetcode.cn/problems/container-with-most-water/
func maxArea(height []int) int {

	if len(height) <= 0 {
		return 0
	}

	max := func(a, b int) int {
		if a > b {
			return a
		}
		return b
	}

	min := func(a, b int) int {
		if a < b {
			return a
		}
		return b
	}

	left, right, area := 0, len(height)-1, 0
	for left < right {
		area = max(area, (right-left)*min(height[left], height[right]))
		if height[left] < height[right] {
			left++
		} else {
			right--
		}
	}

	return area
}
