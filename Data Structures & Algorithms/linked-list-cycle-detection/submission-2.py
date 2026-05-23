# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if head is None:
            return False
        if head.next is None:
            return False

        slow=head
        fast=head.next
        while slow!=fast:
            slow=slow.next
            if not fast.next:
                return False
            fast=fast.next.next
            if not fast:
                return False
        
        return True