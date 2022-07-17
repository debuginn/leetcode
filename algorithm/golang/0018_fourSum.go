package golang

import (
	"sort"
)

// fourSum .
// https://leetcode.cn/problems/4sum/
func fourSum(nums []int, target int) [][]int {

	var resp [][]int

	// sort
	sort.Ints(nums)

	for i := 0; i < len(nums); i++ {

		// 去除重复
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}

		for j := i + 1; j < len(nums); j++ {

			// 去除重复
			if j > i+1 && nums[j] == nums[j-1] {
				continue
			}

			// 双指针
			left, right := j+1, len(nums)-1

			for left < right {

				if nums[i]+nums[j]+nums[left]+nums[right] == target {

					resp = append(resp, []int{nums[i], nums[j], nums[left], nums[right]})

					// 去除 left 重复值
					for left < right && nums[left] == nums[left+1] {
						left++
					}
					// 去除 right 重复值
					for left < right && nums[right] == nums[right-1] {
						right--
					}

					left++
					right--
				} else if nums[i]+nums[j]+nums[left]+nums[right] > target {
					right--
				} else if nums[i]+nums[j]+nums[left]+nums[right] < target {
					left++
				}
			}
		}

	}

	return resp
}
