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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==nullptr && n==1)return nullptr;
        //if(n==1)return head->next;

        ListNode* temp=head;
        int size=0;
        while(temp!=nullptr)
        {
            size++;
            temp=temp->next;
        }
        int deletedIndex=size-n+1;
        if(deletedIndex==1)return head->next;
        //cout<<deletedIndex<<" "<<size<<endl;
        ListNode* curNode=head;
        for(int i=1;i<=deletedIndex;i++)
        {
            if(i==deletedIndex-1)
            {
                curNode->next=curNode->next->next;
            }
            else
            {
                curNode=curNode->next;
            }
        }
        return head;
    }
};
