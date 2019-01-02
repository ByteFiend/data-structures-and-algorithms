/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	if nil == head || n <= 0 { return nil }

	dummyNode := &ListNode{0, head}

	goAhead := dummyNode
	cnt := 0
	for ; cnt <= n && nil != goAhead; cnt++ { goAhead = goAhead.Next }
	if cnt <= n { return nil }

	prev := dummyNode
	for ; nil != goAhead; { prev, goAhead = prev.Next, goAhead.Next }

	prev.Next = prev.Next.Next
	return dummyNode.Next
}
