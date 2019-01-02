func mySqrt(x int) int {
	if x < 0 { panic("Invalid input") }
	if 0 == x || 1 == x { return x }

	var mid int
	left, right := 1, x - 1
	for ; left <= right; {
		mid = ((right - left) >> 1) + left
		if mid == x / mid {
			return mid
		} else if mid < x / mid {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}

	return left - 1
}
