/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func buildTree(inorder []int, postorder []int) *TreeNode {
	if nil == inorder || nil == postorder || 0 == len(inorder) || len(inorder) != len(postorder) { return nil }

	rootIdxInPost := len(postorder) - 1
	root := &TreeNode{postorder[rootIdxInPost], nil, nil}

	if 1 == len(postorder) { return root }

	idx := 0
	for ; idx < len(inorder); idx++ {
		if inorder[idx] == postorder[rootIdxInPost] { break }
	}

	leftSize := idx

	root.Left = buildTree(inorder[ : leftSize], postorder[ : leftSize])
	root.Right = buildTree(inorder[leftSize + 1 : ], postorder[leftSize : rootIdxInPost])

	return root
}
