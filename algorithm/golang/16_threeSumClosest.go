package golang

import "sort"

func threeSumClosest(nums []int, target int) int {

	// sort
	sort.Ints(nums)

	res := nums[0] + nums[1] + nums[len(nums)-1]

	for i := 0; i < len(nums); i++ {

		// 双指针
		left, right := i+1, len(nums)-1

		for left < right {
			sum := nums[i] + nums[left] + nums[right]

			if sum > target {
				right--
			} else {
				left++
			}

			if abs(sum-target) < abs(res-target) {
				res = sum
			}

		}

	}

	return res
}
