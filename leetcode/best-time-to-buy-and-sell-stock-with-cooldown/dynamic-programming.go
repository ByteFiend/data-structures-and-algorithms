const INT_MAX = int(^uint(0) >> 1)
const INT_MIN = ^INT_MAX

func max(a, b int) int {
	if a < b {
		return b
	} else {
		return a
	}
}

func maxProfit(prices []int) int {
	if nil == prices || len(prices) <= 1 { return 0 }

	haveStock, noStockButBlocked, noStockUnblocked := INT_MIN, 0, 0
	for _, p := range prices {
		haveStock, noStockUnblocked, noStockButBlocked = max(haveStock, noStockUnblocked - p), max(noStockUnblocked, noStockButBlocked), haveStock + p
	}

	return max(noStockButBlocked, noStockUnblocked)
}
