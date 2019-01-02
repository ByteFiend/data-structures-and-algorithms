/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSame(s, t *TreeNode) bool {
	if nil == s {
		return nil == t
	} else if nil == t {
		return false
	}

	if s == t { return true }

	if s.Val != t.Val { return false }

	return isSame(s.Left, t.Left) && isSame(s.Right, t.Right)
}

func isSubtree(s *TreeNode, t *TreeNode) bool {
	if nil == s {
		return nil == t
	} else if nil == t {
		return false
	}

	if isSame(s, t) { return true }

	return isSubtree(s.Left, t) || isSubtree(s.Right, t)
}
