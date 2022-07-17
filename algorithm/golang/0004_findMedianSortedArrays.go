package golang

import "sort"

// https://leetcode.com/problems/median-of-two-sorted-arrays/

/**
Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

*/

func FindMedianSortedArrays(nums1 []int, nums2 []int) float64 {

	length := len(nums1) + len(nums2)

	// 求中位数 idx 位置
	var medIdx []int
	med := float64(length) / 2
	if int64(med*10)%10 > 0 {
		medIdx = append(medIdx, int(med))
	} else {
		medIdx = append(medIdx, int(med-1), int(med))
	}

	nums1 = append(nums1, nums2...)
	sort.Ints(nums1)

	if len(medIdx) > 1 {
		return float64(nums1[medIdx[0]]+nums1[medIdx[1]]) / 2.0
	}

	return float64(nums1[medIdx[0]])
}
