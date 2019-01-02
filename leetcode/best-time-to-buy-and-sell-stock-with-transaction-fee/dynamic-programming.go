func max(a, b int) int {
	if a < b {
		return b
	} else {
		return a
	}
}

func maxProfit(prices []int, fee int) int {
	if nil == prices || len(prices) <= 1 { return 0 }

	haveStock, noStock := -prices[0], 0
	for i := 1; i < len(prices); i++ {
		haveStock, noStock = max(haveStock, noStock - prices[i]), max(noStock, haveStock + prices[i] - fee)
	}

	return noStock
}
