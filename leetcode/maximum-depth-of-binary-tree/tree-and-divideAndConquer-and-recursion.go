package leetcode

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxDepth(root *TreeNode) int {
	if nil == root { return 0 }
	if nil == root.Left { return maxDepth(root.Right) + 1 }
	if nil == root.Right { return maxDepth(root.Left) + 1 }

	left, right := maxDepth(root.Left), maxDepth(root.Right)
	if left > right {
		return left + 1
	} else {
		return right + 1
	}
}
