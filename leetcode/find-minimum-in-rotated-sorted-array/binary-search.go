func findMin(nums []int) int {
	if nil == nums || 0 == len(nums) { panic("invalid input") }
	if 1 == len(nums) || nums[0] < nums[len(nums) - 1] { return nums[0] }

	left, right := 0, len(nums) - 1
	for ; left <= right; {
		mid := left + ((right - left) >> 1)
		if nums[0] < nums[mid] {
			left = mid + 1
		} else if 0 == mid {
			return nums[1]
		} else {
			if nums[mid - 1] > nums[mid] {
				return nums[mid]
			} else {
				right = mid - 1
			}
		}
	}

	panic("error")
	return 0
}
