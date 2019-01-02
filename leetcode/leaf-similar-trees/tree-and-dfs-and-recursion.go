/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func dfs(root *TreeNode, leaves []int) []int {
	if nil == root { return leaves }

	if nil == root.Left && nil == root.Right {
		leaves = append(leaves, root.Val)
		return leaves
	}

	leaves = dfs(root.Left, leaves)
	leaves = dfs(root.Right, leaves)

	return leaves
}

func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
	if root1 == root2 { return true }
	if nil == root1 || nil == root2 { return false }

	leaves1, leaves2 := make([]int, 0), make([]int, 0)
	leaves1 = dfs(root1, leaves1)
	leaves2 = dfs(root2, leaves2)

	if len(leaves1) != len(leaves2) { return false }

	for i := 0; i < len(leaves1); i++ {
		if leaves1[i] != leaves2[i] { return false }
	}
	return true
}