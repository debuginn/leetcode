package golang

// https://leetcode.com/problems/add-two-numbers/

// ListNode
//Definition for singly-linked list.
//* type ListNode struct {
//*     Val int
//*     Next *ListNode
//* }
type ListNode struct {
	Val  int
	Next *ListNode
}

func AddTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {

	dummy, sum := new(ListNode), 0

	for cur := dummy; l1 != nil || l2 != nil || sum != 0; cur = cur.Next {

		if l1 != nil {
			sum += l1.Val
			l1 = l1.Next
		}

		if l2 != nil {
			sum += l2.Val
			l2 = l2.Next
		}

		// 计算对应位数相加对 10 取余数
		cur.Next = &ListNode{Val: sum % 10}
		// 计算进位数
		sum /= 10
	}

	return dummy.Next
}
