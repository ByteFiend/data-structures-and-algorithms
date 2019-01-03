/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
const INT_MAX = int(^uint(0) >> 1)
const INT_MIN = ^INT_MAX

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func helper(root *TreeNode, small, big int) int {
	ans := INT_MAX
	if nil == root { return ans }

	if INT_MIN != small {
		ans = min(ans, root.Val - small)
	}
	if INT_MAX != big {
		ans = min(ans, big - root.Val)
	}

	if nil == root.Left || nil == root.Right {
		if nil == root.Left && nil == root.Right {
			return ans
		} else if nil == root.Left {
			ans = min(ans, helper(root.Right, root.Val, big))
		} else {
			ans = min(ans, helper(root.Left, small, root.Val))
		}
	} else {
		ans = min(ans, helper(root.Left, small, root.Val))
		ans = min(ans, helper(root.Right, root.Val, big))
	}

	return ans
}

func minDiffInBST(root *TreeNode) int {
	if nil == root { return 0 }

	return helper(root, INT_MIN, INT_MAX)
}