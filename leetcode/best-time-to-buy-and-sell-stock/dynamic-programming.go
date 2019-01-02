func maxProfit(prices []int) int {
	ans := 0
	if nil == prices || len(prices) < 2 { return ans }

	curMin := prices[0]
	for i := 1; i < len(prices); i++ {
		if prices[i] - curMin > ans {
			ans = prices[i] - curMin
		}
		if prices[i] < curMin {
			curMin = prices[i]
		}
	}

	return ans
}
