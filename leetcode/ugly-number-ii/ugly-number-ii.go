func min(a, b, c int) int {
	if a < b {
		if a < c {
			return a
		} else {
			return c
		}
	} else {
		if b < c {
			return b
		} else {
			return c
		}
	}
}

func nthUglyNumber(n int) int {
	if n <= 0 { panic("Error input") }
	if 1 == n { return 1 }

	buf := make([]int, n)
	buf[0] = 1

	curIdx, idx2, idx3, idx5 := 0, 0, 0, 0
	for ; curIdx < n - 1; {
		num2, num3, num5 := buf[idx2] * 2, buf[idx3] * 3, buf[idx5] * 5
		minNum := min(num2, num3, num5)
		if num2 == minNum {
			idx2++
		} else if num3 == minNum {
			idx3++
		} else {
			idx5++
		}

		if minNum == buf[curIdx] { continue }
		curIdx++
		buf[curIdx] = minNum
	}

	return buf[n - 1]
}
