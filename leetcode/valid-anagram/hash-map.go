func isAnagram(s string, t string) bool {
	if len(s) != len(t) { return false }
	if 0 == len(s) { return true }

	sCnt, tCnt := make(map[rune]int), make(map[rune]int)
	for _, c := range s {
		if _, exist := sCnt[c]; false == exist { sCnt[c] = 0 }
		sCnt[c]++
	}
	for _, c := range t {
		if _, exist := tCnt[c]; false == exist { tCnt[c] = 0 }
		tCnt[c]++
	}

	if len(sCnt) != len(tCnt) { return false }

	for c, cntS := range sCnt {
		cntT, exist := tCnt[c]
		if false == exist || cntS != cntT { return false }
	}

	return true
}
