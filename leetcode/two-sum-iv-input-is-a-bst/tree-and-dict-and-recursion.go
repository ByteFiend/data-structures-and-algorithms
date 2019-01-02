/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func makeExistDict(root *TreeNode, existDict map[int]bool) map[int]bool {
	if nil == root {
		return existDict
	}

	existDict = makeExistDict(root.Left, existDict)
	existDict[root.Val] = true
	existDict = makeExistDict(root.Right, existDict)

	return existDict
}

func helper(root *TreeNode, existDict map[int]bool, k int) bool {
	if nil == root { return false }

	if exist, _ := existDict[k - root.Val]; root.Val * 2 != k && exist { return true }

	return helper(root.Left, existDict, k) || helper(root.Right, existDict, k)
}

func findTarget(root *TreeNode, k int) bool {
	if nil == root {
		return false
	}

	existDict := make(map[int]bool)
	existDict = makeExistDict(root, existDict)

	return helper(root, existDict, k)
}