/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func middleNode(head *ListNode) *ListNode {
	if nil == head || nil == head.Next {
		return head
	}

	oneStep, twoStep := head, head.Next
	for ; nil != twoStep && nil != twoStep.Next; {
		twoStep = twoStep.Next.Next
		oneStep = oneStep.Next
	}

	return oneStep
}

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

func reorderList(head *ListNode)  {
	if nil == head || nil == head.Next {
		return
	}

	middle := middleNode(head)
	rightHead := reverseList(middle.Next, nil)
	middle.Next = nil

	dummyNode := &ListNode{0, nil}
	dummyNode.Next = head
	tail := dummyNode

	for ; nil != head && nil != rightHead; {
		tail.Next, tail, head = head, head, head.Next
		tail.Next, tail, rightHead = rightHead, rightHead, rightHead.Next
	}

	if nil != head {
		tail.Next = head
	}
}
