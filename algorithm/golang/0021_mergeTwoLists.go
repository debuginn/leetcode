package golang

type ListNode1 struct {
	Val  int
	Next *ListNode1
}

// mergeTwoLists .
func mergeTwoLists(list1 *ListNode1, list2 *ListNode1) *ListNode1 {

	resp := &ListNode1{}
	prev := resp

	for ; list1 != nil && list2 != nil; prev = prev.Next {
		if list1.Val <= list2.Val {
			prev.Next = list1
			list1 = list1.Next
		} else if list1.Val >= list2.Val {
			prev.Next = list2
			list2 = list2.Next
		}
	}

	if list1 != nil {
		prev.Next = list1
	}
	if list2 != nil {
		prev.Next = list2
	}

	return resp.Next
}
