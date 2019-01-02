package leetcode

import "testing"

func TestThat(t *testing.T){
	if 7 != maxProfit([]int{7,1,5,3,6,4}) { panic("ERROR!") }
	if 4 != maxProfit([]int{1, 2, 3, 4, 5}) { panic("ERROR!") }
	if 0 != maxProfit([]int{7, 6, 4, 3, 1}) { panic("ERROR!") }
}
