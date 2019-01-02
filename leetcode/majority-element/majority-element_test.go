package leetcode

import "testing"

func TestMajorityElement(t *testing.T){
	if 3 != majorityElement([]int{3, 2, 3}) { panic("ERROR!") }
	if 2 != majorityElement([]int{2, 2, 1, 1, 1, 2, 2}) { panic("ERROR!") }
	if 2 != majorityElement([]int{2, 2}) { panic("ERROR!") }
	if 3 != majorityElement([]int{3}) { panic("ERROR!") }
	if 3 != majorityElement([]int{3, 3}) { panic("ERROR!") }
	if 3 != majorityElement([]int{3, 3, 3}) { panic("ERROR!") }
	if 3 != majorityElement([]int{2, 3, 3}) { panic("ERROR!") }
	if 3 != majorityElement([]int{3, 2, 3}) { panic("ERROR!") }
	if 3 != majorityElement([]int{3, 3, 2}) { panic("ERROR!") }
	if 3 != majorityElement([]int{3, 3, 3, 3}) { panic("ERROR!") }
	if 3 != majorityElement([]int{2, 3, 3, 3}) { panic("ERROR!") }
	if 3 != majorityElement([]int{3, 2, 3, 3}) { panic("ERROR!") }
	if 3 != majorityElement([]int{3, 3, 2, 3}) { panic("ERROR!") }
	if 3 != majorityElement([]int{3, 3, 3, 2}) { panic("ERROR!") }
	if 6 != majorityElement([]int{6, 6, 6, 7, 7}) { panic("ERROR!") }
}

func TestMajorityElementPartition(t *testing.T){
	if 3 != majorityElementPartition([]int{3, 2, 3}) { panic("ERROR!") }
	if 2 != majorityElementPartition([]int{2, 2, 1, 1, 1, 2, 2}) { panic("ERROR!") }
	if 2 != majorityElementPartition([]int{2, 2}) { panic("ERROR!") }
	if 3 != majorityElementPartition([]int{3}) { panic("ERROR!") }
	if 3 != majorityElementPartition([]int{3, 3}) { panic("ERROR!") }
	if 3 != majorityElementPartition([]int{3, 3, 3}) { panic("ERROR!") }
	if 3 != majorityElementPartition([]int{2, 3, 3}) { panic("ERROR!") }
	if 3 != majorityElementPartition([]int{3, 2, 3}) { panic("ERROR!") }
	if 3 != majorityElementPartition([]int{3, 3, 2}) { panic("ERROR!") }
	if 3 != majorityElementPartition([]int{3, 3, 3, 3}) { panic("ERROR!") }
	if 3 != majorityElementPartition([]int{2, 3, 3, 3}) { panic("ERROR!") }
	if 3 != majorityElementPartition([]int{3, 2, 3, 3}) { panic("ERROR!") }
	if 3 != majorityElementPartition([]int{3, 3, 2, 3}) { panic("ERROR!") }
	if 3 != majorityElementPartition([]int{3, 3, 3, 2}) { panic("ERROR!") }
	if 6 != majorityElementPartition([]int{6, 6, 6, 7, 7}) { panic("ERROR!") }
}
