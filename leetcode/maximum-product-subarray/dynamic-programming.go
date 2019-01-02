func max(a, b, c int) int {
	if a > b {
		if a > c {
			return a
		} else {
			return c
		}
	} else {
		if b > c {
			return b
		} else {
			return c
		}
	}
}

func min(a, b, c int) int {
	if a < b {
		if a < c {
			return a
		} else {
			return c
		}
	} else {
		if b < c {
			return b
		} else {
			return c
		}
	}
}

func maxProduct(nums []int) int {
	if nil == nums { panic("invalid input") }
	if 1 == len(nums) { return nums[0] }

	ans, curMin, curMax := nums[0], nums[0], nums[0]
	for i := 1; i < len(nums); i++ {
		curMin *= nums[i]
		curMax *= nums[i]
		curMin, curMax = min(nums[i], curMin, curMax), max(nums[i], curMin, curMax)

		if curMax > ans {
			ans = curMax
		}
	}

	return ans
}
