package leetcode

func majorityElement(nums []int) int {
	if nil == nums || 0 == len(nums) { panic("Invalid input") }
	if 1 == len(nums) { return nums[0] }

	var (
		ans int
		cnt int = 0
	)

	for i := 0; i < len(nums); i++ {
		if 0 == cnt {
			ans = nums[i]
			cnt++

		} else if nums[i] == ans {
			cnt++

		} else {
			cnt--
		}
	}

	cnt = 0
	for i := 0; i < len(nums); i++ {
		if ans == nums[i] { cnt++ }
	}

	if cnt <= (len(nums) >> 1) { panic("Invalid input") }

	return ans
}
