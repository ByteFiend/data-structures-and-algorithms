func climbStairs(n int) int {
	if n <= 0 { panic("invalid input") }
	if 1 == n || 2 == n { return n }

	lastLast, last := 1, 2
	for i := 3; i <= n; i++ {
		lastLast, last = last, lastLast + last
	}

	return last
}
