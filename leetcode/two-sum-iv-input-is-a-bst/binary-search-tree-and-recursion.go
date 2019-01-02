/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func helper(cur *TreeNode, root *TreeNode, k int) bool {
	if nil == cur || nil == root {
		return false
	}

	if cur.Val * 2 != k && find(root, k - cur.Val) { return true }

	return helper(cur.Left, root, k) || helper(cur.Right, root, k)
}

func find(root *TreeNode, k int) bool {
	if nil == root {
		return false
	}

	if root.Val == k {
		return true
	} else if root.Val > k {
		return find(root.Left, k)
	} else {
		return find(root.Right, k)
	}
}

func findTarget(root *TreeNode, k int) bool {
	if nil == root {
		return false
	}

	return helper(root, root, k)
}