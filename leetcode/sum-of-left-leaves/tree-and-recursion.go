/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func helper(root *TreeNode, isLeft bool, sum int) int {
	if nil == root { return sum }

	if nil == root.Left && nil == root.Right && isLeft {
		sum += root.Val
	} else {
		sum = helper(root.Left, true, sum)
		sum = helper(root.Right, false, sum)
	}

	return sum
}

func sumOfLeftLeaves(root *TreeNode) int {
	if nil == root { return 0 }

	return helper(root, false, 0)
}