func findMin(nums []int) int {
	if nil == nums || 0 == len(nums) { panic("invalid input") }
	if 1 == len(nums) || nums[0] < nums[len(nums) - 1] { return nums[0] }

	if nums[0] > nums[len(nums) - 1] {
		left, right := 0, len(nums) - 1
		for ; left <= right; {
			mid := left + ((right - left) >> 1)
			if nums[0] <= nums[mid] {
				left = mid + 1
			} else if nums[mid - 1] > nums[mid] {
				return nums[mid]
			} else {
				right = mid - 1
			}
		}
	}

	ans := nums[0]
	for i := 1; i < len(nums); i++ {
		if nums[i] < ans { ans = nums[i] }
	}

	return ans
}
