func search(nums []int, target int) int {
	if nil == nums || 0 == len(nums) { return -1 }
	if nums[0] == target {
		return 0
	} else if nums[len(nums) - 1] == target {
		return len(nums) - 1
	} else if 1 == len(nums) && nums[0] != target {
		return -1
	}

	var (
		left, right = 0, len(nums) - 1
		mid int
	)

	if nums[0] < nums[len(nums) - 1] {
		for ; left <= right; {
			mid = left + ((right - left) >> 1)
			if nums[mid] == target {
				return mid
			} else if nums[mid] < target {
				left = mid + 1
			} else {
				right = mid - 1
			}
		}
		return -1
	}

	for ; left <= right; {
		mid = left + ((right - left) >> 1)
		if nums[mid] == target {
			return mid

		} else if nums[0] < target && target < nums[mid] {
			right = mid - 1
		} else if nums[mid] < nums[0] && nums[0] < target {
			right = mid - 1
		} else if target < nums[mid] && nums[mid] < nums[0] {
			right = mid - 1

		} else if nums[0] < nums[mid] && nums[mid] < target {
			left = mid + 1
		} else if nums[mid] < target && target < nums[0] {
			left = mid + 1
		} else { // target < nums[0] < nums[mid]
			left = mid + 1
		}
	}

	return -1
}
