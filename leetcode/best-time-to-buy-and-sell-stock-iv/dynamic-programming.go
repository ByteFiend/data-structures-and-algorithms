const INT_MAX = int(^uint(0) >> 1)
const INT_MIN = ^INT_MAX

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func max(a, b int) int {
	if a < b {
		return b
	} else {
		return a
	}
}

func maxProfitNoTimesLimit(prices []int) int {
	ans := 0
	for i := 1; i < len(prices); i++ {
		if prices[i] > prices[i - 1] { ans += (prices[i] - prices[i - 1]) }
	}

	return ans
}

func maxProfit(k int, prices []int) int {
	if k <= 0 || nil == prices || len(prices) <= 1 { return 0 }
	if k >= (len(prices) >> 1) { return maxProfitNoTimesLimit(prices) }

	holdStock, noStock := make([]int, k + 1), make([]int, k + 1)
	for i := 0; i <= k; i++ { holdStock[i] = INT_MIN }

	for i, p := range prices {
		for j := 1; j <= min(i + 1, k); j++ {
			holdStock[j] = max(holdStock[j], noStock[j - 1] - p)
			noStock[j] = max(noStock[j], holdStock[j] + p)
		}
	}

	return noStock[k]
}
