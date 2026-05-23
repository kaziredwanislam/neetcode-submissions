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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr)return head;
        if(head->next==nullptr)return head;
        if(head->next->next==nullptr) {
            ListNode* newHead=head->next;
            newHead->next=head;
            head->next=nullptr;
            return newHead; 
        }

        ListNode* curNode=head->next->next;
        ListNode* prevNode=head->next;
        ListNode* prevprevNode=head;
        
        //prevprevNode->next=nullptr;
        
        while(curNode!=nullptr) {
            prevNode->next=prevprevNode;
            prevprevNode=prevNode;
            prevNode=curNode;
            curNode=curNode->next;
        }
        prevNode->next=prevprevNode;
        head->next=nullptr;
        return prevNode;
    }

    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* first=head;
        ListNode* second=reverseList(slow->next);
        slow->next=nullptr;

        while(second) {
            ListNode* temp1=first->next;
            ListNode* temp2=second->next;

            first->next=second;
            second->next=temp1;

            first=temp1;
            second=temp2;
        }
    }
};
