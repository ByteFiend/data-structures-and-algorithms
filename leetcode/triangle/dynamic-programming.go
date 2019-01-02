func minimumTotal(triangle [][]int) int {
	if nil == triangle { panic("invalid input") }

	mini := make([]int, len(triangle[len(triangle) - 1]))
	copy(mini, triangle[len(triangle) - 1])

	for i := len(triangle) - 2; i >= 0; i-- {
		for j := 0; j <= i; j++ {
			if mini[j] < mini[j + 1] {
				mini[j] = mini[j] + triangle[i][j]
			} else {
				mini[j] = mini[j + 1] + triangle[i][j]
			}
		}
	}

	return mini[0]
}
