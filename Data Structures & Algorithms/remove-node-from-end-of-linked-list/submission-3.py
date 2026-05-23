# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if head is None:
            return head
        
        len=0
        cur_node=head
        while cur_node:
            len+=1
            cur_node=cur_node.next
        
        dest=len-n+1
        print(dest)
        if dest==1:
            return head.next

        cur_node=head
        cur_pos=0
        while cur_pos<dest-2:
            cur_pos+=1
            cur_node=cur_node.next
        
        print(cur_pos)
        cur_node.next=cur_node.next.next
        return head
            