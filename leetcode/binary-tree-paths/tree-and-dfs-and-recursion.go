/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func helper(root *TreeNode, paths []string, aPath []int) []string {
	if nil == root { return paths }

	aPath = append(aPath, root.Val)

	if nil == root.Left && nil == root.Right {
		var buf bytes.Buffer
		buf.WriteString(strconv.Itoa(aPath[0]))
		for i := 1; i < len(aPath); i++ {
			buf.WriteString("->")
			buf.WriteString(strconv.Itoa(aPath[i]))
		}
		paths = append(paths, buf.String())
	}

	paths = helper(root.Left, paths, aPath)
	paths = helper(root.Right, paths, aPath)

	return paths
}

func binaryTreePaths(root *TreeNode) []string {
	paths := make([]string, 0)
	if nil == root { return paths }

	aPath := make([]int, 0)
	return helper(root, paths, aPath)
}