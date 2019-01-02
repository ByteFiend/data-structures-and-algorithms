func dfs(leftRemain, rightRemain int, ans []string, sequence string) []string {
	if 0 == leftRemain && 0 == rightRemain {
		ans = append(ans, sequence)
	}

	if leftRemain > 0 {
		ans = dfs(leftRemain - 1, rightRemain, ans, sequence + "(")
	}

	if rightRemain > leftRemain && rightRemain > 0 {
		ans = dfs(leftRemain, rightRemain - 1, ans, sequence + ")")
	}

	return ans
}

func generateParenthesis(n int) []string {
	ans := make([]string, 0)
	return dfs(n, n, ans, "")
}
