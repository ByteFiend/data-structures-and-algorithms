func firstUniqChar(s string) int {
	if 0 == len(s) { return -1 }

	times := make(map[rune]int)
	for _, c := range s {
		if _, exist := times[c]; exist {
			times[c]++
		} else {
			times[c] = 1
		}
	}

	for idx, c := range s {
		if t, exist := times[c]; exist && 1 == t { return idx }
	}

	return -1
}
