package golang

// https://leetcode.com/problems/two-sum/

// TwoSum violence
func TwoSum(nums []int, target int) []int {

	for i := 0; i < len(nums); i++ {
		for j := i + 1; j < len(nums); j++ {
			if nums[i]+nums[j] == target {
				return []int{i, j}
			}
		}
	}
	return []int{0, 0}
}

// TwoSumHashTable
func TwoSumHashTable(nums []int, target int) []int {

	hashTable := make(map[int]int, len(nums))

	for idx, val := range nums {
		if hv, ok := hashTable[target-val]; ok {
			return []int{hv, idx}
		}

		hashTable[val] = idx
	}
	return []int{}
}
