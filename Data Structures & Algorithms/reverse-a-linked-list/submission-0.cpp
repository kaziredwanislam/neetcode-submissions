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
        //cout<<head->val<<endl;
        if(head==nullptr)return nullptr;
        vector<int>nums;
        ListNode* curNode=head;
        nums.push_back(head->val);
        //cout<<head->val<<endl;
        curNode=curNode->next;
        while(curNode!=nullptr)
        {
           
            nums.push_back(curNode->val);
            //cout<<curNode->val<<endl;
            curNode=curNode->next;

        }

        ListNode* newNode=new ListNode(nums.back());
        //newNode->val=nums[nums.size()-1];
        ListNode* newHead=newNode;
        for(int i=nums.size()-2;i>=0;i--)
        {
            ListNode* temp=new ListNode(nums[i]);
            newNode->next=temp;
            newNode=newNode->next;
        }
        return newHead;
    }
};
