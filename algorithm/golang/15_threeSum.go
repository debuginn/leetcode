package golang

import "sort"

func threeSum(nums []int) [][]int {

	var resp [][]int

	// sort
	sort.Ints(nums)

	for i := 0; i < len(nums); i++ {

		if nums[i] > 0 {
			return resp
		}
		// 排除值重复的固定位
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}

		// 双指针
		left, right := i+1, len(nums)-1

		for left < right {

			if nums[i]+nums[left]+nums[right] == 0 {

				resp = append(resp, []int{nums[i], nums[left], nums[right]})

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
			} else if nums[i]+nums[left]+nums[right] > 0 {
				right--
			} else if nums[i]+nums[left]+nums[right] < 0 {
				left++
			}
		}

	}

	return resp
}
