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
       ListNode* curNode=head;
       int size=1;
       while(curNode->next!=nullptr) {
        curNode=curNode->next;
        size++;
       } 
        
        //cout<<size<<endl;
       if(size==1 && n==1)return nullptr;
       int num=size-n;
       if(num==0)return head->next;

       //int pos=num-1;
       int s=1;
       curNode=head;
       while(s!=num) {
            curNode=curNode->next;
            s++;
       }

       curNode->next=curNode->next->next;
       return head;
    }
};
