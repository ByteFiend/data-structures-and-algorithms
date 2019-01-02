func dfs(n, row, clm, leftDown, rightDown uint, p_ans *int){
	if n == 0 { return }
	if row == uint(n) {
		(*p_ans)++
		return
	}

	choices := ((^(clm | leftDown | rightDown)) & ((1 << n) - 1))
	for ; 0 != choices; {
		pos := (choices & -choices)
		dfs(n, row + 1, clm | pos, (leftDown | pos) << 1, (rightDown | pos) >> 1, p_ans)
		choices &= (choices - 1)
	}
}

func totalNQueens(n int) int {
	ans := 0
	if n <= 0 { return ans }

	dfs(uint(n), 0, 0, 0, 0, &ans)
	return ans
}
