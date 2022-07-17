package golang

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {

	dummy := &ListNode{0, head}

	first, second := head, dummy

	for i := 0; i < n; i++ {
		first = first.Next
	}

	for first != nil {
		second = second.Next
		first = first.Next
	}

	second.Next = second.Next.Next
	return dummy.Next
}
