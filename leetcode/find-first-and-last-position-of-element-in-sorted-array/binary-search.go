func findFirstPosition(nums []int, target int) int {
	if nil == nums || 0 == len(nums) { return -1 }
	if 1 == len(nums) {
		if nums[0] != target {
			return -1
		} else {
			return 0
		}
	}

	left, right := 0, len(nums) - 1
	for ; left <= right; {
		mid := left + ((right - left) >> 1)
		if nums[mid] > target {
			right = mid - 1
		} else if nums[mid] < target {
			left = mid + 1
		} else if 0 == mid || nums[mid - 1] != target {
			return mid
		} else {
			right = mid - 1
		}
	}

	return -1
}

func findLastPosition(nums []int, target int) int {
	if nil == nums || 0 == len(nums) { return -1 }
	if 1 == len(nums) {
		if nums[0] != target {
			return -1
		} else {
			return 0
		}
	}

	left, right := 0, len(nums) - 1
	for ; left <= right; {
		mid := left + ((right - left) >> 1)
		if nums[mid] > target {
			right = mid - 1
		} else if nums[mid] < target {
			left = mid + 1
		} else if len(nums) - 1 == mid || nums[mid + 1] != target {
			return mid
		} else {
			left = mid + 1
		}
	}

	return -1
}

func searchRange(nums []int, target int) []int {
	ans := make([]int, 2)
	ans[0], ans[1] = -1, -1

	if nil == nums || 0 == len(nums) { return ans }
	if 1 == len(nums) {
		if nums[0] != target {
			return ans
		} else {
			return make([]int, 2)
		}
	}

	ans[0], ans[1] = findFirstPosition(nums, target), findLastPosition(nums, target)
	return ans
}
