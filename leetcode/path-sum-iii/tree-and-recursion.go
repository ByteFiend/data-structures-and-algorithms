/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func helper(root *TreeNode, sum int, started bool) int {
	if nil == root {
		return 0
	}

	ans := 0
	if sum == root.Val {
		ans += 1
	}

	if false == started {
		ans += (helper(root.Left, sum, started) + helper(root.Right, sum, started))
	}

	ans += (helper(root.Left, sum - root.Val, true) + helper(root.Right, sum - root.Val, true))

	return ans
}

func pathSum(root *TreeNode, sum int) int {
	if nil == root {
		return 0
	}

	return helper(root, sum, false)
}