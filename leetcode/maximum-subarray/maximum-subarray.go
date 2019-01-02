const INT_MAX = int(^uint(0) >> 1)
const INT_MIN = ^INT_MAX

func maxSubArray(nums []int) int {
	if nil == nums || 0 == len(nums) { return 0 }
	if 1 == len(nums) { return nums[0] }

	sum, ans := 0, INT_MIN
	for _, v := range nums {
		if v >= 0 {
			if sum >= 0 {
				sum += v
			} else {
				sum = v
			}
		} else {
			if sum + v >= 0 {
				sum += v
			} else {
				sum = v
			}
		}

		if sum > ans { ans = sum }
	}

	return ans
}
