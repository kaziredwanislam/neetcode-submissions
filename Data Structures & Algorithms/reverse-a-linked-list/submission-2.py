# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:return None
        if not head.next:return head
        if not head.next.next:
            new_head=head.next
            new_head.next=head
            head.next=None
            return new_head
        
        prev_prev=head
        prev=head.next
        cur=prev.next
        prev_prev.next=None

        while cur:
            prev.next=prev_prev
            prev_prev=prev
            prev=cur
            cur=cur.next
        prev.next=prev_prev
        return prev