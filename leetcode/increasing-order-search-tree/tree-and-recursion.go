/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func helper(root *TreeNode) (*TreeNode, *TreeNode) {
	if nil == root || nil == root.Left && nil == root.Right { return root, root }

	var head, tail, tmp *TreeNode

	if nil == root.Left {
		head = root
	} else {
		head, tmp = helper(root.Left)
		tmp.Right = root
		root.Left = nil
	}

	if nil == root.Right {
		tail = root
	} else {
		tmp, tail = helper(root.Right)
		root.Right = tmp
		tmp.Left = nil
	}

	return head, tail
}

func increasingBST(root *TreeNode) *TreeNode {
	if nil == root || nil == root.Left && nil == root.Right { return root }

	head, _ := helper(root)
	return head
}