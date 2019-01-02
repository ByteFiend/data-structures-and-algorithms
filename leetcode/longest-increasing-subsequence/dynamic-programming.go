func lengthOfLIS(nums []int) int {
	if nil == nums || 0 == len(nums) { return 0 }
	if 1 == len(nums) { return 1 }

	ans := 1
	dp := make([]int, len(nums))
	for i := 0; i < len(nums); i++ {
		dp[i] = 1
		for j := 0; j < i; j++ {
			if nums[j] < nums[i] && dp[j] + 1 > dp[i] {
				dp[i] = dp[j] + 1
				if dp[i] > ans {
					ans = dp[i]
				}
			}
		}
	}

	return ans
}
