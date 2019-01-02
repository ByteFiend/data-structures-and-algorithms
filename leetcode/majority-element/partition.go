package leetcode

import (
	"math/rand"
	"time"
)

func partition(nums []int, left, right int) int {
	if nil == nums || 0 == len(nums) || left > right { panic("Invalid input") }
	if left == right { return left }

	pivotIdx := left + rand.New(rand.NewSource(time.Now().UnixNano())).Intn(right - left + 1)
	nums[pivotIdx], nums[right] = nums[right], nums[pivotIdx]
	pivot := nums[right]

	pivotIdx = left
	for idx := left; idx < right; idx++ {
		if nums[idx] < pivot {
			nums[idx], nums[pivotIdx] = nums[pivotIdx], nums[idx]
			pivotIdx++
		}
	}

	nums[pivotIdx], nums[right] = nums[right], nums[pivotIdx]
	return pivotIdx
}

func majorityElementPartition(nums []int) int {
	if nil == nums || 0 == len(nums) { panic("Invalid input") }
	if 1 == len(nums) { return nums[0] }

	var pivotIdx int
	for begin, end := 0, len(nums); begin < end; {
		pivotIdx = partition(nums, begin, end - 1)
		if pivotIdx == (len(nums) >> 1) {
			break

		} else if pivotIdx < (len(nums) >> 1) {
			begin = pivotIdx + 1

		} else {
			end = pivotIdx
		}
	}

	cnt := 0
	for i := 0; i < len(nums); i++ {
		if nums[pivotIdx] == nums[i] { cnt++ }
	}

	if cnt <= (len(nums) >> 1) { panic("Invalid input") }

	return nums[pivotIdx]
}
