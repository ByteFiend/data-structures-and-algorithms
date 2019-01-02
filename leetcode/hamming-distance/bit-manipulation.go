func hammingDistance(x int, y int) int {
	tmp := (x ^ y)

	cnt := 0
	for ; 0 != tmp; {
		tmp &= (tmp - 1)
		cnt++
	}

	return cnt
}
