/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func buildTree(preorder []int, inorder []int) *TreeNode {
	if nil == preorder || nil == inorder || len(preorder) != len(inorder) || 0 == len(preorder) { return nil }

	root := &TreeNode{preorder[0], nil, nil}

	if 1 == len(preorder) { return root }

	idx := 0
	for ; idx < len(inorder); idx++ {
		if preorder[0] == inorder[idx] { break }
	}

	leftSize := idx

	root.Left = buildTree(preorder[1 : 1 + leftSize], inorder[ : leftSize])
	root.Right = buildTree(preorder[1 + leftSize : ], inorder[leftSize + 1 : ])

	return root
}
