func helper(nums []int) int {
	if nil == nums || 0 == len(nums) { panic("invalid input") }

	ans := 0
	for _, v := range nums {
		ans ^= v
	}
	return ans
}

func singleNumber(nums []int) []int {
	ans := make([]int, 0)
	if nil == nums || 0 == len(nums) { return ans }
	if 1 == len(nums) { return append(ans, nums[0]) }
	if 2 == len(nums) {
		if nums[0] == nums[1] {
			return ans
		} else {
			return nums
		}
	}

	twoNumsXor := helper(nums)
	oneBit := (twoNumsXor & (- twoNumsXor))

	ans = append(ans, 0)
	ans = append(ans, 0)
	for _, v := range nums {
		if 0 == (oneBit & v) {
			ans[0] ^= v
		} else {
			ans[1] ^= v
		}
	}

	return ans
}
