/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func trimBST(root *TreeNode, L int, R int) *TreeNode {
	if nil == root {
		return nil
	}

	left, right := trimBST(root.Left, L, R), trimBST(root.Right, L, R)
	if root.Val > R {
		return left
	} else if root.Val < L {
		return right
	} else {
		root.Left, root.Right = left, right
		return root
	}
}