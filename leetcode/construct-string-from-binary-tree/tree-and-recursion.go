/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func helper(buf *bytes.Buffer, t *TreeNode) {
	if nil == t {
		return
	}

	buf.WriteString(strconv.Itoa(t.Val))

	if nil != t.Left {
		buf.WriteString("(")
		helper(buf, t.Left)
		buf.WriteString(")")
	} else if nil != t.Right {
		buf.WriteString("()")
	}

	if nil != t.Right {
		buf.WriteString("(")
		helper(buf, t.Right)
		buf.WriteString(")")
	}
}

func tree2str(t *TreeNode) string {
	if nil == t { return "" }

	var buf bytes.Buffer
	helper(&buf, t)

	return buf.String()
}