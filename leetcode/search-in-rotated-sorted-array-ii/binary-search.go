func search(nums []int, target int) bool {
	if nil == nums || 0 == len(nums) { return false }
	if nums[0] == target || nums[len(nums) - 1] == target {
		return true
	} else if 1 == len(nums) && nums[0] != target {
		return false
	}

	var (
		left, right = 0, len(nums) - 1
		mid int
	)

	if nums[0] < nums[len(nums) - 1] {
		for ; left <= right; {
			mid = left + ((right - left) >> 1)
			if nums[mid] == target {
				return true
			} else if nums[mid] < target {
				left = mid + 1
			} else {
				right = mid - 1
			}
		}
		return false
	}

	for i := 0; i < len(nums); i++ {
		if nums[i] == target { return true }
	}
	return false
}
