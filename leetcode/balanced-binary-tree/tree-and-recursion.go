/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isBalanced(root *TreeNode) bool {
	isOk, _ := helper(root)
	return isOk
}

func helper(root *TreeNode) (bool, int) {
	if nil == root { return true, 0 }
	if nil == root.Left && nil == root.Right { return true, 1 }

	isLeftBalanced, leftDepth := helper(root.Left)
	isRightBalanced, rightDepth := helper(root.Right)

	if false == isLeftBalanced || false == isRightBalanced { return false, max(leftDepth, rightDepth) + 1 }
	if -1 <= leftDepth - rightDepth && leftDepth - rightDepth <= 1 { return true, max(leftDepth, rightDepth) + 1 }

	return false, max(leftDepth, rightDepth) + 1
}

func max(a, b int) int {
	if a < b {
		return b
	} else {
		return a
	}
}
