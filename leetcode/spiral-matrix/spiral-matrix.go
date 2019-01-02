func spiralOrder(matrix [][]int) []int {
	ans := make([]int, 0)
	if nil == matrix || 0 == len(matrix) { return ans }

	minRow, maxRow, minClm, maxClm := 0, len(matrix) - 1, 0, len(matrix[0]) - 1

	var curRow, curClm int
	for ; minRow <= maxRow && minClm <= maxClm; {
		if minRow > maxRow || minClm > maxClm { continue }

		curRow = minRow
		for i := minClm; i <= maxClm; i++ {
			ans = append(ans, matrix[curRow][i])
		}
		minRow++

		if minRow > maxRow || minClm > maxClm { continue }

		curClm = maxClm
		for i := minRow; i <= maxRow; i++ {
			ans = append(ans, matrix[i][curClm])
		}
		maxClm--

		if minRow > maxRow || minClm > maxClm { continue }

		curRow = maxRow
		for i := maxClm; i >= minClm; i-- {
			ans = append(ans, matrix[curRow][i])
		}
		maxRow--

		if minRow > maxRow || minClm > maxClm { continue }

		curClm = minClm
		for i := maxRow; i >= minRow; i-- {
			ans = append(ans, matrix[i][curClm])
		}
		minClm++
	}

	return ans
}
