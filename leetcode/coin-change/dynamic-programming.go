func coinChange(coins []int, amount int) int {
	if nil == coins || 0 == len(coins) || amount < 0 { return -1 }
	if 0 == amount { return 0 }

	dp := make([]int, amount + 1)
	for i := 1; i <= amount; i++ {
		dp[i] = amount + 1
	}
	dp[0] = 0

	for i := 0; i < amount; i++ {
		for _, coin := range coins {
			if i + coin > amount { continue }
			if dp[i] + 1 < dp[i + coin] {
				dp[i + coin] = dp[i] + 1
			}
		}
	}

	if dp[amount] <= amount {
		return dp[amount]
	} else {
		return -1
	}
}
