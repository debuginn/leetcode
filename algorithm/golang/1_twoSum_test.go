package golang

import (
	"reflect"
	"testing"
)

func TestTwoSum(t *testing.T) {

	tests := []struct {
		name   string
		nums   []int
		target int
		want   []int
	}{
		{
			name:   "case 1",
			nums:   []int{2, 7, 11, 15},
			target: 9,
			want:   []int{0, 1},
		},
		{
			name:   "case 2",
			nums:   []int{3, 2, 4},
			target: 6,
			want:   []int{1, 2},
		},
		{
			name:   "case 3",
			nums:   []int{3, 3},
			target: 6,
			want:   []int{0, 1},
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {

			result := TwoSum(tt.nums, tt.target)

			if reflect.DeepEqual(result, tt.want) {
				t.Logf("test pass")
			} else {
				t.Fatalf("test not pass, result:%v", result)
			}
		})
	}

}

func TestTwoSumHashTable(t *testing.T) {

	tests := []struct {
		name   string
		nums   []int
		target int
		want   []int
	}{
		{
			name:   "case 1",
			nums:   []int{2, 7, 11, 15},
			target: 9,
			want:   []int{0, 1},
		},
		{
			name:   "case 2",
			nums:   []int{3, 2, 4},
			target: 6,
			want:   []int{1, 2},
		},
		{
			name:   "case 3",
			nums:   []int{3, 3},
			target: 6,
			want:   []int{0, 1},
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {

			result := TwoSumHashTable(tt.nums, tt.target)

			if reflect.DeepEqual(result, tt.want) {
				t.Logf("test pass")
			} else {
				t.Fatalf("test not pass, result:%v", result)
			}
		})
	}

}
