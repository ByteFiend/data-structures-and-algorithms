/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func reverseList(head, stopAndAppend *ListNode) *ListNode {
	if nil == head || nil == head.Next {
		return head
	}

	newHead := stopAndAppend
	for ; head != stopAndAppend; {
		head.Next, newHead, head = newHead, head, head.Next
	}

	return newHead
}

func reverseKGroup(head *ListNode, k int) *ListNode {
	if k <= 0 || nil == head { return nil }
	if nil == head.Next || 1 == k { return head }

	var (
		todoHead, todoTail *ListNode
		cnt int
	)

	dummyNode := &ListNode{0, head}

	for okTail := dummyNode; nil != okTail.Next; {
		todoHead = okTail.Next
		todoTail = todoHead

		cnt = 1
		for ; cnt < k && nil != todoTail.Next; {
			todoTail = todoTail.Next
			cnt++
		}
		if cnt < k { break }

		okTail.Next, okTail = reverseList(todoHead, todoTail.Next), todoHead
	}

	return dummyNode.Next
}
