# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        min_index=-1
        min_num=10000
        for i in range(len(lists)):
            cur_list=lists[i]
            if cur_list and cur_list.val<min_num:
                min_index=i
                min_num=cur_list.val
            
        if min_num==10000:
            return None
        newHead=lists[min_index]
        lists[min_index]=lists[min_index].next
        cur_node=newHead

        while True:
            min_index=-1
            min_num=10000
            for i in range(len(lists)):
                cur_list=lists[i]
                if cur_list and cur_list.val<min_num:
                    min_index=i
                    min_num=cur_list.val
            
            if min_num==10000:
                return newHead
            cur_node.next=lists[min_index]
            cur_node=cur_node.next
            lists[min_index]=lists[min_index].next