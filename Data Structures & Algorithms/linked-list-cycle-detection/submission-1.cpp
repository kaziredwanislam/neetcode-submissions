/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
       ListNode*  sNode=head;
       ListNode* fNode=head;
       while(sNode!=nullptr && sNode->next!=nullptr) {
            fNode=fNode->next;
            sNode=sNode->next->next;
            if(fNode==sNode)return true;
       }
       return false;
    }
};
