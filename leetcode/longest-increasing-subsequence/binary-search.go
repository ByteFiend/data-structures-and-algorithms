func lowerBound(nums []int, target int) int {
	if nil == nums || 0 == len(nums) { return -1 }

	left, right := 0, len(nums) - 1
	for ; left <= right; {
		mid := left + ((right - left) >> 1)
		if nums[mid] == target {
			return mid
		} else if nums[mid] < target {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}

	if left >= len(nums) {
		return -1
	} else {
		return left
	}
}

func lengthOfLIS(nums []int) int {
	if nil == nums || 0 == len(nums) { return 0 }
	if 1 == len(nums) { return 1 }

	lis := make([]int, 0)
	lis = append(lis, nums[0])
	for i := 1; i < len(nums); i++ {
		idx := lowerBound(lis, nums[i])
		if -1 == idx {
			lis = append(lis, nums[i])
		} else {
			lis[idx] = nums[i]
		}
	}

	return len(lis)
}
